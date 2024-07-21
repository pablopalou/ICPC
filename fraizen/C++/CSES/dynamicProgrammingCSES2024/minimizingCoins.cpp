#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define inf 1000000000

void solve() {
    ll n,x; cin >> n >> x; ll a[n];
    fr(0,n) cin >> a[i];
    int dp[2][1000010];
    fr(0,2){
        rep(j,0,x+1){
            dp[i][j] = inf; 
        }
    }
    // return;
    //para la primer moneda, simplemente vamos en sus multiplos
    if (a[0] <= x){
        dp[0][a[0]] = 1;
    }
    // return;
    for(int i = a[0]+a[0]; i <= x; i+=a[0]){
        dp[0][i] = dp[0][i-a[0]] + 1;
    }
    // return;
    fr(1,n){
        if (a[i] <= x){
            dp[1][a[i]] = 1;
        }
        rep(j,0,x+1){
            dp[1][j] = min(dp[1][j], dp[0][j]);
            if (dp[0][j]!=0 && j + a[i] <= x){
                dp[1][j+a[i]] = min(dp[1][j+a[i]], dp[1][j] + 1);
            }
        }
        swap(dp[0], dp[1]);
        fr(0,x+1){
            dp[1][i] = inf;
        }
    }
    if (dp[0][x] == inf){
        cout << "-1\n"; return;
    }
    cout << dp[0][x] << '\n';
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