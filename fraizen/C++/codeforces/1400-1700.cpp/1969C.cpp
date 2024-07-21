#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n,k; cin >> n>>k;
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 2e18));
    dp[0][0] = 0;
    fr(0,n){
        rep(j,0,k+1){
            ll mini = 2e18;
            for(int d = 0; j + d <= k && i+d < n; d++){
                mini = min(mini, a[i+d]);
                dp[i+d+1][j+d] = min(dp[i+d+1][j+d], dp[i][j] + (d+1)*mini);
            }
        }
    }
    // fr(0,n+1){
    //     rep(j,0,k+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}