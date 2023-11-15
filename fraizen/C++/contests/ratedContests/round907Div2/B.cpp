//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
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


//DA TLE
ll ultBit(ll n)
{
    if (n == 0)
        return 0;
    // Position variable initialize with 1
    // m variable is used to check the set bit
    ll position = 1;
    ll m = 1;
 
    while (!(n & m)) {
 
        // left shift
        m = m << 1;
        position++;
    }
    return position;
}

// Copiar obligatoriamente 0

void solve() {
    //guardar parejas en un vector teniendo (ultI, pos)
    ll n,cantQueries; cin >> n >> cantQueries;
    ll a[n];
    ll q[cantQueries];
    fr(0,n){
        cin >> a[i];
    }
    fr(0,cantQueries){
        cin >> q[i];
    }
    vector<pair<ll,ll>> v;
    fr(0,n){
        v.push_back(mp(ultBit(a[i]),i));
    }
    sort(v.begin(), v.end()); // Sort the vector

    fr(0,cantQueries){
        auto it = lower_bound(v.begin(), v.end(), mp(q[i]+1,-1LL));
        vector<pair<ll, ll>> to_insert;
        while(it != v.end()){
            pair<ll,ll> p = *it;
            ll pos = p.second;
            ll sumar = (1 << (q[i]-1));
            a[pos] += sumar;
            // cout << "SUMO " << sumar << " A " << pos;
            // Store the updated elements to insert later
            to_insert.push_back(mp(q[i], pos));
            it = v.erase(it);
        }
        // Insert the updated elements back into the vector
        for (const auto& p : to_insert) {
            it = lower_bound(v.begin(), v.end(), p);
            v.insert(it, p);
        }
    }
    fr(0,n){
        cout << a[i] << ' ';
    }
    cout << "\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}