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
    int n; cin >> n;
    bool tablero[11][11];
    fr(0,11){
        rep(j,0,11){
            tablero[i][j] = false;
        }
    }
    fr(0,n){
        int d,l,r,c;
        cin >> d >> l >> r >> c;
        if (d == 0){ // HORIZONTAL
            // empiezo en r,c voy hasta r,c+l-1
            if ( r >= 11 || r <= 0 || c <= 0 || c >= 11 || c+l-1 >= 11 || c+l-1 <= 0 || c+l-1 <= 0 || c+l-1 >= 11){
                cout("N");
                return;
            }
            rep(j, c, c+l){
                if (tablero[r][j]){
                    cout("N");
                    return;
                }
                tablero[r][j] = true;
            }
        } else { //VERTICAL
            // empiezo en r,c voy hasta r+l-1,c
            if ( r >= 11 || r <= 0 || c <= 0 || c >= 11 ||  r+l-1 >= 11 ||  r+l-1 <= 0 ||  r+l-1 <= 0 ||  r+l-1 >= 11){
                cout("N");
                return;
            }
            rep(j, r, r+l){
                if (tablero[j][c]){
                    cout("N");
                    return;
                }
                tablero[j][c] = true;
            }
        }
    }
    cout("Y");
    return;
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}