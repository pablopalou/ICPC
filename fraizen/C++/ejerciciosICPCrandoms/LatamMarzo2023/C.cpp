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

ll potencias[61];

void precomputar(){
    potencias[0] = 1;
    fr(1,61){
        potencias[i] = potencias[i-1] * 2;
    }
}

// Copiar obligatoriamente 0
void solve() {
    ll n, p, h;
    cin >> n >> p >> h;
    precomputar();
    ll altura[n+1];
    altura[0] = 1; // no existe
    // altura[1] = 1;
    altura[n] = h;
    // fr(0,n+1){
    //     cout << potencias[i] << ' ';
    // }
    // cout(' ');
    for(ll i = n-1; i >= 1; i--){
        if (altura[i+1] > potencias[i]){ // quiere decir que subi
            altura[i] = potencias[i+1] + 1 - altura[i+1];
        } else { // la altura quedo como estaba
            altura[i] = altura[i+1];
        }
    }
    // fr(0,n+1){
    //     cout << altura[i] << ' ';
    // }
    // cout(' ');
    ll pos = p;
    //actualizar pos
    fr(1,n+1){
        // debug(potencias[n-i]);
        // debug(pos);
        if (pos <= potencias[n-i]){ //estoy a la izquierda
            if (altura[i-1] == altura[i]){ //me tengo que quedar como estoy, giro la otra parte
                cout << "R";
            } else {
                cout << "L";
                pos = potencias[n-i] + 1 - pos;
            }
        } else { // estoy a la derecha
            if (altura[i-1] == altura[i]){
                cout << "L";
                pos -= potencias[n-i];
            } else {
                cout << "R";
                pos = potencias[n-i+1] + 1 - pos;
            }
        }
    }
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}