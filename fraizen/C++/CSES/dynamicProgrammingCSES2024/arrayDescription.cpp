#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007

void solve() {
    int n,m; cin >> n>>m; int a[n]; fr(0,n) cin >> a[i];
    int dp[n][m+1];
    memset(dp,0,sizeof(dp));
    if (a[0] == 0){
        fr(1,m+1){
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
    fr(1,n){
        if (a[i] != 0){
            if (a[i]-1 >=0 ){
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1] % MOD) % MOD;
            }
            if (a[i] +1 <= m){
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+1] % MOD) % MOD;
            }
            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]] % MOD) % MOD;
        } else {
            rep(j,1,m+1){
                if (j-1 >=0 ){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1] % MOD) % MOD;
                }
                if (j +1 <= m){
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1] % MOD) % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j] % MOD) % MOD;
            }
        }
    }
    // cout << "DP " << endl;
    // fr(0,n){
    //     rep(j,0,m+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll res = 0;
    if (a[n-1] == 0){
        fr(0,m+1){
            res = (res + dp[n-1][i] % MOD) % MOD ;
        }
        cout << res << "\n";
    } else {
        cout << dp[n-1][a[n-1]];
    }
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