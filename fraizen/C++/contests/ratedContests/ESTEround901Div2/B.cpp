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

void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    int maxA= 0;
    int maxB= 0;
    int minA= 1e9+1;
    int minB= 1e9+1;
    ll sumaA = 0;
    ll sumaB = 0;
    fr(0,n){
        cin >> a[i];
        maxA = max(a[i], maxA);
        minA = min(minA, a[i]);
        sumaA += a[i];
    }
    fr(0,m){
        cin >> b[i];
        maxB = max(b[i], maxB);
        minB = min(minB, b[i]);
        sumaB += b[i];
    }
    if (k % 2 == 0){
        // se beneficia el rival, cambio yo y despues cambia el. 
        if (minA >= maxB){ //solo cambia el rival
            cout(sumaA - maxA + minB);
            return;
        } else {
            //cambio yo primero
            fr(0,n){
                if (a[i] == minA){
                    a[i] = maxB;
                    break;
                }
            }
            fr(0,m){
                if (b[i] == maxB){
                    b[i] = minA;
                    break;
                }
            }
            //actualizo las cosas
            maxA= 0;
            maxB= 0;
            minA= 1e9+1;
            minB= 1e9+1;
            sumaA = 0;
            sumaB = 0;
            fr(0,n){
                maxA = max(a[i], maxA);
                minA = min(minA, a[i]);
                sumaA += a[i];
            }
            fr(0,m){
                maxB = max(b[i], maxB);
                minB = min(minB, b[i]);
                sumaB += b[i];
            }
            //cambia el
            cout(sumaA - maxA + minB);
            return;
        }
    } else {
        //cambio una vez si me sirve, sino solo sumo
        if (minA >= maxB){
            cout(sumaA);
            return;
        } else {
            cout(sumaA - minA + maxB);
            return;
        }
    }
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }
}