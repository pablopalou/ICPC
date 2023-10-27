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
#define prDouble(x) cout << fixed << setprecision(10) << x << "\n";
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
long double distance(ld x1, ld y1, ld x2, ld y2) 
{ 
    return sqrtl(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
} 

// tengo que ver que 0,0 este dentro de un circulo
// que px,py este dentro de un circulo
// si estan en distintos circulos, que los circulos se toquen.
bool hayCamino(ld radio, ld distancia, ld px, ld py, ld ax, ld ay, ld bx, ld by){
    if ( distance(0.0,0.0, ax,ay) < radio){ //0,0 adentro del primer circulo
        if (distance(px,py, ax, ay) < radio){ //px,py adentro del primer circulo
            return true;
        } else { //px,py afuera del primer circulo
            if (distance(px,py, bx, by) < radio){ // px, py adentro del segundo circulo
                // me tengo que fijar si se conectan los circulos
                return (radio * 2.0 >=distance(ax,ay,bx,by));
            } else {
                return false; //px,py afuera de ambos circulos
            }
        }
    } else { //0,0 afuera del primer circulo
        if (distance(px,py, ax, ay) < radio){ //px,py adentro del primer circulo
            if (distance(0.0,0.0, bx, by) < radio){ // 0,0 adentro del segundo circulo
                // me tengo que fijar si se conectan los circulos
                return (radio * 2.0 >=distance(ax,ay,bx,by));
            } else {
                return false; //0,0 afuera de ambos circulos
            }
        } else { //px,py afuera del primer circulo (la unica opcion es que esten ambos en el 2)
            return (distance(0.0,0.0, bx,by) < radio && distance(px,py, bx,by) < radio);
        }
    }
}

void solve() {
    ld px,py; cin >> px >> py;
    ld ax,ay; cin >> ax >> ay;
    ld bx,by; cin >> bx >> by;
    //binario en float
    ld distancia = distance(0.0,0.0,px,py);
    ld left = 0.0;
    ld right = 4000.0;
    ld res = right;
    ld epsilon = 1e-14;
    while (right - left > epsilon){
        ld mid = left + (right - left) / 2.0;
        // debug(mid);
        if (hayCamino(mid, distancia, px,py, ax, ay, bx,by)){
            res = mid;
            right = mid - epsilon;
        } else {
            left = mid + epsilon;
            
        }
    }
    prDouble(res);
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

    return 0;
}