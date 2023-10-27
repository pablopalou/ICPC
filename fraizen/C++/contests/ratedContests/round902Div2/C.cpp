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

void solve() {
    ll n,m,k; cin >> n >> m >> k;
    if (k > 3){
        cout(0);
        return;
    } else if (k == 1){
        cout(1);
        return;
    }
    // me queda ver caso k == 2 y k == 3;
    //tenemos que contar todos los casos desde 1 hasta m (esos son los valores posibles de m que pueden dar 2 o 3)
    ll cant2 = 0;
    ll cant3 = 0;
    if (m <= n){
        cant2 = m;
        if (k == 3){
            cout(0);
            return;
        } else {
            cout(cant2);
            return;
        }
    } else {
        cant2 = n; //sabemos que tenemos las primeras m posibilidades que dan 2
        // debug(cant2);
        // falta ver desde m+1 en adelante.
        cant2 += m/n - 1;
        // debug(cant2);
        cant3 = m - cant2 ;
        // debug(cant3);
        if (k == 2){
            cout(cant2);
            return;
        } else {
            cout(cant3);
            return;
        }
    }


    // if (m == 0){
    //     if (k == 1){
    //         cout(1);
    //         return;
    //     } else {
    //         cout(0);
    //         return;
    //     }
    // }

    // if (m <= k){

    // } else {

    // }
    // if (n == m && n >= 2){
    //     if (k == 1){
    //         cout(1);
    //         return;
    //     } else if (k == 2) {
    //         cout(m-1);
    //         return;
    //     }
    // }

}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    ll cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}