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

#define p 256
string res;
string s;

vi precompute_hashes(const string& s){
    vi hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

bool existe(ll mid,vi hashes,vi potencias, ll largo){
    unordered_map<ll,pair<ll,ll>> m; //guardar cantidad, posicion donde arranca
    // ll hashInicial = hashes[mid];
    // m[hashInicial]=mp(1,0);
    pair<ll, ll> p2;
    fr(0, largo - mid + 1){
        ll curHash = get_hash(hashes, i+1, i+mid, potencias);
        if (m.find(curHash) != m.end()){
            p2 = m[curHash];
            m[curHash] = mp(p2.first + 1, i);
        } else {
            m[curHash] = mp(1LL, i);
        }
    }
    // debug(m);
    // veo si alguno tiene uno y la posicion en donde arranca
    bool hay = false;
    ll posInicial = 10000000;
    for(auto e: m){
        if (e.second.first == 1){
            hay = true;
            posInicial = min(e.second.second, posInicial);
        }
    }
    // debug(mid);
    // debug(hay);
    if (hay){
        res = s.substr(posInicial, mid);
        return true;
    } else {
        return false;
    }
}

void solve() {
    cin >> s;
    vi hashes = precompute_hashes(s);
    vi potencias(s.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < s.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }
    // debug(hashes);

    res = s;
    ll left = 1;
    ll right = s.size();
    while (left <= right){
        ll mid = (left) + (right-left) /2;
        if (existe(mid, hashes, potencias,s.size())){
            right = mid -1;
        } else {
            left = mid + 1;
        }
    }
    cout << res;
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }
}