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
    ll n; cin >> n;
    ll a[n];
    string s[n];
    fr(0,n){
        cin >> a[i];
    }
    sort(a, a+n);
    fr(0,n){
        s[i] = to_string(a[i]);
    }
    // fr(0,n){
    //     cout << a[i] << " ";
    // }
    // cout(' ');
    map<ll, map<ll,ll>> m;//mapa para guardar largo y adentro lo que tiene que sumar con la cantidad de veces
    fr(0,n){ //aca tengo que armar el mapa.
        ll sumDigits = 0;
        rep(j,0,s[i].size()){
            sumDigits += s[i][j] -'0';
        }
        ll fraizen = s[i].size();
        // s[i].size()
        if ( fraizen == 1){
            m[1][sumDigits]++;
        } else if (fraizen == 2){
            //solo guardo en largo 2.
            m[2][sumDigits]++;
        } else if ( fraizen == 3){ // solo guardo largo 1 y largo 3
            m[3][sumDigits]++;
            ll lastPart = sumDigits - (s[i][0] - '0');
            if (lastPart - (s[i][0] - '0') >= 0){
                m[1][lastPart - (s[i][0] - '0')]++;
            }
            // ojo que tmb puede ser para atras entonces seria largo 1 pero al final
            lastPart = sumDigits - (s[i][2] - '0');
            if (lastPart - (s[i][2] - '0') >= 0){
                m[1][lastPart - (s[i][2] - '0')]++;
            }
        } else if ( fraizen == 4){ //
            m[4][sumDigits]++;
            ll lastPart = sumDigits - (s[i][0] - '0');
            if (lastPart - (s[i][0] - '0') >= 0){
                m[2][lastPart - (s[i][0] - '0')]++;
            }
            // ojo que falta el 3 izq y 1 derecha, largo 2.
            lastPart = sumDigits - (s[i][3] - '0');
            if (lastPart - (s[i][3] - '0') >= 0){
                m[2][lastPart - (s[i][3] - '0')]++;
            }
        } else {
            m[5][sumDigits]++;
            //agregar largo 3 y largo 1
            ll lastPart = sumDigits - (s[i][0] - '0');
            if (lastPart - (s[i][0] - '0') >= 0){
                m[3][lastPart - (s[i][0] - '0')]++;
            }
            lastPart = sumDigits - (s[i][0] - '0') - (s[i][1] -'0');
            if (lastPart - (s[i][0] - '0') - (s[i][1] -'0') >= 0){
                m[1][lastPart - (s[i][0] - '0') - (s[i][1] -'0')]++;
            }
            //hay que dar vuelta. Largo 1 y largo 3.
            lastPart = sumDigits - (s[i][4] - '0');
            if (lastPart - (s[i][4] - '0') >= 0){
                m[3][lastPart - (s[i][4] - '0')]++;
            }
            lastPart = sumDigits - (s[i][4] - '0') - (s[i][3] -'0');
            if (lastPart - (s[i][4] - '0') - (s[i][3] -'0') >= 0){
                m[1][lastPart - (s[i][4] - '0') - (s[i][3] -'0')]++;
            }
        }
    }

    // for (const auto &outer_pair : m) {
    //     cout << "Length " << outer_pair.first << ": ";
    //     for (const auto &inner_pair : outer_pair.second) {
    //         cout << "{" << inner_pair.first << ": " << inner_pair.second << "} ";
    //     }
    //     cout << "\n";
    // }

    ll res = 0;
    fr(0,n){ // pa cada uno, calculo el resultado
        // debug(i);
        ll largo = (s[i].size());
        ll need = 0;
        rep(j,0,largo){
            need += (s[i][j] - '0');
        }
        //busco el lower_bound de lo que necesito en log n y sumo si es ese. 
        auto it = m[largo].lower_bound(need);
        if (it != m[largo].end() && (it->first) == need){
            // cout << "agrego " << it->second << endl;
            res += (it->second);
        }
    }
    cout(res);
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    ll cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}