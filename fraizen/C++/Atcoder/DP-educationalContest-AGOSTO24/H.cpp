#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007
void solve() {
    int n,m; cin >> n >> m; char mat[n][m];
    fr(0,n){
        rep(j,0,m){
            cin >> mat[i][j];
        }
    }
    int dp[n][m]; memset(dp, 0, sizeof(dp));
    if (mat[0][0]=='#' or mat[n-1][m-1]=='#') {cout << 0 << '\n'; return;}
    dp[0][0] = 1;
    fr(1,n){
        if (mat[i][0] == '.'){
            dp[i][0] = dp[i-1][0];
        } else {
            dp[i][0] = 0;
        }
    }
    fr(1,m){
        if (mat[0][i] == '.'){
            dp[0][i] = dp[0][i-1];
        } else {
            dp[0][i] = 0;
        }
    }
    fr(1,n){
        rep(j,1,m){
            if (mat[i][j] == '#'){
                dp[i][j] = 0; continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    cout << dp[n-1][m-1];
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