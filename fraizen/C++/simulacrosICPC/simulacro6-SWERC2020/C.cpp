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
#define prDouble(x) cout << fixed << setprecision(6) << x
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

class UnionFind { // OOP style
    private: vi p, rank; // remember: vi is vector<int>
    public:
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) p[i] = i; 
        }
        
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
            } 
        } 
};

ld res;

bool hayCamino(ld mid, tuple<ld, ld>* puntos, ll n,ld x, ld y){
    UnionFind u(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++){
            ld x1 = get<0>(puntos[i]);
            ld y1 = get<1>(puntos[i]);
            ld x2 = get<0>(puntos[j]);
            ld y2 = get<1>(puntos[j]);
            if (sqrt(((x2 - x1) * ((x2 - x1)) + (y2 - y1) * (y2 - y1))) < (mid * 2.0)){
                // cout << "Uno " << "(" << x1 << ',' << y1 << ") con (" << x2 << ',' << y2 << ')' << endl;
                u.unionSet(i,j);
            }
            // cout << "(" << get<0>(puntos[i]) << ", " << get<1>(puntos[i]) << ")" << endl;
        }
    }
    map<int, set<tuple<ld,ld>>> component_points;
    for (int i = 0; i < n; i++) {
        int component_rep = u.findSet(i);
        component_points[component_rep].insert(puntos[i]);
    }
    
    //chequeo las componentes y si alguna intersecta el NW o el SE retorno false
    for (auto component: component_points){
        int component_rep = component.first;
        // cout << component_rep << endl;
        set<tuple<ld,ld>> points = component.second;
        bool tocaWN = false;
        bool tocaSE = false;
        for(auto point: points){
            //actualizar si tocaWN y tocaSE
            ld x1 = get<0>(point);
            ld y1 = get<1>(point);
            // cout << "Punto (" << x1 << ',' << y1 << ")" << endl;
            if (x1 - mid <= 0){
                tocaWN = true;
            }
            if (y1 - mid <= 0){
                tocaSE = true;
            }
            if (x1 + mid >= x){
                tocaSE = true;
            }
            if (y1 + mid >= y){
                tocaWN = true;
            }
            // debug(tocaSE);
            // debug(tocaWN);
            if (tocaWN && tocaSE){
                // cout << "retorno false";
                return false;
            }
        }
    }

    return true;
}

void solve() {
    ld x,y; cin >> x >> y;
    int n; cin >> n;
    tuple<ld,ld> puntos[n]; 
    fr(0,n){
        ld x1,y1; cin >> x1 >> y1;
        puntos[i] = {x1,y1};
        if (x1 == x && y1 == y || x1 == 0.0 && y1 == 0.0){
            prDouble(0.0);
            return;
        }
    }
    ld left = 0.0;
    ld right = x + y;
    res = right;
    ld epsilon = 1e-14;
    while (right - left > epsilon){
        ld mid = left + (right - left) / 2.0;
        // debug(mid);
        if (hayCamino(mid, puntos, n, x, y)){
            res = mid;
            left = mid + epsilon;
        } else {
            right = mid - epsilon;
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
    // cin >> cases;
    while(cases--){
        solve();
    }
}