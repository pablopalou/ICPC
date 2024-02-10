#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)

typedef ll tipo;
const tipo neutro = 1e9;
tipo oper(const tipo& a, const tipo& b) { return min(a,b); }
struct ST {
	int sz;
	vector<tipo> t;
	ST(int n) {
		sz = 1 << (32 - __builtin_clz(n));
		t = vector<tipo>(2*sz, neutro);
	}
	tipo &operator[](int p) { return t[sz+p]; }
	void updall() { dforn(i, sz) t[i] = oper(t[2*i], t[2*i+1]); }
	tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
	tipo get(int i, int j, int n, int a, int b) { //O(log n), [i, j)
		if(j <= a || b <= i) return neutro;
		if(i <= a && b <= j) return t[n]; // n = node of range [a,b)
		int c = (a+b)/2;
		return oper(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) { //O(log n)
		p += sz;
		while(p>0 && t[p] != val) {
			t[p] = val;
			p /= 2;
			val = oper(t[p*2], t[p*2+1]);
		}
	}
};

// Copiar obligatoriamente 0
void solve() {
    int n,q; cin >> n >> q;
    int a[n]; //ni necesito este arreglo
    ST stIzq = ST(n);
    ST stDer = ST(n);
    fr(0,n){
        cin >> a[i];
        stDer[i] = a[i] + i;
    }
    for(int i = n-1; i>=0; i--){
        stIzq[i] = a[i] + n-1 - i;
    }
    stIzq.updall();
    stDer.updall();
    fr(0,q){
        int type; cin >> type;
        if (type == 1){
            int i, newVal; cin >> i >> newVal;
            i--;
            //en cuanto estaba no me interesa, solo tengo que hacer el update basicamente.
            a[i] = newVal;
            stDer.set(i, a[i] + i);
            stIzq.set(i, a[i] + n-1 - i);
        } else {
            int q; cin >> q;
            q--;
            //tengo dos opciones, o voy para la izquierda en cuyo caso pregunto por [0,q]
            int izq = stIzq.get(0,q+1) - n + 1 + q;
            //o voy pa la derecha y pregunto por []
            int der = stDer.get(q,n) - q;
            //habria que ver si falta a[i]...
            cout << min(izq, der) << "\n";
        }
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