#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

typedef long double T;
typedef long double ld;
const T EPS = 1e-9;
const T INF = 1e18;
struct pto{
    T x,y;
    pto() : x(0),  y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator-(pto b ){ return pto(x-b.x, y-b.y);}
    pto operator+(pto b ){ return pto(x+b.x, y+b.y);}
    pto operator*(T k) { return pto(x*k,y*k);}
    pto operator/(T k) { return pto(x/k,y/k);}
    T operator*(pto(b)) { return x*b.x + y*b.y;}
    ld norm() { return sqrtl(x*x + y*y);}
    ld dist(pto b) { return (b - (*this)).norm();}
    T norm_sq(){return x*x + y * y;}
};

// Copiar obligatoriamente 0
void solve() {
    int n;
    int x[3*n], y[3*n];
    pto puntos[3*n];
    fr(0,3*n){
        cin >> x[i] >> y[i];
        puntos[i] = pto(x,y);
    }

    do{

    }while(next_permutation(p.begin(), p.end()));
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}