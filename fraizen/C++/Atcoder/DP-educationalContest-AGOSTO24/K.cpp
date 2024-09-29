#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,k; cin >>n >> k;
    int a[n]; fr(0,n) cin >> a[i];
    int dp[k+1];
    memset(dp, 0, sizeof(dp)); // 0 es perder, 1 es ganar
    fr(0,n){
        dp[a[i]] = 1;
    }
    fr(1,k+1){
        if (dp[i] == 1) continue;
        rep(j,0,n){
            if (i - a[j] >= 0){
                if (dp[i-a[j]] == 0){
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    // fr(0,k+1){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    if (dp[k] == 1){
        cout << "First\n";
    } else {
        cout << "Second\n";
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