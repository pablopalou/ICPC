#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define inf 1000000000

void solve() {
    int n,k; cin >> n >>k;
    string s; cin >> s;
    if (k >= 105000){
        cout << 0 << '\n';
        return;
    }
    //meto infinito en todo
    ll dp[2][455][455];
    fr(0,2){
        rep(j,0,n+3){
            rep(k,0,n+3){
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    fr(0,n){
        rep(j,0,n+1){
            rep(k2,0,n+1){
                if (s[i] == '0'){
                    dp[1][j][0] = min(dp[1][j][0], dp[0][j][k2]);
                } else {
                    dp[1][j][k2+1] = min(dp[1][j][k2+1], dp[0][j][k2] + k2 + 1);
                    dp[1][j+1][0] = min(dp[1][j+1][0], dp[0][j][k2]);
                }
            }
        }
        swap(dp[1], dp[0]);
        rep(j,0,n+3){
            rep(k2,0,n+3){
                dp[1][j][k2] = inf;
            }
        }
    }
    // rep(j,0,n){
    //     rep(k2,0,n){
    //         cout << dp[0][j][k2] << ' ';
    //     }
    //     cout << "\n";
    // }
    // tengo la proteina minima que necesito.
    ll res = 500;
    rep(j,0,n+1){
        rep(k2,0,n+1){
            if (k >= dp[0][j][k2]){
                res = min(res,ll(j));
            }
        }
    }
    assert(res<500);
    cout << res << '\n';
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