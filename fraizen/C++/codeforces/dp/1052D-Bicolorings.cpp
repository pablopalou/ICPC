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
#define MOD 998244353
#define MAXN 1005

ll dp[MAXN][2*MAXN][4];

void solve() {
    int n,k; cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;
    dp[0][1][3] = 1;
    dp[0][2][2] = 1;
    dp[0][2][1] = 1;
    fr(0,n-1){
        rep(comp,0,k+1){
            dp[i+1][comp][0] = (dp[i][comp][0] + dp[i+1][comp][0]) % MOD;
            dp[i+1][comp+1][1] = (dp[i][comp][0] + dp[i+1][comp+1][1]) % MOD;
            dp[i+1][comp+1][2] = (dp[i][comp][0] +dp[i+1][comp+1][2]) % MOD;
            dp[i+1][comp+1][3] = (dp[i][comp][0] +dp[i+1][comp+1][3]) % MOD;

            dp[i+1][comp][0] = (dp[i+1][comp][0] + dp[i][comp][1])%MOD;
            dp[i+1][comp][1] = (dp[i+1][comp][1] + dp[i][comp][1])%MOD;
            dp[i+1][comp+2][2]=(dp[i+1][comp+2][2] + dp[i][comp][1])%MOD;
            dp[i+1][comp][3] = (dp[i+1][comp][3] + dp[i][comp][1])%MOD;

            dp[i+1][comp][0] = (dp[i+1][comp][0]+dp[i][comp][2])%MOD;
            dp[i+1][comp+2][1] = (dp[i+1][comp+2][1]+dp[i][comp][2])%MOD;
            dp[i+1][comp][2] = (dp[i+1][comp][2]+dp[i][comp][2])%MOD;
            dp[i+1][comp][3] = (dp[i+1][comp][3]+dp[i][comp][2])%MOD;

            dp[i+1][comp+1][0] = (dp[i+1][comp+1][0]+dp[i][comp][3])%MOD;
            dp[i+1][comp+1][1] = (dp[i+1][comp+1][1]+dp[i][comp][3])%MOD;
            dp[i+1][comp+1][2] = (dp[i+1][comp+1][2]+dp[i][comp][3])%MOD;
            dp[i+1][comp][3] = (dp[i+1][comp][3]+dp[i][comp][3])%MOD;
        }
    }

    ll res = 0;
    fr(0,4){
        res = (res + dp[n-1][k][i]) % MOD;
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