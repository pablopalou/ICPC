#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define inf 1e18

void solve() {
    ll n; cin >> n;
    ll a[n], b[n];
    fr(0,n){
        cin >> a[i] >> b[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(3,inf));
    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = b[0] * 2;
    fr(1,n){
        rep(j,0,3){
            rep(k,0,3){
                if (k + a[i] != j + a[i-1]){
                    dp[i][k] = min(dp[i][k], k * b[i] + dp[i-1][j]);
                }
            }
        }
    }
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
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