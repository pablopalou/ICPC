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
set<string> s;
map<char,ll> cantOriginal;

ll fact[20];
void facts() {
    fact[0] = 1;
    fact[1] = 1;
    fr(2,20){
        fact[i] = i * fact[i-1];
    }
}

ll contar(string subset){
    sort(subset.begin(), subset.end());
    // cout << "estoy en subset: " << subset << endl;
    if (s.find(subset) != s.end()){
        return 0; //ya lo conte
    }

    map<char,ll> cont; //guardo cantidades
    ll largo = 0;
    for(char c: subset){
        cont[c]++;
        largo++;
    }
    // for(const auto& e: cont){
    //     cout << e.first << ": " << e.second << endl;
    // }
    s.insert(subset); // lo agrego al set
    //me fijo si ta bien el set, sino no puedo contar tampoco
    //tiene que tener uno de cada cosa...
    fr(0,10){
        // char j = 
        // cout << "i " << i << endl;
        // cout << i << endl;
        // cout << "original " << cantOriginal['0' +i] << endl;
        // cout << "actual " << cont['0' +i] << endl;
        if (cantOriginal['0' + i] && !cont['0' + i]){
            // cout << "Me voy xq no esta el " << i << endl;
            return 0; //no tiene un numero entonces ya retorno...
        }
    }
    // cout << "Increiblemente voy a sumar" << endl;

    //hago cuenta
    ll resContar = 0;
    resContar = fact[largo]; //inicializo con todos los numeros que tenga
    // cout(largo);
    fre(cont){
        resContar /= fact[e.second];
    }
    //si tengo algun 0, resto
    ll restar = 0;
    if (cont['0'] > 0){
        // cout << "tengo 0 asi que resto" << endl;
        restar = fact[largo-1];
        // cout << restar << endl;
        cont['0']--;
        fre(cont){
            // cout << e.second << endl;
            restar /= fact[e.second];
        }
        // cout << "Resto: " << restar << endl;
    }
    return resContar - restar;

}

void solve() {
    ll a; cin >> a;
    ll res = 0;
    facts();
    string original = to_string(a);
    // cout << original << endl;
    for(char c: original){
        cantOriginal[c]++;
    }

    // for(const auto& e: cantOriginal){
    //     cout << e.first << ": " << e.second << endl;
    // }
    // cout << cantOriginal[('7')] << endl;
    // cout << "termino mapa" << endl;

    ll k = to_string(a).size();
    fr(1, 1 << k){
        string subset;
        rep(j,0,k){
            if (i & (1<<j)){
                subset += original[j];
            }
        }
        res += contar(subset);
        // cout << "Ahora res es " << res << endl; 
    }
    cout << res << '\n';
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

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}