#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n,k; cin >>n>>k;
    int a[k][n];
    fr(0,k){
        rep(j,0,n){
            cin >> a[i][j]; 
        }
    }
    if (k == 1){
        cout << "YES\n"; return;
    }
    map<ll,ll> m;
    //en el primero ya tengo que dejar el orden pronto
    // vector<int> pos;
    int falta = a[0][0];
    int hayOrden = false;
    int minimaPosicion;
    fr(1,n){
        // pos.pb(a[0][i]);
        m[a[0][i]] = i*2-1;
    }
    int falta2 = a[1][0];
    // fre(m){
    //         cout << e.first << " " << e.second << endl;
    //     }
    //     cout << endl;
    ll minPos = 0;
    bool listo = false;
    fr(1,n){
        if (a[1][i] == falta && i!=1 && i!=n-1){
            // cout << "ENTRO AL IF " << endl;
            m[a[1][i]] = minPos+1;
            listo = true;
            break;
        } else if (a[1][i]== falta && ((i==1 && falta2!=a[0][0])|| (i==n-1 && falta2!=a[0][n-1]) ) ){
            m[a[1][i]] = minPos+1;
            listo = true;
            break;
        }
        minPos = max(minPos, m[a[1][i]]);
    }
    // cout << endl;
    // fre(m){
    //         cout << e.first << " " << e.second << endl;
    //     }
    //     cout << endl;

    if (listo){
        fr(1,k){
            rep(j,1,n-1){
                if (m[a[i][j]] > m[a[i][j+1]]){
                    cout << "NO\n"; return;
                }
            }
        }
        cout << "YES\n"; return;
    } else if (k==2){
        fr(1,k){
            rep(j,1,n-1){
                if (k ==2 && a[i][j] == falta || a[i][j+1] == falta) continue;
                if (m[a[i][j]] > m[a[i][j+1]]){
                    cout << "NO\n"; return;
                }
            }
        }
        cout << "YES\n"; return;
    } else {
        // cout << "Falta " << falta << endl;
        // cout(falta2);
        // fre(m){
        //     cout << e.first << " " << e.second << endl;
        // }
        int posFalta1 = -1;
        int posFalta2 = -1;
        fr(1,n-1){
            if (a[2][i] == falta){
                posFalta1 = i;
            }
            if (a[2][i] == falta2){
                posFalta2 = i;
            }
        }
        if (posFalta1 > posFalta2){
            m[falta] = m[falta2]-1;
        } else {
            m[falta] = m[falta2]+1;
        }
        // cout << endl;
        // fre(m){
        //     cout << e.first << " " << e.second << endl;
        // }
        fr(1,k){
            rep(j,1,n-1){
                if (m[a[i][j]] > m[a[i][j+1]]){
                    cout << "NO\n"; return;
                }
            }
        }
        cout << "YES\n"; return;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}