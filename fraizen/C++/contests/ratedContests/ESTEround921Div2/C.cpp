//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define cout(x) cout << x << "\n";

//copiar luego 3
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;

//Copiar luego 4
typedef long double ld;
typedef double d;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;

//Copiar obligatoriamente 2
#define debug(x) cout << #x << ": "; _print(x); cout << "\n";
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = a; i<b; i++)

//copiar luego 4
#define ff first
#define ss second
#define fre(s) for(auto e:s)
#define MAXN 1000008

// Copiar luego 4
#define ppb pop_back
#define mod 1000000007
#define mod1 998244353
#define PI 3.141592653589793238462
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

//Copiar luego 4
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

// Copiar obligatoriamente 0
void solve() {
    int n,k,m; cin >> n >> k >> m;
    string s; cin >> s;
    if (s.size() < n * k){
        cout << "NO" << endl;
        //ahora imprimir ejemplo... solo es agarrar la que falte al final o algo de eso
        // 100% que falta alguna letra, la repito y chau.
        map<char, int> m;
        char faltaLetra;
        bool faltaaa = false;
        fr(0,n){
            rep(j,0,k){
                m[s[i*k+j]]++;
            }
        }
        // fre(m){
        //     cout << e.first << " => " << e.second << endl;
        // }
        for (char c = 'a'; c < ('a' + k) ; c++){
            if (m[c] < n){
                faltaLetra = c;
                faltaaa = true;
            }
        }
        if (faltaaa){
            string res = "";
            fr(0,n){
                res += faltaLetra;
            }
            cout << res << "\n";
            return;
        }
    } else if (s.size() == n * k ){
        string res = "";
        bool respuestaNo = false;
        int pos = 0;
        char letra;
        bool primeraVez = true;
        map<char, int> grupo;
        char sobra;
        bool entra = false;
        fr(0,n){
            rep(j,0,k){
                grupo[s[i*k+j]]++;
            }
            for (char c = 'a'; c < ('a' + k); c++){
                // cout << "LETRA : " << c << endl;
                if (grupo[c] < i + 1){
                    // cout << "fallo " <<  letra << endl;
                    // cout << "NO" << endl;
                    letra = c;
                    pos = i;
                    respuestaNo = true;
                    entra = true;
                }
            }
            if (primeraVez && entra){
                primeraVez = false;
                // me fijo cuales sobran
                vector<char> sobran;
                for (char c = 'a'; c <= ('a' + k) ; c++){
                    if (grupo[c] > i){
                        sobran.pb(c);
                        sobra = c;
                    }
                }
            }
        }
        if (respuestaNo){
            //primero me fijo si falta alguna...
            char faltaLetra;
            bool faltaaa = false;
            for (char c = 'a'; c < ('a' + k) ; c++){
                if (grupo[c] < n){
                    faltaLetra = c;
                    faltaaa = true;
                }
            }
            if (faltaaa){
                res = "";
                fr(0,n){
                    res += faltaLetra;
                }
                cout << "NO" << "\n";
                cout << res << "\n";
                return;
            }
            //armar palabra
            int i = 0;
            while(i < pos){
                i++;
                res += 'a';
            }
            res += letra;
            //pa mi agarro cualquiera que sobre y fue
            int tam = res.size();
            while (tam < k){
                res += sobra;
                tam++;
            }
            cout << "NO" << "\n";
            cout << res << "\n";
            return;
        } else {
            cout << "YES" << endl;
            return;
        }
    } else { //tenemos letras de "sobra"
        // cout << "letras de sobra" << endl;
        int sobran = s.size() - n * k;
        map<char, int> grupo;
        fr(0,sobran){
            grupo[s[i]]++;
        }
        //copio el codigo normal
        string res = "";
        bool respuestaNo = false;
        int pos = 0;
        char letra;
        bool primeraVez = true;
        char sobra;
        bool entra = false;

        fr(0,n){
            rep(j,0,k){
                grupo[s[i*k+j + sobran]]++;
            }
        //             fre(grupo){
        //     cout << e.first << " => " << e.second << endl;
        // }
            for (char c = 'a'; c < ('a' + k); c++){
                // cout << "LETRA : " << c << endl;
                if (grupo[c] < i+1){
                    // cout << "fallo " <<  letra << endl;
                    letra = c;
                    pos = i;
                    respuestaNo = true;
                    entra = true;
                }
            }
            if (primeraVez && entra){
                primeraVez = false;
                // me fijo cuales sobran
                vector<char> sobran;
                for (char c = 'a'; c < ('a' + k) ; c++){
                    if (grupo[c] > i){
                        sobran.pb(c);
                        sobra = c;
                    }
                }
            }
        }

        if (respuestaNo){
            //primero me fijo si falta alguna...
            char faltaLetra;
            bool faltaaa = false;
            for (char c = 'a'; c < ('a' + k) ; c++){
                if (grupo[c] < n){
                    faltaLetra = c;
                    faltaaa = true;
                }
            }
            if (faltaaa){
                res = "";
                fr(0,n){
                    res += faltaLetra;
                }
                cout << "NO" << endl;
                cout << res << "\n";
                return;
            }
            //armar palabra
            int i = 0;
            // cout << pos; 
            while(i < pos){
                i++;
                res += letra;
            }
            // cout << "letra" << letra << endl;
            res += letra;
            //pa mi agarro cualquiera que sobre y fue
            int tam = res.size();
            // cout << sobra << endl;
            while (tam < k){
                res += sobra;
                tam++;
            }
            cout << "NO" << endl;
            cout << res << "\n";
            return;
        } else {
            cout << "YES" << endl;
            return;
        }
    }
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}