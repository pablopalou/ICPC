#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    int n,r,c,k;
    int m[102][102];
    while (cin >> n >> r >> c >> k){
        if (n == 0 && r == 0 && c == 0 && k == 0) return;
        memset(m, -1, sizeof(m));
        fr(0,r){
            rep(j, 0,c){
                cin >> m[i][j]; 
            }
        }
        int res[102][102];
        rep(iter, 0,k){
            memset(res, -1, sizeof(res));
            fr(0,r){
                rep(j, 0,c){
                    if (i > 0){
                        if ((m[i][j] + 1)%n == m[i-1][j]) {
                            res[i-1][j] = m[i][j]; 
                        }
                    }
                    if (i < r-1){
                        if ((m[i][j] + 1)%n == m[i+1][j]) {
                            res[i+1][j] = m[i][j]; 
                        }
                    }
                    if (j > 0){
                        if ((m[i][j] + 1)%n == m[i][j-1]) {
                            res[i][j-1] = m[i][j]; 
                        }
                    }
                    if (j < c-1){
                        if ((m[i][j] + 1)%n == m[i][j+1]) {
                            res[i][j+1] = m[i][j]; 
                        }
                    }
                }
            }
            fr(0,r){
                rep(j,0,c){
                    if (res[i][j] == -1){
                        res[i][j] = m[i][j];
                    }
                }
            }
            swap(m,res);
        }
        fr(0,r){
            rep(j,0,c){
                if (j < c-1){
                    cout << m[i][j] << ' ';
                } else {
                    cout << m[i][j];
                }
            }
            cout << "\n";
        }
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