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

ll dp[100005][201];

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    if (a[0] > a[n-1]){
        reverse(a,a+n);
    }
    bool todoMenos1 = true;
    fr(0,n){
        if (a[i] != -1) {
            todoMenos1 = false;
        };
    }
    if (todoMenos1){
        cout << "200";
        return;
    }
    if (n == 2){
        if (a[0] == -1 && a[1] == -1){
            cout << 200 << '\n';
            return;
        } else if (a[0] == -1 || a[1] == -1){
            cout << 1 << '\n';
            return;
        }
    }
    if (a[n-2] == -1){
        a[n-2] = a[n-1];
    }
    fr(0,100005){
        rep(j,0,202){
            dp[i][j] = 0;
        }
    }
    ll last2 = 0;
    ll ant[n];
    fr(0, n) {
        ant[i] = 1;
    }
    bool ini2 = false;
    fr(0, n) {
        if (!ini2 && a[i] != -1) {
            ini2 = true;
            last2 = a[i];
            continue;
        }
        if (a[i] != -1) {
            ant[i] = last2;
            last2 = a[i];
        } else {
            ant[i] = last2;
        }
    }

    fr(0,n){
        if (i == 0){
            if (a[i] == -1){
                rep(j,ant[i], 201){
                    dp[i][j] = 1;
                }
            } else {
                dp[i][a[i]] = 1;
            }
        } else {
            if (a[i] == -1){
                // rep(j,ant[i], 201){
                // cout << "anterior " << ant[2] << endl;
                dp[i][ant[i]] = dp[i-1][ant[i]];
                rep(j, ant[i]+1, 201){
                    dp[i][j] = dp[i][j-1];
                }
                rep(j, ant[i]+1,201){
                    dp[i][j] = (dp[i][j] % mod1 + dp[i-1][j] % mod1) % mod1;
                }
                // rep(j, ant[i], 201){
                //     dp[i][j] += dp[i][j-1] j-2 j-3;
                // }
            } else { //tengo un numero fijo, asi que agarro la suma de los anteriores
                rep(j, 1,a[i]+1){
                    // cout << "sumo " << dp[i-1][j] << endl;
                    dp[i][a[i]] = (dp[i][a[i]] % mod1 + dp[i-1][j] % mod1) % mod1;
                }
            }
        }
    }

    fr(0,n){
        rep(j, 0, 10){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    //si ultimo es -1 sumar toda la columna sino retornar valor de dp.
    ll res = 0;
    if (a[n-1] == -1){
        rep(j, ant[n-1], 201){
            res = (res % mod1 +  dp[n-1][j] % mod1) % mod1;
        }
        cout << res <<'\n';
    } else {
        cout << dp[n-1][a[n-1]] << '\n';
    }

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

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}