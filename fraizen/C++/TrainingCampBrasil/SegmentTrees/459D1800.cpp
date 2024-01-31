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
}; //Use: definir oper tipo neutro,
//cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    unordered_map<ll, ll> contIzq;
    unordered_map<ll, ll> contDer;
    //el segment va a tener la derecha para atras digamos.
    ST st = ST(n);
    for(ll i = n-1; i>=0; i--){
        contDer[a[i]]++;
        // st.set(contDer[a[i]], st[contDer[a[i]]] + 1);
        st[contDer[a[i]]-1]++;
    }
    st.updall();
    #ifdef JP
		cerr << "Time elapsed to create: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    ll ans = 0;
    fr(0,n-1){
        st.set(contDer[a[i]] - 1, st[contDer[a[i]] - 1] - 1);
        contDer[a[i]]--;
        contIzq[a[i]]++;
        ans += st.get(0, contIzq[a[i]] - 1);
    }
    cout << ans << "\n";
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