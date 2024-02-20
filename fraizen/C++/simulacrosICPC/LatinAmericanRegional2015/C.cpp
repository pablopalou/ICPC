#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)

typedef long long T; // double could be faster but less precise

struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b){ return pto(x+b.x, y+b.y); }
	pto operator-(pto b){ return pto(x-b.x, y-b.y); }
	pto operator+(T k){ return pto(x+k, y+k); }
	pto operator*(T k){ return pto(x*k, y*k); }
	pto operator/(T k){ return pto(x/k, y/k); }
	// dot product
	T operator*(pto b){ return x*b.x+y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b){ return x*b.y-y*b.x; }
};
ll n;
ll ac[200005];
pto p[100005];
ll area;

ll f(ll i, ll j){ //devuelve el maximo valor de uno de los pedazos
    //calculo area en O(1)
    ll areaActual = ac[j-1];
    if (i>0) areaActual-=ac[i-1];
    ll pedazo1 = llabs(areaActual + (p[j%n]^p[i%n]));
    //retorno maximo de los pedazos
    return max(pedazo1, area-pedazo1);
}
// Copiar obligatoriamente 0
void solve() {
    while(cin>>n){
        fr(0,n){
            cin >> p[i].x >> p[i].y;
        }
        area =0;
        fr(0,n){
            area += p[i]^p[(i+1)%n];
        }
        area = llabs(area);
        //tengo que tener el acumulado...
        fr(0,2*n){
            ac[i] = p[i%n]^p[(i+1)%n];
            if (i>0) ac[i] += ac[i-1];
        }
        ll ans = 0;
        //desde cada uno tengo que sacar una ternaria
        fr(0,n){
            ll l = i;
            ll h = i + n -1;
            int k = 0;
            while(k < 30 && h-l >= 2){
                k++;
                // ll m1 = (2*l+h)/3;
                // ll m2=(l+2*h)/3;
                ll m1 = l + (h-l)/3;
                ll m2 = h - (h-l)/3;
                // cout << "m1 = " << m1 << ' ';
                // cout << "m2 = " << m2 << '\n';
                if (f(i,m1) < f(i,m2)){
                    h = m2;
                } else {
                    l = m1;
                }
            }
            ll cur = 1ll<<60; //diferencia infinita
            //me quedo con el minimo de las areas digamos
            for(int j = l; j<=h; j++){
                cur = min(cur, f(i,j));
            }
            // cout << "i = " << i << endl;
            // cout << "cur = " << cur << endl;
            ans = max(ans, cur);
        }
        cout << ans << ' ' << area-ans << "\n";
    }
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