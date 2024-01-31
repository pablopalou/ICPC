#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b, const tipo& ind, ll sz) {
    ll height = 64 - __builtin_clzll(sz - 1);
    ll level = height - (64 - __builtin_clzll(ind));
    if (level % 2 == 0) return a | b;
    return a ^ b;
}
struct ST {
	ll sz;
	vector<tipo> t;
	ST(ll n) {
		sz = 1 << (64 - __builtin_clzll(n));
		t = vector<tipo>(2*sz, neutro);
	}
	tipo &operator[](ll p) { return t[sz+p]; }
	void updall() { for(ll i = sz-1; i >= 0; i--) t[i] = oper(t[2*i], t[2*i+1], i, sz); }
	tipo get(ll i, ll j) { return get(i, j, 1, 0, sz); }
	tipo get(ll i, ll j, ll n, ll a, ll b) { //O(log n), [i, j)
		if(j <= a || b <= i) return neutro;
		if(i <= a && b <= j) return t[n]; // n = node of range [a,b)
		ll c = (a+b)/2;
		return oper(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b), n, sz);
	}
	void set(ll p, tipo val) { //O(log n)
		p += sz;
		while(p>0 && t[p] != val) {
			t[p] = val;
			p /= 2;
			val = oper(t[p*2], t[p*2+1], p, sz);
		}
	}
}; //Use: definir oper tipo neutro,
//cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

void solve() {
    ll n, m;
    cin >> n >> m;
    n = 1 << n;
    ST st(n);
    fr(0, n) {
        cin >> st[i];
    }
    st.updall();
    fr(0, m) {
        ll p, b;
        cin >> p >> b;
        p--;
        st.set(p, b);
        cout << st.get(0, n) << "\n";
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