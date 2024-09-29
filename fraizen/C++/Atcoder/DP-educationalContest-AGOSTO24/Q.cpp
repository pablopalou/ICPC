
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return max(a,b); }
struct ST {
  int sz;
  vector<tipo> t;
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<tipo>(2 * sz, neutro);
  }
  tipo& operator[](int p) { return t[sz + p]; }
  void updall() { dforn(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
  tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
    if (j <= a || b <= i) return neutro;
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  void set(int p, tipo val) {  // O(log n)
    p += sz;
    while (p > 0 && t[p] != val) {
      t[p] = val;
      p /= 2;
      val = oper(t[p * 2], t[p * 2 + 1]);
    }
  }
};  // Use: definir oper tipo neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

//El segment tree guarda los valores de la dp. 
//Hacemos la query al ST para saber el maximo valor de una dp anterior, siempre y cuando la altura sea menor, por eso vamos hasta h[i].
void solve() {
    ll n; cin >> n;
    ll h[n]; ll a[n];
    ll maxi = 0;
    fr(0,n){
        cin >> h[i]; maxi = max(h[i], maxi);
    }
    fr(0,n){
        cin >> a[i];
    }
    ST st = ST(maxi+1);
    ll ans = 0;
    fr(0,n){
        ll cur = a[i] + st.get(0,h[i]);
        ans = max(ans, cur);
        st.set(h[i], max(st.get(h[i],h[i]+1), cur)); //ponemos el maximo entre lo que teniamos y lo que podemos obtener si dejamos a la flower i.
    }
    cout << ans; 
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