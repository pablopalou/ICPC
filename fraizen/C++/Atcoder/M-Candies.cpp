#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mod 1000000007

ll dp[105][100005];
ll n,k;
ll ps[105][100005];
ll a[105];

ll f(ll x, ll cant){
    ll &res = dp[x][cant];
    if (res != -1) return res;
    if (x == n && cant == 0) return 1;
    if (x == n) return 0;
    //asumo que ya tengo ps entonces seria solo hacer esa cuenta.
    res = ((ps[x+1][cant+1] - ps[x+1][max(0ll,cant-a[x])]) + mod )% mod;
    return res;
}

void solve() {
    cin >> n >> k; fr(0,n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    //podria llamar a la funcion en orden todas las veces y eso no cambiaria el orden
    //asi me queda bien el suma...
    memset(ps, 0, sizeof(ps));
    fr(0,n+1){
        rep(j,1,k+2){
            ps[n-i][j] = ps[n-i][j-1] + f(n-i,j-1); //uso el valor anterior xq en realidad estoy calculando hasta j-1 inclusive.
            if (ps[n-i][j] > mod){
                ps[n-i][j] -= mod;
            }
        }
    }
    cout << f(0,k) << "\n";
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