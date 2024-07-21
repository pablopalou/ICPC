#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,m; cin >> n>>m;
    int a[n][m];
    fr(0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }

    //pongo los numeros
    for(int i = n-2; i>=0; i--){
        for(int j = m-2; j>=0; j--){
            if (a[i][j] != 0){
                continue;
            }
            //puedo ponerle valor
            a[i][j] = min(a[i+1][j], a[i][j+1]) - 1;
        }
    }

    // fr(0,n){
    //     rep(j,0,m){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    //chequeo filas
    fr(0,n){
        int mini = a[i][0];
        rep(j,1,m){
            if (a[i][j] <= mini){
                cout << "-1\n";
                return;
            } else {
                mini = a[i][j];
            }
        }
    }

    rep(j,0,m){
        int mini = a[0][j];
        rep(i,1,n){
            if (a[i][j] <= mini){
                cout << "-1\n";
                return;
            } else {
                mini = a[i][j];
            }
        }
    }

    ll suma = 0;
    fr(0,n){
        rep(j,0,m){
            suma += a[i][j];
        }
    }
    cout << suma << '\n';
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