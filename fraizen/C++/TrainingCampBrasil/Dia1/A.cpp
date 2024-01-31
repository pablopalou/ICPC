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
long long dp[101][4];
long long mayorAnterior(long long j){
    long long res = 0;
    fr(0,4){
        res = max(res, dp[j-1][i]);
    }
    return res;
}

long long numero(string a, string b, long long i){
    if (a[i] == 'X' && b[i] == 'X'){
        return 3;
    } else if (a[i] == 'X' && b[i] == '0'){
        return 2;
    } else if (a[i] == '0' && b[i] == 'X'){
        return 1;
    } else {
        return 0;
    }
}

// Copiar obligatoriamente 0
void solve() {
    string a, b;
    cin >> a >> b;
    if (a.size() <= 1){
        cout << '0' << '\n';
        return;
    }
    fr(0,101){
        rep(j,0,4){
            dp[i][j] = -inf;
        }
    }
    dp[0][numero(a,b,0)] = 0;
    fr(1, a.size() + 1){
        ll antes = mayorAnterior(i);
        if (numero(a,b,i) == 3){
            dp[i][3] = antes;
        } else if (numero(a,b,i) == 2){
            dp[i][3] = max(antes, dp[i-1][0] +1);
            dp[i][2] = antes;
        } else if (numero(a,b,i) == 1){
            dp[i][3] = max(antes, dp[i-1][0] + 1);
            dp[i][1] = antes;
        } else {
            dp[i][0] = antes;
            dp[i][1] = max(antes, dp[i-1][0] + 1);
            dp[i][2] = max(antes, dp[i-1][0] + 1);
            dp[i][3] = max(max(antes, dp[i-1][1] + 1), dp[i-1][2] + 1);
        }
    }
    ll res = 0;
    fr(0,4){
        res = max(res, dp[a.size()-1][i]);
    }
    // fr(0,4){
    //     rep(j,0,4){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << res << '\n';
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