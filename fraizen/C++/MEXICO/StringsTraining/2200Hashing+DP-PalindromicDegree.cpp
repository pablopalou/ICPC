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

vector<ll> precompute_reverse_hashes(const string& s){
    vector<ll> reverse_hashes(s.size() + 1, 0);
    ll reverse_hash = 0;
    for (ll i = s.size() - 1; i >= 0; i--) {
        reverse_hash = (reverse_hash * p + s[i]) % mod;
        reverse_hashes[s.size() - i] = reverse_hash;
    }
    return reverse_hashes;
}

ll get_hash(const vector<ll>& hashes, ll l, ll r, const vector<ll>& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

bool isPalindrome(const vector<ll>& hashes,const vector<ll>& reverse_hashes,ll i,ll j, const vector<ll>& potencias){
    ll pre = get_hash(hashes, i+1, j+1, potencias);
    ll suf = get_hash(reverse_hashes, n - j, n -i, potencias);
    return pre == suf;
}

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    n = s.size();
    vector<ll> hashes = precompute_hashes(s);
    vector<ll> reverse_hashes = precompute_reverse_hashes(s);

    vector<ll> potencias(s.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < s.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }

    int dp[n+1];
    fill(dp, dp+n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    fr(2,n+1){
        // cout << "i = " <<i << endl;
        if (dp[i/2] == 0){
            if (isPalindrome(hashes, reverse_hashes,0,i-1, potencias)){
                dp[i] = 1;
            }
            continue;
        }
        if (i % 2== 0){
            if (get_hash(hashes, 1, i/2, potencias) == get_hash(hashes, i/2+1, i, potencias)){
                dp[i] = dp[i/2] + 1;
            }
        } else {
            // cout << get_hash(hashes, 1, i/2, potencias) << endl;
            // cout << get_hash(hashes, (i+1)/2 + 1, i, potencias) << endl;
            if (get_hash(hashes, 1, i/2, potencias) == get_hash(hashes, (i+1)/2 + 1, i, potencias)){
                dp[i] = dp[i/2] + 1;
                // cout << "acutalizo dp con " << dp[i/2] + 1 << endl;
            }
        }
    }
    // fr(0,n+1){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << accumulate(dp, dp+n+1, 0) << "\n";

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