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

int puntosL, puntosR, setL, setR, serve; // 0 izq, 1 der

bool ganoSet(){
    if (puntosL == 5 && puntosR <= 3){
        return true;
    }
    if (puntosR == 5 && puntosL <= 3){
        return true;
    }
    if (puntosR == 10 || puntosL == 10){
        return true;
    }
    if (puntosR >= 4 && puntosL >= 4 && (puntosR - puntosL == 2 || puntosL - puntosR == 2)){
        return true;
    }
    return false;
}

void reiniciarPuntos(){
    puntosL = 0;
    puntosR = 0;
}

void solve() {
    string s; cin >> s;
    fr(0,s.size()){
        if (s[i] == 'S'){
            if (serve == 0){
                puntosL++;
                if (ganoSet()){
                    setL++;
                    reiniciarPuntos();
                }
                serve = 0;
            } else {
                puntosR++;
                if (ganoSet()){
                    setR++;
                    reiniciarPuntos();
                }
                serve = 1;
            }
        } else if (s[i] == 'R'){
            if (serve == 0){
                puntosR++;
                if (ganoSet()){
                    setR++;
                    reiniciarPuntos();
                }
                serve = 1;
            } else {
                puntosL++;
                if (ganoSet()){
                    setL++;
                    reiniciarPuntos();
                }
                serve = 0;
            }
        } else { //imprimir
            if (i == s.size()-1){ //ya alguien gano
                if (setL == 2){
                    cout << "2 (winner) - " << setR << "\n";
                } else {
                    cout << setL << " - 2 (winner)" << "\n";   
                }
            } else {
                if (serve == 0){
                    cout << setL << " (" << puntosL << "*) - " << setR << " (" << puntosR << ")" << "\n";   
                } else {
                    cout << setL << " (" << puntosL << ") - " << setR << " (" << puntosR << "*)" << "\n";   
                }
            }
        }
    }

}

// ACORDATE DE USAR LONG LONG
int main() {
    serve = 0; 
    setL = 0; 
    puntosL = 0; 
    puntosR = 0; 
    setR = 0;
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("F.in", "r", stdin);
    // freopen("F.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}