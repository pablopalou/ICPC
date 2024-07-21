#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int dp[501][501];

void solve() {
    int w,h; cin >> w >> h;
    fr(0,w+1){
        rep(j,0,h+1){
            if (i == j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9;
            //pruebo cortar la i
            rep(k, 1, i){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            //pruebo cortar la j
            rep(k, 1, j){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout << dp[w][h] << '\n';
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