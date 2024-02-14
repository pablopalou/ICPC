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
const ll MAXN = 2e5+10;
ll a[MAXN];
ll n,b,x;
ll gauss(ll x){
    return ll(((x)*(x+1)) / ll(2));
}

ll valor(ll cant){
    // cout << "Pruebo cajas = " << cant << endl;
    ll res = 0;
    //tengo que dividir en cant cajas.
    //para cada valor hago la cuenta
    fr(0,n){
        //separo y sumo cada valor
        ll div = a[i] / cant; //cuantos entran enteros...
        ll sobran = a[i] % cant; //cant cajas con div+1
        //cantidad de cajas con div
        ll cajasDiv = cant - sobran;
        // cur += div * cajasDiv;
        if (cajasDiv > 1){
            //sumo el cajasDiv digamos...
            //saco una caja pa afuera y hago gauss del 1 a cajasDiv
            // cout << "Sumo => " << ((div) * (gauss(cajasDiv-1))) * b << endl;
            res += ((div*div) * (gauss(cajasDiv-1))) * b;
        }
        if (sobran > 1){
            // cout << "Sumo. => " <<((div+1)*(div+1) * gauss(sobran-1)) * b <<endl;
            res += ((div+1)*(div+1) * gauss(sobran-1)) * b;
        }
        // cout << "Sumop.. => "<<(((div * cajasDiv )* (sobran * (div+1))) * b) <<endl;
        res += (((div * cajasDiv )* (sobran * (div+1))) * b);
    }
    // resto cant-1 * x
    res -= ((cant-1) * x);
    //retorno
    // debug(res);
    return res;
}
// Copiar obligatoriamente 0
void solve() {
    int probe[MAXN];
    cin >> n >>b>>x;
    ll maximo = 0;
    fr(0,n){
        cin >> a[i];
        maximo = max(maximo, a[i]);
    }
    //hago ternaria xq supongo que la funcion sube y baja. Parabola invertida
    ll l = 1;
    ll r = maximo+1;
    ll ans = 0;
    while(r-l >= 3){
        ll m1 = l + (r-l)/3; ll m2 = r - (r-l)/3;
        ll valm1 = valor(m1);
        ll valm2 = valor(m2);
        if (valm1 <= valm2){
            l = m1;
        } else {
            r = m2;
        }
        ans = max(ans, max(valm1, valm2));
    }
    //pruebo los valores que quedan supongo e imprimo...
    rep(i,l, l+4){
        ans = max(ans, valor(i));
    }
    cout << ans << "\n";
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