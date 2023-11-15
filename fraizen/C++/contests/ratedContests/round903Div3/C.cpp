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
#define MAXN 1001

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

char matrix[MAXN][MAXN];

pair<int, int> rotate90(int i, int j, int n, int iter) {
    int newRow;
    int newCol;
    if (iter == 0) {
        newRow = j;
        newCol = n - i - 1;
    } else if (iter == 1){
        newRow = n-1-i;
        newCol = n - 1 -j;
    } else {
        newRow = n-1-j;
        newCol = i;
    }
    return make_pair(newRow, newCol);
}

ll getRes(int i,int j, int n){
    char curMax = matrix[i][j];
    // cout << "Veo " << i << ' ' << j << endl;
    char l[4];
    l[3] = curMax;
    // ver los otros y guardarlos
    // recorrer array y devolver suma
    // la fila indica cuanto sumar
    rep(k,0,3){
        // int pos = (j + n - 2 * i - 1) % (n - 2 * i -1) + i;
        pair<int,int> p = rotate90(i,j, n, k);
        char c;
        c = matrix[p.first][p.second];
        // cout << p.first << ' ' << p.second << endl;
        l[k] = c;
        if (c > curMax){
            curMax = c;
        }
    }
    ll sum = 0;
    fr(0,4){
        sum += (curMax - l[i]);
    }
    // cout << "sumo " << sum << endl;
    return sum;
}

// ll getRes(int i,int j, int n){
//     char curMax = matrix[i][j];
//     char l[4];
//     l[3] = curMax;
//     // ver los otros y guardarlos
//     // recorrer array y devolver suma
//     // la fila indica cuanto sumar
//     fr(0,3){
//         if (i == 0){
//             int pos = (j + n - 2 * i - 1) % (n - 2 * i -1) + i;
//             char c = matrix[pos][n-i];
//             l[i] = c;
//             if (c > curMax){
//                 curMax = c;
//             }
//         } else if (i == 1){
//             // int pos = (j + n - 2 * i - 1) % (n - 2 * i -1) + i;
//             // char c = matrix[n-i][];
//             l[i] = c;
//             if (c > curMax){
//                 curMax = c;
//             }
//         } else if (i == 2){
//             // int pos = (j + n - 2 * i - 1) % (n - 2 * i -1) + i;
//             // char c = matrix[i][];
//             l[i] = c;
//             if (c > curMax){
//                 curMax = c;
//             }
//         }
//     }
//     if (i == j){
//         // es borde
//     } else {
//         if ()
//         matrix[]
//     }
//     return 1;
// }
// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    int res = 0;
    fr(0,n){
        string s; cin >> s;
        rep(j,0,n){
            matrix[i][j] = s[j];
            // cout << matrix[i][j] << ' ';
        }
        // cout(' ');
    }
    fr(0,n){
        rep(j,i,n-i-1){
            // cout << i << ' ' << j << endl;
            res += getRes(i,j, n);
        }
    }
    cout(res);
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
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}