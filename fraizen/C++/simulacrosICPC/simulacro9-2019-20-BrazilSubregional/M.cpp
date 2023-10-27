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

bool valid(ll mid, ll a[], ll n, ll c, ll t){
    int i = 0;
    int pers = 1;
    while( pers <= c && i < n){
        ll cur = 0;
        while ((cur + a[i]) <= (mid * t)){
            cur += a[i];
            i++;
        }
        pers++;
    }
    if (i == n){
        return true;
    } else {
        return false;
    }
}

// Copiar obligatoriamente 0
void solve() {
    ll n,c,t; cin >> n >> c >> t;
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    ll suma = 0;
    ll maximo = 0;
    fr(0,n){
        suma += a[i];
        maximo = max(a[i], maximo);
    }
    ll l = max(ll(ceil(maximo/double(t))) - 1, ll(0));
    ll r = ll(ceil(suma/double(t))) + 1;
    // cout(ll(ceil(suma/t)));
    ll res = r;
    // cout(l);
    // cout(r);
    // cout('a');
    while (l <= r){
        ll mid = l + (r-l) / 2;
        // cout << "mid:" << mid << endl;
        // cout << valid(mid, a, n,c,t) << endl;
        if (valid(mid, a, n,c,t)){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << res << "\n";
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("M.in", "r", stdin);
    // freopen("M.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}