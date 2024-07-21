#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007
ll dp[1000005];

void solve() {
    int n; cin >> n;
    dp[1] = 1;
    fr(2,n+1){
        rep(j,1,7){
            if (i - j > 0){
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
        if (i <= 6){
            dp[i]++;
        }
    }
    cout << dp[n] << "\n";
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