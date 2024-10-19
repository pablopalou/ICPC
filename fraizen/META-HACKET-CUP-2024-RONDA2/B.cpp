#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define mp make_pair

bool valid(int x, int y){
    return (x >= 0 && x <=5 && y >= 0 && y <= 6);
}

void solve() {
    // cout << endl;
    char mat[6][7];
    for(int i = 5; i>=0; i--){
        rep(j,0,7){
            cin >> mat[i][j];
        }
    }
    bool invalid[6][7];
    fr(0,6) rep(j,0,7) invalid[i][j] = false;
    //chequeo todas las formas posibles
    set<vector<pair<int,int> > > ganoF, ganoC;
    vector<pair<int,int> > mejorHorizontal0, mejorHorizontal1, mejorHorizontal2;
    fr(0,6){
        rep(j,0,7){
            //me fijo si i,j es un borde de una solucion
            //horizontal pa la derecha
            if (valid(i, j+1) && valid(i,j+2) && valid(i,j+3)){
                if (mat[i][j] == mat[i][j+1] && (mat[i][j] == mat[i][j+2]) && (mat[i][j] == mat[i][j+3])){
                    vector<pair<int,int> > v; 
                    v.pb(mp(i,j));
                    v.pb(mp(i,j+1));
                    v.pb(mp(i,j+2));
                    v.pb(mp(i,j+3));
                    if (mat[i][j] == 'C'){
                        ganoC.insert(v);
                    } else {
                        ganoF.insert(v);
                    }
                }
            }
            //horizontal pa la izquierda deberia estar cubierto
            //vertical hacia arriba
            if (valid(i+1, j) && valid(i+2,j) && valid(i+3,j)){
                if (mat[i][j] == mat[i+1][j] && (mat[i][j] == mat[i+2][j]) && (mat[i][j] == mat[i+3][j])){
                    vector<pair<int,int> > v; 
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j));
                    v.pb(mp(i+2,j));
                    v.pb(mp(i+3,j));
                    if (mat[i][j] == 'C'){
                        ganoC.insert(v);
                    } else {
                        ganoF.insert(v);
                    }
                }
            }
            //vertical hacia abajo deberia estar cubierto
            //diagnoal hacia arriba a la derecha 
            if (valid(i+1, j+1) && valid(i+2,j+2) && valid(i+3,j+3)){
                if (mat[i][j] == mat[i+1][j+1] && (mat[i][j] == mat[i+2][j+2]) && (mat[i][j] == mat[i+3][j+3])){
                    vector<pair<int,int> > v; 
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j+1));
                    v.pb(mp(i+2,j+2));
                    v.pb(mp(i+3,j+3));
                    if (mat[i][j] == 'C'){
                        ganoC.insert(v);
                    } else {
                        ganoF.insert(v);
                    }
                }
            }
            //diagnoal hacia abajo a la derecha me parece (pero yo soy el de abajo a la derecha)
            if (valid(i+1, j-1) && valid(i+2,j-2) && valid(i+3,j-3)){
                if (mat[i][j] == mat[i+1][j-1] && (mat[i][j] == mat[i+2][j-2]) && (mat[i][j] == mat[i+3][j-3])){
                    vector<pair<int,int> > v; 
                    v.pb(mp(i+3,j-3));
                    v.pb(mp(i+2,j-2));
                    v.pb(mp(i+1,j-1));
                    v.pb(mp(i,j));
                    if (mat[i][j] == 'C'){
                        ganoC.insert(v);
                    } else {
                        ganoF.insert(v);
                    }
                }
            }
            //las otras diagonales deberian haber quedado cubiertas
        }
    }

    // for(auto ganoc: ganoC){
    //     fre(ganoc){
    //         cout <<"(" << e.first  << ", " << e.second << ") "<< ", ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(auto ganoc: ganoF){
    //     fre(ganoc){
    //         cout <<"(" << e.first  << ", " << e.second << ") "<< ", ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;



    //para cada punto ganador, tiro hacia arriba un invalido. 
    for(auto ganoc: ganoC){
        // fre(ganoc){
        //     cout <<"(" << e.first  << ", " << e.second << ") "<< ", ";
        // }
        // cout << endl;
        //si es vertical, hay que tener cuidado. 
        if (ganoc[0].second == ganoc[1].second){
            int i = ganoc[3].first;
            i+=1;
            int j = ganoc[3].second;
            while(i < 6){
                if (invalid[5-i][j]) break;
                // cout << "marco como invalido al " << i << ',' << j << endl;
                invalid[5-i][j] = true;
                i++;
            }
        } else {
            // fre(ganoc){
            //     //itero los 4 puntos de ahi pa arriba y marco todo como invalid = true;
            //     //tengo el punto e
            //     int i = e.first;
            //     i+=1;
            //     int j = e.second;
            //     while(i < 6){
            //         if (invalid[5-i][j]) break;
            //         cout << "marco como invalido al " << i << ',' << j << endl;
            //         invalid[5-i][j] = true;
            //         i++;
            //     }
            // }
        }
    }
    for(auto ganoc: ganoF){
        // fre(ganoc){
        //     cout <<"(" << e.first  << ", " << e.second << ") "<< ", ";
        // }
        // cout << endl;
        //si es vertical, hay que tener cuidado. 
        if (ganoc[0].second == ganoc[1].second){
            int i = ganoc[3].first;
            i+=1;
            int j = ganoc[3].second;
            while(i < 6){
                if (invalid[5-i][j]) break;
                // cout << "marco como invalido al " << i << ',' << j << endl;
                invalid[5-i][j] = true;
                i++;
            }
        } else {
            // fre(ganoc){
            //     //itero los 4 puntos de ahi pa arriba y marco todo como invalid = true;
            //     //tengo el punto e
            //     int i = e.first;
            //     i+=1;
            //     int j = e.second;
            //     while(i < 6){
            //         if (invalid[5-i][j]) break;
            //         cout << "marco como invalido al " << i << ',' << j << endl;
            //         invalid[5-i][j] = true;
            //         i++;
            //     }
            // }
        }
    }

    // fr(0,6){
    //     rep(j,0,7){
    //         cout << invalid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    set<vector<pair<int,int> > > validosF, validosC;
    //se supone que ya me quedo todo bien lo de los invalidos y ya tengo las respuestas. 
    //ahora para cada uno, me tengo que fijar si son o no validos. 
    for(auto ganoc: ganoC){
        bool valid = true;
        fre(ganoc){
            if (invalid[e.first][e.second]){
                valid = false;
                break;
            }
        }
        if (valid){
            validosC.insert(ganoc);
        }
    }

    for(auto ganoc: ganoF){
        bool valid = true;
        fre(ganoc){
            if (invalid[e.first][e.second]){
                valid = false;
                break;
            }
        }
        if (valid){
            validosF.insert(ganoc);
        }
    }
    //ahora tengo los casi validos. Capaz habria que ir por cada uno definiendo los rangos validos.
    for(auto ganoc: validosC){
        if (ganoc[0].first == ganoc[1].first){ //es horizontal
            int i = ganoc[0].first + 1;
            int j = ganoc[0].second;
            while(i < 6){
                vector<pair<int,int> > v;
                v.pb(mp(i,j));
                v.pb(mp(i,j+1));
                v.pb(mp(i,j+2));
                v.pb(mp(i,j+3));
                validosC.erase(v);
                validosF.erase(v);
                i++;
            }
            //elimino los diagonales arriba mio
            if (i <= 2){
                while(i+3 < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j+1));
                    v.pb(mp(i+2,j+2));
                    v.pb(mp(i+3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
                i = ganoc[0].first + 1;
                while(i+3 < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i+3,j));
                    v.pb(mp(i+2,j+1));
                    v.pb(mp(i+1,j+2));
                    v.pb(mp(i,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            }
        } else {
            //saco los horizontales por encima de la diagonal
            int maxi = max(ganoc[0].first, ganoc[3].first);
            int j = min(ganoc[0].second, ganoc[3].second);
            while(maxi + 1 < 6){
                vector<pair<int,int> > v;
                v.pb(mp(maxi,j));
                v.pb(mp(maxi,j+1));
                v.pb(mp(maxi,j+2));
                v.pb(mp(maxi,j+3));
                validosC.erase(v);
                validosF.erase(v);
                maxi++;
            }
            //ahora tengo que sacar los diagonales (misma diagonal, por encima)
            if (ganoc[0].first > ganoc[3].first){ //la i baja, diagnoal hacia abajo
                int i = 1 + ganoc[0].first;
                while(i < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i-1,j+1));
                    v.pb(mp(i-2,j+2));
                    v.pb(mp(i-3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            } else {
                int i = 1 + ganoc[3].first; //sube
                while(i < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j+1));
                    v.pb(mp(i+2,j+2));
                    v.pb(mp(i+3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            }
        }
    }

    for(auto ganoc: validosF){
        if (ganoc[0].first == ganoc[1].first){ //es horizontal
            int i = ganoc[0].first + 1;
            int j = ganoc[0].second;
            while(i < 6){
                vector<pair<int,int> > v;
                v.pb(mp(i,j));
                v.pb(mp(i,j+1));
                v.pb(mp(i,j+2));
                v.pb(mp(i,j+3));
                validosC.erase(v);
                validosF.erase(v);
                i++;
            }
            //elimino los diagonales arriba mio
            if (i <= 2){
                while(i+3 < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j+1));
                    v.pb(mp(i+2,j+2));
                    v.pb(mp(i+3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
                i = ganoc[0].first + 1;
                while(i+3 < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i+3,j));
                    v.pb(mp(i+2,j+1));
                    v.pb(mp(i+1,j+2));
                    v.pb(mp(i,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            }
        } else {
            //saco los horizontales por encima de la diagonal
            int maxi = max(ganoc[0].first, ganoc[3].first);
            int j = min(ganoc[0].second, ganoc[3].second);
            while(maxi + 1 < 6){
                vector<pair<int,int> > v;
                v.pb(mp(maxi,j));
                v.pb(mp(maxi,j+1));
                v.pb(mp(maxi,j+2));
                v.pb(mp(maxi,j+3));
                validosC.erase(v);
                validosF.erase(v);
                maxi++;
            }
            //ahora tengo que sacar los diagonales (misma diagonal, por encima)
            if (ganoc[0].first > ganoc[3].first){ //la i baja, diagnoal hacia abajo
                int i = 1 + ganoc[0].first;
                while(i < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i-1,j+1));
                    v.pb(mp(i-2,j+2));
                    v.pb(mp(i-3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            } else {
                int i = 1 + ganoc[3].first; //sube
                while(i < 6){
                    vector<pair<int,int> > v;
                    v.pb(mp(i,j));
                    v.pb(mp(i+1,j+1));
                    v.pb(mp(i+2,j+2));
                    v.pb(mp(i+3,j+3));
                    validosC.erase(v);
                    validosF.erase(v);
                    i++;
                }
            }
        }
    }

    if (validosC.size() == 0 && validosF.size() == 0){
        cout << "0\n";
    } else if (validosC.size() > 0 && validosF.size() > 0){
        cout << "?\n";
    } else if (validosC.size() == 0 && validosF.size() > 0){
        cout << "F\n";
    } else if (validosC.size() > 0 && validosF.size() == 0){
        cout << "C\n";
    }
}

// Para compilar: g++ -O2 -Wl,-stack_size,0x20000000 -o A A.cpp
// Para correr: ./A
// Acordate de usar LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //DESCOMENTAR ESTO PREVIO A BAJAR EL ARCHIVO
    freopen("four_in_a_burrow_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cases = 1;
    cin >> cases;
    rep(i,1,cases+1){
        cout << "Case #" << i << ": "; 
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}
