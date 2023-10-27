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

const int N = 555;
long double fac[N];

long double binom(int n, int k) {
	if (k > n) return 0;
	return fac[n] / fac[k] / fac[n-k];
}

long double bin(int n, int k) {
    if (k > n) return 0;

    long double res = 1.0;
    rep(i,1,k+1) {
        res = res * (n - (k - i)) / i;
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    int k; int n; cin >> n >> k;
    long double a[n];
    fr(0,n){
        cin >> a[i];
    }

    if (k == 1){
        fr(0,n){
            cout << fixed << setprecision(10) << (1.0/n) * 100 << ' ';
        }
        return;
    }

	fac[0] = 1;
	for (int n = 1; n < N; n++) {
		fac[n] = fac[n-1] * n;
	}
    // cout << n << ' ' << k << endl; 
    // cout << fixed << setprecision(7) << binom(n,k) << endl;
    rep(pos, 0,n){
        long double res = 0.0;
        long double suma = 0.0;
        fr(0,n-k+1){
            suma += a[(((pos - i)%n) + n) % n];
            res += (suma / 100) * (binom(n-i-2, k-2) / binom(n,k));
            // cout << res << ' ';
        }
        cout << fixed << setprecision(10) << res * 100 << ' ';
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();

    return 0;
}