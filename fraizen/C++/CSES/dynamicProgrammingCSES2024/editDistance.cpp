#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(); int m = s2.size();
    int dp[n+1][m+1];
    fr(0,n+1){
        rep(j,0,m+1){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    fr(0,n+1){
        rep(j,0,m+1){
            if (i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
            if (i && j) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1]!=s2[j-1]));
            }
        }
    }
    // fr(0,n+1){
    //     rep(j,0,m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << '\n';
}

//ta mega buggeado, F
// void solve() {
//     string s1, s2; cin >> s1 >> s2;
//     int dp[2][5100];
//     int n = s1.size();
//     int m = s2.size();
//     fr(0,2){
//         rep(j,0,m+1){
//             dp[i][j] = 1e9;
//         }
//     }
//     dp[0][0] = 0;
//     fr(1,m+1){
//         dp[0][i] = dp[0][i-1] + 1;
//     }
//     // rep(j,0,m+1){
//     //     cout << dp[0][j] << ' ';
//     // }
//     // cout << endl;
//     fr(0,n){
//         dp[1][0] = dp[0][0] + 1;
//         rep(j,1,m+1){
//             int cur = 1e9;
//             cur = min(cur, dp[0][j] + 1);
//             if (j > 0){
//                 cur = min(cur, dp[1][j-1] + 1);
//                 cur = min(cur, dp[0][j-1] + (s1[i]!=s2[j-1]));
//             }
//             dp[1][j] = min(dp[1][j], cur);
//         }
//         swap(dp[0], dp[1]);
//         // rep(j,0,m+1){
//         //     cout << dp[0][j] << ' ';
//         // }
//         // cout << endl;
//         rep(h, 0,m){
//             dp[1][h] = 1e9;
//         }
//     }
//     cout << dp[0][m] << '\n';
// }

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