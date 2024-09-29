#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define MAXN 100100

ll dp[MAXN][104]; //dp[i][k] => si es mayor o igual a 0, significa que es posible agarrar el segmento empezando en i, de largo k. Si es <0, no lo puedo agarrar
ll p2[2*MAXN];

//DA WA EN EL 54
void solve() {
    ll n,k; cin >> n >> k;
    ll a[n]; fr(0,n) cin >> a[i];
    ll b[n]; fr(0,n) cin >> b[i];
    if (k > n){k = n;}
    if (b[0] == 2) {
        p2[0] = a[0];
        p2[n] = a[0];
    } else {
        p2[0] = 0;
        p2[n] = 0;
    }
    fr(1,n){
        p2[i] = p2[i-1];
        if (b[i] == 2){
            p2[i]+=a[i];
        }
    }
    p2[n]+=p2[n-1];
    fr(n+1, 2*n){
        p2[i] = p2[i-1];
        if (b[i%n] == 2){
            p2[i]+=a[i%n];
        }
    }
    memset(dp, -1, sizeof(dp)); 
    ll res = 0;
    fr(0,n){
        dp[0][0] = 0;
        if (b[i] == 1){
            dp[i][1] = a[i];
        } else {
            dp[i][1] = -1;
        }
    }
    //el rango seria [i, i+largo-1]
    rep(largo,2,k+1){
        // rep(i,0,n-largo+1){
        rep(i,0,n){
            if (dp[i][largo-1]>=0){
                if (b[(i+largo-1)%n] == 2){
                    dp[i][largo] = max(dp[i][largo], dp[i][largo-1] - a[(i+largo-1)%n]);
                } else {
                    dp[i][largo] = max(dp[i][largo], dp[i][largo-1] + a[(i+largo-1)%n]);
                }
            }
            if (dp[(i+1)%n][largo-1] >= 0){
                if (b[i] == 2){
                    dp[i][largo] = max(dp[i][largo], dp[(i+1)%n][largo-1] - a[i]);
                } else {
                    dp[i][largo] = max(dp[i][largo], dp[(i+1)%n][largo-1] + a[i]);
                }
            }
            if (dp[i][largo] >= 0){
                if (i > 0){
                    res = max(res, p2[i+largo-1] - p2[i-1]);
                } else {
                    res = max(res, p2[i+largo-1]);
                }
            }   
        }
    }
    cout << res << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}