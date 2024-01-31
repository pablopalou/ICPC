#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return a+b; }
// AL FINAL ESTE SALIO CON IMPLICIT SEGMENT TREE. ARCHIVO: salaryQueriesImplicitST.cpp
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
    ll n,q; cin >> n >> q;
    ST st = ST(1000005);
    ll a[n];
    // cout 
    // fr(0,n) {
    //     cout << i << ": " << st[i] << '\n';
    // }
    map<ll,ll> freqSalarios;
    fr(0,n){
        ll salary; cin >> salary;
        st[salary/1000]++;
        // cout << "st salary" << st[salary/100] << endl;
        a[i] = salary;
        freqSalarios[salary]++;
    }
    // fr(0,n) {
    //     cout << i << ": " << st[i] << '\n';
    // }

    st.updall();
    fr(0,q){
        string type; cin >> type;
        ll l,r; cin >> l >> r;
        if (type == "?"){
            // cout << "Query : [ " << l << "," << r << "]" << endl;
            if (r < l){
                cout << 0 << "\n";
                continue;
            }
            if (r - l <= 2000){ // aca lo hago a huevo y chau
                ll ans = 0;
                for(ll i = l; i<=r;i++){
                    ans += freqSalarios[i];
                }
                cout << ans << "\n";
                continue;
            }
            //aca me vino la query. Si un segmento esta entero, respondo eso, sino hago fuerza bruta.
            // conseguir la izquierda y derecha bien digamos.
            if (l % 1000 == 0 && r % 1000 == 999){ //empieza rango
                cout << st.get(l/1000,r/1000+1) << "\n";
                continue;
            }
            if (l % 1000 == 0){ // 3500 a 3730
                // fr(0,40){
                //     cout << i << ": " << st[i] << '\n';
                // }
                // cout << l/1000
                ll casiAns = st.get(l/1000, r/1000); // 35 => 37 ====> 3500 a 3699
                // cout << "casiAns = " << casiAns << endl;
                for(ll i = r / 1000 * 1000; i<=r;i++){
                    casiAns += freqSalarios[i];
                }
                cout << casiAns << "\n";
                continue;
            }
            if (r % 1000 == 99){
                ll casiAns = st.get(l/1000+1, r/1000+1);
                for(ll i = l; i<=(l/1000*1000 + 99);i++){
                    casiAns += freqSalarios[i];
                }
                cout << casiAns << "\n";
                continue;
            }
            ll izq = l / 1000;
            ll der = r / 1000;
            ll casiAns = st.get(izq + 1, der);
            for(ll i = l; i<=(l/1000*1000 + 99);i++){
                casiAns += freqSalarios[i];
            }
            for(ll i = r / 1000 * 1000; i<=r;i++){
                casiAns += freqSalarios[i];
            }
            cout << casiAns << "\n";
        } else {
            //aca updateo el l con r. (subir 1 y bajar 1 en la frecuencia)
            st.set(a[l-1]/1000, st[a[l-1]/1000]-1);
            st.set(r/1000, st[r/1000]+1); //creo que ta bien, fijarse
            //updatear la frecuencia
            freqSalarios[a[l-1]]--;
            freqSalarios[r]++;
            //updatear el arreglo tmb
            a[l-1] = r;
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