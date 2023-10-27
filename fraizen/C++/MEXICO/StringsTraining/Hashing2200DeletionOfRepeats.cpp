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
#define p 256
int n;
 
vector<ll> precompute_hashes(const string& s){
    vector<ll> hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}
 
ll get_hash(const vector<ll>& hashes, ll l, ll r, const vector<ll>& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}
 
// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    string s;
    map<int, vector<int>> pos;
    int num[n];
    int largo[n];
    int prefixLargo[n+1];
    prefixLargo[0] = 0;
    fr(0,n){
        int a; cin >> a;
        pos[a].pb(i);
        num[i] = a;
        largo[i] = to_string(a).size();
        prefixLargo[i+1] = prefixLargo[i] + largo[i];
        //agregar una barra separadora xq sino no voy a poder diferenciar 572 3 de 57 23 por ejemplo (al final esto no importaba ni idea)
        s.append(to_string(a));
    }
    vector<ll> hashes = precompute_hashes(s);
 
    vector<ll> potencias(s.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < s.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }
 
    int cur = 0;
    int ult = 0;
    int nroActual = 0;
    while (nroActual < n){
        auto it = upper_bound(pos[num[nroActual]].begin(),pos[num[nroActual]].end(),nroActual);
        if (it != pos[num[nroActual]].end()){
            cur = prefixLargo[nroActual];
            int posFinal = prefixLargo[*(it--)];
            if (posFinal + 1 < hashes.size() && posFinal + (posFinal - cur) < hashes.size() && get_hash(hashes, cur+1, posFinal, potencias) == get_hash(hashes, posFinal + 1, posFinal + (posFinal-cur), potencias)){
                nroActual = lower_bound(prefixLargo, prefixLargo + n + 1, posFinal + 1) - prefixLargo - 1;
                ult = lower_bound(prefixLargo, prefixLargo + n + 1, posFinal) - prefixLargo;
            } else {
                nroActual++;
            }
        } else {
            nroActual++;
        }
    }
 
    cout << n-ult << "\n";
    fr(ult, n){
        rep(j,0,largo[i]){
            cout << s[prefixLargo[i] + j];
        }
        cout << ' ';
    }
}
 
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
