#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define INF 2e18
ll dp[200100][4];
ll a[200100];

void solve() {
    ll n; cin >> n;
    fr(0,n) cin >> a[i];
    fr(0,n+1){
        rep(j,0,3){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    fr(1,n+1){
        dp[i][0] = min(dp[i][0], dp[i-1][0] + (a[i-1]>0?1:0));
        if (a[i-1] >= 5){
            continue;
        }
        if (a[i-1] <= 2){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
        }
        if (a[i-1] >= 3 && a[i-1] <= 4){
            // dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
            // dp[i][0] = min(dp[i][0], dp[i-1][2] + 1);
            // dp[i][0] = min(dp[i][0], dp[i-1][0] + 2);
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }
    cout << dp[n][0] << "\n";
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