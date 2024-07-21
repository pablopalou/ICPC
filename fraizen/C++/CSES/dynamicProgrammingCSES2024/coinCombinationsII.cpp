#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007

void solve() {
    int n, x; cin >> n >> x; int a[n]; fr(0,n) cin >> a[i];
    int dp[2][1000010];
    memset(dp,0,sizeof(dp));
    fr(0,n){
        rep(j,0,x+1){
            dp[1][j] = dp[0][j];
            if (j == a[i]){
                dp[1][j] += 1;
            }
            if (j-a[i] >= 0 && dp[1][j - a[i]] > 0){
                dp[1][j] = (dp[1][j] % MOD + dp[1][j-a[i]] % MOD) % MOD;
            }
        }
        swap(dp[0], dp[1]);
        fill(dp[1], dp[1]+x+1, 0);
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