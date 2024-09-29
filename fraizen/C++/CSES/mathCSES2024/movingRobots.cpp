#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
typedef long double ld;

int dxfraizen[] = {1,-1, 0,0};
int dyfraizen[] = {0,0, 1, -1};

//no lo termine xq no se como se sigue. me quede trancado y no entendi la editorial tampoco
int count(int i, int j){
    if ((i == 0 && j == 7)  or ((i == 0) && j == 0) or (i == 7 && j == 0) && (i == 7 && j == 7)){
        return 2;
    }
    if (i == 0 or i == 7 or j == 0 or j == 7){
        return 3;
    }
    return 4;
}

void solve() {
    int n; cin >> n;
    ld dp[n+1][8][8];
    fr(0,n+1){
        rep(j,0,8){
            rep(k,0,8){
                if (i == 1){
                    dp[0][j][k] = 1.0;
                } else {
                    dp[i][j][k] = 0.0;
                }
    
            }
        }
    }
    fr(1,n+1){
        rep(j,0,8){
            rep(k,0,8){
                int valid = count(j,k);
                for(auto dx:dxfraizen){
                    for(auto dy:dyfraizen){
                        int newX = j + dx;
                        int newY = k + dy;
                        if (newX >= 0 and newX < 8 and newY >= 0 and newY < 8){
                            dp[i][newX][newY] += dp[i-1][j][k] / valid;
                        }
                    }
                }
            }
        }
    }
    fr(0,8){
        rep(j,0,8){
            cout <<fixed << setprecision(10) << dp[1][i][j] << " ";
        }
        cout << endl;
    }
    ld res = 0.0;
    fr(0,8){
        rep(j,0,8){
            res += dp[n][i][j];
        }
    }
    cout << fixed << setprecision(8) << res << "\n";
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