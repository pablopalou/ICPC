#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

#define dforn(i,n) for(int i=n-1;i>=0;i--)

//no anda. Hay que llevar minimo del rango y cuanto faltaria para llevar a todos los numeros lo cual es inviable. s
typedef tuple<ll,ll,ll> tipo;
const tipo neutro = {0,0,0};
tipo oper(const tipo& a, const tipo& b) {
    tuple<ll,ll,ll> c;
    if (get<1>(b) <= get<1>(a)){
        get<0>(c) = get<0>(a) + get<0>(b) + (get<1>(a) - get<1>(b)) * get<2>(b);
    } else {
        get<0>(c) = get<0>(a) + get<0>(b);
    }
    // cout << get<0>(a) << endl;
    // cout << get<0>(b) << endl;
    get<1>(c) = max(get<1>(a), get<1>(b));
    get<2>(c) = get<2>(a) + get<2>(b);
    // cout << get<0>(c) << " " << get<1>(c) << " " << get<2>(c) << " " << "\n";
    return c;
}
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
    ST st = ST(n);
    ll a[n];
    fr(0,n){
        cin >> a[i];
        st[i] = {0,a[i], 1};
    }
    st.updall();
    // cout << get<0>(st[1]) << " " << get<1>(st[1]) << " " << get<2>(st[1]) << " " << "\n";
    fr(0,q){
        ll l,r; cin >> l >> r;
        // cout << l-1 << ' ' << r << endl;
        cout << get<0>(st.get(l-1, r)) << "\n";
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