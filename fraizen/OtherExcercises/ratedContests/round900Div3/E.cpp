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
    int n;
    cin >> n;
    int prefix[n+1][32];
    int arr[n+1];
    fr(1,n+1){
        cin >> arr[i];
    }
    //precomputo
    fr(0,n+1){
        rep(j,0,32){
            prefix[i][j] = 0;
        }
    }
    fr(1,n+1){
        //agarramos el numero arr[i] y le sumamos lo que ya teniamos. 
        int number = arr[i];
        int pos = 0;
        rep(j,0,32){
            prefix[i][j] = prefix[i-1][j];
        }
        while(number > 0){
            if (number & 1){
                prefix[i][pos]++;
            }
            pos++;
            number/=2;
        }
    }

    // la matriz de prefijos queda pro.
    // fr(0,n+1){
    //     rep(j,0,32){
    //         cout << prefix[i][j] << ' ';
    //     }
    //     cout(' ');
    // }

    int q;
    cin >> q;
    fr(0,q){
        int a,b;
        cin >> a >> b;
        if (arr[a] < b){
            cout << "-1 ";
            continue;
        }
        int left = a;
        int right = n;
        int numero;
        int valid = -1;
        while(left <= right){
            // debug(left);
            // debug(right);
            int med = left + (right - left) / 2;
            int arrMed[32];
            // debug(med);
            // debug(a);
            rep(j,0,32){
                arrMed[j] = prefix[med][j] - prefix[a-1][j];
            }
            // rep(j,0,32){
            //     cout << arrMed[j] << ' ';
            // }
            numero = 0;
            rep(j,0,32){
                if (arrMed[j] == med - a + 1){
                    numero |= (1 << j); 
                }
            }
            // debug(numero);
            if (numero >= b){
                valid = max(med,valid);
                // debug(valid);
                left = med+1;
            } else {
                right = med-1;
            }
        }
        cout << valid << ' ';
    }
    cout << "\n";
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