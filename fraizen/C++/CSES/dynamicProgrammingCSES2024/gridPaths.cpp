#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007
void solve() {
    int n; cin >> n;
    char a[n][n];
    fr(0,n){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }
    if (a[0][0] == '*' or a[n-1][n-1] == '*'){
        cout << "0\n"; return;
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    fr(0,n){
        rep(j,0,n){
            if (a[i][j] == '*'){
                continue;
            }
            if (i > 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j] % MOD) %MOD;
            }
            if (j > 0){
                dp[i][j] = (dp[i][j] + dp[i][j-1] % MOD) %MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << '\n';
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