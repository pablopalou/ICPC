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

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    int a[n];
    fr(0,n){
        cin >> a[i];
    }
    map<int,set<int>> m;
    fr(0,n){
        m[a[i]].insert(i);
    }
    //recorro mapa y pregunto el size.
    int rep = 0;
    for ( auto it = m.begin(); it != m.end(); ++it  )
    {
        if (it->second.size() > 1){
            rep++;
        }
    }
    if (rep < 2){
        cout << -1 << "\n";
        return;
    }
    //hay mas de 2 repetidos. a la primer pareja le pongo 1,2 y a la siguiente 1,3, al resto todo 1 y fue.
    int res[n];
    fr(0,n){
        res[i] = 0;
    }
    int parejas = 0;
    for ( auto it = m.begin(); it != m.end(); ++it  )
    {
        if (it->second.size() > 1){
            if (parejas == 0){
                parejas++;
                res[*(it->second.begin())] = 2;
            } else if ( parejas == 1){
                res[*(it->second.begin())] = 3;
                break;
            }
        }
    }
    fr(0,n){
        if (res[i] != 0 ){
            cout << res[i] << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
    cout << "\n";
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