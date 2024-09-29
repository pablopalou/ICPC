#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

//ESTE DA WA NO SE XQ, LO REESCRIBI EN EL ARCHIVO L2 Y DIO AC
int global = 0; 

string ask(int x, int y){
    // global++;
    // cout << "global = " << global << endl;
    cout << x+1 << ' ' << y+1 << endl;
    // return "";
    string ans; cin >> ans;
    return ans;
}

void check_direction(int &barcos, int i, int j, int k, int di, int dj, int n) {
    for (int fraizen = 1; fraizen < 6; ++fraizen) {
        int new_i = i * 5 + j + di * fraizen;
        int new_k = k * 5 + j + dj * fraizen;
        if (new_i >= 0 && new_i < n && new_k >= 0 && new_k < n) {
            if (ask(new_i, new_k) == "sunk") {
                barcos--;
                if (barcos == 0) {
                    exit(0);
                }
            }
        }
    }
}

void solve() {
    int n,barcos; cin >> n >> barcos;
    fr(0,n/5 + 1){
        rep(j,0,5){
            rep(k,0,n/5 + 1){
                if (i*5 + j < n && k*5 + j < n){
                    string ans = ask(i*5 + j, k*5 + j);
                    // continue;
                    if (ans == "miss"){
                        continue;
                    } else if (ans == "sunk"){
                        barcos--;
                        if (barcos == 0){
                            return;
                        }
                    } 
                    check_direction(barcos, i, j, k, 0, -1, n); // Up
                    check_direction(barcos, i, j, k, 0, 1, n);  // Down
                    check_direction(barcos, i, j, k, 1, 0, n);  // Right
                    check_direction(barcos, i, j, k, -1, 0, n); // Left
                    //le pegue, tengo que probar los costados y hundirlo.
                    //pruebo hacia arriba:
                    // rep(fraizen, 1,6){
                    //     if (k*5 + j - fraizen >= 0){
                    //         ans = ask(i*5 + j, k*5 + j - fraizen);
                    //         if (ans == "sink"){
                    //             barcos--;
                    //             if (barcos == 0){
                    //                 return;
                    //             }
                    //         }
                    //     }
                    // }
                    // //pruebo pa abajo
                    // rep(fraizen, 1,6){
                    //     if (k*5 + j + fraizen < n){
                    //         ans = ask(i*5 + j, k*5 + j + fraizen);
                    //         if (ans == "sink"){
                    //             barcos--;
                    //             if (barcos == 0){
                    //                 return;
                    //             }
                    //         }
                    //     }
                    // }
                    // //derecha
                    // rep(fraizen, 1,6){
                    //     if (i*5 + j + fraizen < n){
                    //         ans = ask(i*5 + j + fraizen, k*5 + j);
                    //         if (ans == "sink"){
                    //             barcos--;
                    //             if (barcos == 0){
                    //                 return;
                    //             }
                    //         }
                    //     }
                    // }
                    // //izquierda
                    // rep(fraizen, 1,6){
                    //     if (i*5 + j - fraizen >= 0){
                    //         ans = ask(i*5 + j - fraizen, k*5 + j);
                    //         if (ans == "sink"){
                    //             barcos--;
                    //             if (barcos == 0){
                    //                 return;
                    //             }
                    //         }
                    //     }
                    // }
                    
                }
            }
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