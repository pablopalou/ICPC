//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
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
void solve() {
    ll n; cin >> n;
    ll inicio[n];
    ll fin[n];
    fr(0, n) {
        ll ini, fi; cin >> ini >> fi;
        inicio[i] = ini;
        fin[i] = fi;
    }
    ll p; cin >> p;
    ll pos_p[p];
    fr(0, p) {
        ll x; cin >> x;
        pos_p[i] = x;
    }

    ll cant_p[n];
    ll p_act = 0;
    ll r_act = 0;
    fr(0, n) {
        cant_p[i] = 0;
    }
    while(p_act < p && r_act < n) {
        if (inicio[r_act] > pos_p[p_act]) {
            p_act += 1;
            continue;
        }
        if (inicio[r_act] <= pos_p[p_act] && pos_p[p_act] <= fin[r_act]) {
            cant_p[r_act] += 1;
            if (pos_p[p_act] < fin[r_act]) {
                p_act += 1;
                continue;
            } else {
                r_act += 1;
                continue;
            }
        }
        if(fin[r_act] < pos_p[p_act]) {
            r_act += 1;
            continue;
        }
    }

    fr(0,n){
        // cout << cant_p[i] << ' ';
        if (cant_p[i] > 2){
            cout("impossible");
            return;
        }
    }
    // cout(' ');
    vi res;
    fr(0,n-1){
        auto it = lower_bound(pos_p, pos_p+p, fin[i]);
        if (fin[i] == inicio[i+1] && cant_p[i] < 2 && cant_p[i+1] < 2 && (*it != fin[i] || p == 0)){
            res.pb(fin[i]);
            cant_p[i]++;
            cant_p[i+1]++;
        }
    }

    fr(0,n){
        if (cant_p[i] == 0){
            res.pb(inicio[i] + 1);
            res.pb(inicio[i] + 2);
        } else if (cant_p[i] == 1){
            auto it = lower_bound(pos_p, pos_p+p, inicio[i] + 1);
            if ( *it == inicio[i] + 1){
                res.pb(inicio[i] + 2);
            } else {
                res.pb(inicio[i] + 1);
            }
        }
    }

    cout << res.size() << "\n";
    fr(0, res.size()){
        cout << res[i] << ' ';
    }

    // r_act = 0;
    // vi res;
    // while(r_act < n) {
    //     if (cant_p[r_act] > 2) {
    //         cout("impossible");
    //         return;
    //     } else if (cant_p[r_act] == 2) {
    //         r_act += 1;
    //     } else {
    //         if (r_act < n-1 && fin[r_act] == inicio[r_act+1]) {
    //             if (cant_p[r_act+1] == 1) {
    //                 res.pb(fin[r_act]);
    //                 cant_p[r_act+1] += 1;
    //             } else {
                    
    //             }
    //         } else {

    //         }
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

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}