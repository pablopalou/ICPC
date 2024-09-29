#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n"
#define pb push_back
void solve() {
    int n; int x; cin >> n >> x;
    int a[n]; fr(0,n) cin >> a[i];
    map<int, int> m; //cantidad
    fr(0,n){
        m[a[i]]++;
    }
    if (m.size()==2){
        auto it = m.begin();
        int num1 = it->first;
        it++;
        int num2 = it->first;
        if (num1 + num2 == x){ //caso de un unico grupo
            cout << "*\n";
            return;
        }
    }

    // fre(m){
    //     cout << e.first << " " << e.second << endl;
    // }
    // cout << endl;
    vector<int> res1, res2;
    vector<int> sueltos;
    if (x % 2 == 1){ //x es impar, estoy salvado con el caso 5555, entonces solo tengo grupos disjuntos
        //me guardo los sueltos
        //aca es como que puedo poner de a grupos? 
        fre(m){
            int efirst = e.first;
            int esecond = e.second;
            if (esecond > 0){
            // cout << "e.first " << efirst << "\n";
                if (efirst <= x/2){
                    if (m[x-efirst] == 0){
                        fr(0,esecond){
                            sueltos.pb(efirst);
                        }
                        // cout << "pongo " << efirst << " a sueltos" << "\n";
                    } else {
                        fr(0,esecond){
                            // cout << "pongo " << efirst << " a res1" << "\n";
                            res1.pb(efirst);
                        }
                    }
                } else {
                    if (m[x-efirst] == 0){
                        fr(0,esecond){
                        sueltos.pb(efirst);
                        }
                        // cout << "pongo " << efirst << " a sueltos" << "\n";
                    } else {
                        fr(0,esecond){
                            // cout << "pongo " << efirst <<  " a res 2"<< "\n";
                            res2.pb(efirst);
                        }
                    }
                }
            }
        }
        //falta poner los sueltos, que los pongo en el medio y chau
        fre(res1){
            cout << e << ' ';
        }
        fre(sueltos){
            cout << e << ' ';
        }
        sort(res2.begin(), res2.end(), greater<ll>());
        fre(res2){
            cout << e << ' ';
        }
        return;
    } else {
        // cout << "HERE \n";
        int cant = m[x/2];
        // cout << "cant = " << cant << endl;
        // cout << "n-cant " << n-cant << endl;
        if (cant-1 > n-cant){ 
            cout << "*\n";
            return;
        }
        // cout << " X = " << x << endl;
        fre(m){
            int efirst = e.first;
            int esecond = e.second;
            if (esecond > 0 && e.first != x/2){
                // cout << "e.first " << efirst << "\n";
                if (efirst < x/2){
                    if (m[x-efirst] == 0){
                        fr(0,esecond){
                            sueltos.pb(efirst);
                        // cout << "pongo " << efirst << " a sueltos" << "\n";
                        }
                    } else {
                        fr(0,esecond){
                            // cout << "pongo " << efirst << " a res1" << "\n";
                            res1.pb(efirst);
                        }
                    }
                } else {
                    if (m[x-efirst] == 0){
                        fr(0,esecond){
                        sueltos.pb(efirst);
                        // cout << "pongo " << efirst << " a sueltos" << "\n";
                        }
                    } else {
                        fr(0,esecond){
                            // cout << "pongo " << efirst <<  " a res 2"<< "\n";
                            res2.pb(efirst);
                        }
                    }
                }
            }
        }
        //falta los 5s 
        vector<ll> resOficial;
        // while(cant > 0){
        fre(res1){
            if (cant > 0){
                resOficial.pb(x/2);
                cant--;
            }
            resOficial.pb(e);
        }

        // }
        fre(sueltos){
            if (cant > 0){
                resOficial.pb(x/2);
                cant--;
            }
            resOficial.pb(e);
        }
        sort(res2.begin(), res2.end(), greater<ll>());
        fre(res2){
            if (cant > 0){
                resOficial.pb(x/2);
                cant--;
            }
            resOficial.pb(e);
        }
        if (cant > 0){
            resOficial.pb(x/2);
        }
        vector<ll> resOficial2;
        bool puedo = true;
        fr(0, resOficial.size()-1){
            if (resOficial[i] + resOficial[i+1] == x){
                puedo = false;
            }
        }
        if (puedo){
            fre(resOficial){
                cout << e << ' ';
            }
            return;
        }
        //agarro el ultimo menor a x que no sea x/2;
        int ultimo = 0;
        int ultimoX = 0;
        fr(0,resOficial.size()){
            if (resOficial[i] < x/2){
                ultimo = i;
            }
            if (resOficial[i] == x/2){
                ultimoX = i;
            }
        }
        swap(resOficial[ultimoX], resOficial[ultimo]);
        fre(resOficial){
                cout << e << ' ';
            }
            return;
        //tengo que cambiar un x/2 a algun otro lado menor a x/2, 
        
        // fre(res1){
        //     resOficial.pb(e);
        // }
        // fre(sueltos){
        //     cout << e << ' ';
        // }
        // fre(res2){
        //     cout << e << ' ';
        // }
        return;


        //me falta poner los 5 nomas me parece. ??? 
        //OJO CON LOS NUMEROS SUELTOS
        //imprimir aca y chau
    }
    // fre(res1){
    //     cout << e << ' ';
    // }
}

int main() {
    std:iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    //cin >> cases;
    while(cases--) {
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}