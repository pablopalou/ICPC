//copiar obligatoriamente
#include <bits/stdc++.h>
using namespace std;

//copiar obligatoriamente
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;

//Copiar luego
typedef long double ld;
typedef double d;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;

//Copiar obligatoriamente
#define debug(x) cout << #x << ": "; _print(x); cout << "\n";
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define ff first
#define ss second
#define fre(s) for(auto e:s)
#define MAXN 1000008

// Copiar luego
#define ppb pop_back
#define mod 1000000007
#define mod1 998244353
#define PI 3.141592653589793238462
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

//Copiar obligatoriamente de aca para abajo
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(d t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, size_t N> void _print(T (&arr)[N]);

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, size_t N> void _print(T (&arr)[N]) {cout << "[ "; for (size_t i = 0; i < N; ++i) {_print(arr[i]); cout << " ";}cout << "]";}

//falta terminar... 
bool valid(int i,int j,int l,int c){
    if (i < 0 || j < 0 || i >= l || j >=c){
        return false;
    }
    return true;
}

void solve() {
    int l, c;
    cin >> l >> c;
    char tablero[l][c];
    bool entre[l][c];
    bool entreAhora[l][c];
    bool conte[l][c];
    int res = 0;
    fr(0,l){
        string s; cin >> s;
        rep(j,0,c){
            tablero[i][j] = s[j];
        }
    }
    rep(j,0,l){
        rep(h,0,c){
            entre[j][h] = false;
        }
    }
    rep(j,0,l){
        rep(h,0,c){
            conte[j][h] = false;
        }
    }
    int n; cin >> n;
    fr(0,n){
        debug(i);
        rep(j,0,l){
            rep(h,0,c){
                cout << entre[j][h] << ' ';
            }
            cout(' ');
        }
        rep(j,0,l){
            rep(h,0,c){
                entreAhora[j][h] = false;
            }
        }
        string a;
        cin >> a;
        map<char, int> m1;
        rep(j,0, a.size()){
            m1[a[j]]++;
        }
        // horizontales
        rep(j, 0, l){ // para cada horizontal
            map<char, int> m2; //armo mapa
            rep(k,0,a.size()){ //pongo primeras letras
                m2[tablero[j][k]]++;
            }
            debug(m2);
            if (m1 == m2){
                rep(k, 0, a.size()){
                    if (conte[j][k]){
                        continue;
                    } else if (entre[j][k] && !entreAhora[j][k]){
                        res++;
                        conte[j][k] = true;
                    } else {
                        entreAhora[j][k] = true;
                        entre[j][k] = true;
                    }
                }
            }
            rep(k, a.size(), l){
                m2[tablero[j][k]]++;
                //sacar el de la otra punta
                m2[tablero[j][k - a.size()]]--; //fijarse si no falta un -1
                // debug(m2);
                if (m1 == m2){
                    rep(h, k, k + a.size()){
                        if (conte[j][h]){
                            continue;
                        } else if (entre[j][h] && !entreAhora[j][h]){
                            res++;
                            conte[j][h] = true;
                        } else {
                            entre[j][h] = true;
                            entreAhora[j][h] = true;
                        }
                    }
                }
            }
        }
        // verticales
        rep(j, 0, c){ // para cada vertical
            map<char, int> m2; //armo mapa
            rep(k,0,a.size()){ //pongo primeras letras
                m2[tablero[k][j]]++;
            }
            if (m1 == m2){
                rep(k, 0, a.size()){
                    if (conte[k][j]){
                        continue;
                    } else if (entre[k][j] && !entreAhora[k][j]){
                        res++;
                        conte[k][j] = true;
                    } else {
                        entre[k][j] = true;
                        entreAhora[k][j] = true;
                    }
                }
            }
            rep(k, a.size(), c){
                m2[tablero[k][k]]++;
                //sacar el de la otra punta
                m2[tablero[k][j - a.size()]]--; //fijarse si no falta un -1
                if (m1 == m2){
                    rep(h, k, k + a.size()){
                        if (conte[h][j]){
                            continue;
                        } else if (entre[h][j] && !entreAhora[h][j]){
                            res++;
                            conte[h][j] = true;
                        } else {
                            entre[h][j] = true;
                            entreAhora[h][j] = true;
                        }
                    }
                }
            }
        }
        //diagonales de izq a der (min(l,c+1-ci))    1.. l-1... lx ... l-1 a 1
        rep(j, 0, c){ // para cada diagnoal
            //arrrancar en [0][j];
            bool salir = false;
            map<char, int> m2; //armo mapa
            rep(k,0,a.size()){ //pongo primeras letras
                if (! valid(k,j+k, l,c)){
                    salir = true;
                    break;
                }
                m2[tablero[k][j+k]]++;
            }
            // debug(j);
            // debug(m2);
            if (salir){
                break;
            }
            if (m1 == m2){
                rep(k, 0, a.size()){
                    if (conte[k][j+k]){
                        continue;
                    } else if (entre[k][j+k] && !entreAhora[k][j+k]){
                        res++;
                        conte[k][j+k] = true;
                    } else {
                        entre[k][j+k] = true;
                        entreAhora[k][j+k] = true;
                    }
                }
            }
            rep(k, a.size(), 41){
                if (! valid(k,j+k, l,c)){
                    break;
                }
                m2[tablero[k][j+k]]++;
                m2[tablero[k - a.size()][j+k - a.size()]]--; //fijarse si no falta un -1
                if (m1 == m2){
                    rep(h, 0, a.size()){
                        if (conte[k - a.size() +1 +h][j+k - a.size()+1+h]){
                            continue;
                        } else if (entre[k - a.size() +1 +h][j+k - a.size()+1+h] && !entreAhora[k - a.size() +1 +h][j+k - a.size()+1+h]){
                            res++;
                            conte[k - a.size() +1 +h][j+k - a.size()+1+h] = true;
                        } else {
                            entre[k - a.size() +1 +h][j+k - a.size()+1+h] = true;
                            entreAhora[k - a.size() +1 +h][j+k - a.size()+1+h] = true;
                        }
                    }
                }
            }
        }
        // rep(j, 0, l){ // para cada diagnoal de abajo digamos
        //     //arrrancar en [j+iter][j];
        //     bool salir = false;
        //     map<char, int> m2; //armo mapa
        //     rep(k,0,a.size()){ //pongo primeras letras
        //         if (! valid(j+k+iter,j+k, l,c)){
        //             salir = true;
        //             break;
        //         }
        //         m2[tablero[j+k+iter][j+k]]++;
        //     }
        //     if (salir){
        //         break;
        //     }
        //     if (m1 == m2){
        //         rep(k, 0, a.size()){
        //             if (conte[j+k+iter][j+k]){
        //                 continue;
        //             } else if (entre[j+k+iter][j+k]){
        //                 res++;
        //                 conte[j+k+iter][j+k] = true;
        //             } else {
        //                 entre[j+k+iter][j+k] = true;
        //             }
        //         }
        //     }
        //     rep(k, a.size(), 41){
        //         if (! valid(j+k+iter,j+k, l,c)){
        //             break;
        //         }
        //         m2[tablero[j+k+iter][j+k]]++;
        //         //sacar el de la otra punta
        //         m2[tablero[j+k - a.size() +iter][j+k - a.size()]]--; //fijarse si no falta un -1
        //         if (m1 == m2){
        //             rep(h, 0, a.size()){
        //                 if (conte[j+k - a.size() +1 +h +iter][j+k - a.size()+1+h]){
        //                     continue;
        //                 } else if (entre[j+k - a.size() +1 +h +iter][j+k - a.size()+1+h]){
        //                     res++;
        //                     conte[j+k - a.size() +1 +h +iter][j+k - a.size()+1+h] = true;
        //                 } else {
        //                     entre[j+k - a.size() +1 +h +iter][j+k - a.size()+1+h] = true;
        //                 }
        //             }
        //         }
        //     }
        //     iter++;
        // }
    }
    cout(res);
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    freopen("L.in", "r", stdin);
    freopen("L.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}