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

// NO FUNCIONA
// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    ll nums[n];
    fr(0,n){
        cin >> nums[i];
    }

    int last = nums[n-1];  // Initialize 'last' with the last element
    long long ans = 0;     // Initialize the total operations count

    // Traverse the array in reverse order
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] > last) {  // If the current element needs replacement
            int t = nums[i] / last;  // Calculate how many times the element needs to be divided
            if (nums[i] % last) t++; // If there's a remainder, increment 't'
            last = nums[i] / t;  // Update 'last' for the next comparison
            ans += t - 1; // Add (t - 1) to 'ans' for the number of operations
        } else {
            last = nums[i]; // Update 'last' without replacement
        }
    }
    cout(ans);
    return;

    // DE ACA PA ABAJO DEBERIA FUNCIONAR PERO NO FUNCIONA
    // ll res = 0;

    // //chequeo si todo esta joya
    // bool joya = true;
    // fr(1,n){
    //     if (a[i] < a[i-1]){
    //         joya =false;
    //     }
    // }
    // if (joya){
    //     cout(0);
    //     return;
    // }

    // //divido. Si me da un numero redondo golazo.
    // // Si da un numero mayor a 2, entonces sumo algo.
    // // Voy descartando de a multiplos hasta quedar con una division del estilo 1,7 o algo asi. 
    // //Ahi llento repartir lo mas parejo posible.
    // //Si la division no llega 1, tambien toy sobrado.
    // ll cur = a[n-1];
    // for(ll i = n-2; i>=0; i--){
    //     if(a[i] <= cur){
    //         continue;
    //     }
    //     //a[i] > cur
    //     if (a[i] % cur == 0){ // numero redondo
    //         res += (a[i]/cur -1LL); //el cur sigue siendo el mismo
    //         continue;
    //     } else { //tengo resto
    //         if ( a[i]/cur >= 2LL){ //tengo mayor a dos, asi que tengo que ir sacando...
    //             ll div = a[i]/cur;
    //             res += div-1LL;
    //             //me quedo solo con el 1,algo.
    //             a[i] = a[i] - (div-1LL) * cur;
    //         }
    //         //sigo aca con el 1,algo
    //         if (a[i] <= cur){
    //             continue;
    //         }
    //         res++;
    //         //a[i] > cur y es 1,algo
    //         if (a[i] % 2 == 0){ // si es par, mitad y mitad
    //             cur = a[i] / 2LL;
    //         } else {
    //             cur = (a[i]-1LL)/2LL;
    //         }
    //     }
    // }
    // cout(res);
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}