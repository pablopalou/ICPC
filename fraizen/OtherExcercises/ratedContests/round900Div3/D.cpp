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

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pii> revertir;
    int l[k+1];
    int r[k+1];
    l[0] = 0;
    r[0] = 0;
    fr(1,k+1){
        int a;
        cin >> a;
        l[i] = a;
    }
    fr(1,k+1){
        int b;
        cin >> b;
        r[i] = b;
    }
    int q;
    cin >> q;
    fr(0,q){
        int query;
        cin >> query;
        //handleo la query, busco en log n, guarrdo en reverse
        auto it = lower_bound(l, l+k+1, query);
        int index = it - l;
        int h = min(query, r[index] + l[index] - query);
        int fraizen = max(query, r[index] + l[index] - query);
        revertir.pb(mp(h-1, fraizen-1));
    }
    //hago los revert necesarios
    // debug(s);
    fr(0,revertir.size()){
        pair<ll,ll> p = revertir[i];
        debug(p);
        reverse(s.begin() + p.ff, s.begin() + p.ss + 1);
    }
    cout(s);
    //imprimo



    // fr(0,k+1){
    //     cout << r[i] << ' ';
    // }
    // cout(' ');
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}