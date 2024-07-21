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
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return a + b; }
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



// Copiar obligatoriamente 0
void solve() {
    ll n,q; cin >> n >> q;
    ll a[n];
    map<ll,ll> m; //guardo ult pos
    fr(0,n){
        cin >> a[i];
        m[a[i]]=-1;
    }
    vector<tuple<ll,ll,ll>> v;
    fr(0,q){
        ll l,r; cin >> l >> r;
        v.pb({r, l, i});
    }
    sort(v.begin(), v.end());
    //ordeno queries
    auto it = v.begin();
    int i = 0;
    ST st(n);
    int ans[q];
    while(i < n || it != v.end()){
        if(it == v.end()){
            break;
        }
        int r = get<0>(*it);
        int l = get<1>(*it);
        l--;
        int index = get<2>(*it);
        if (i < r){
            //agrego i continuo...
            if (m[a[i]] != -1){
                st.set(m[a[i]], 0);
                // cout << "Pongo " << m[a[i]] << " en 0" << endl;
                m[a[i]] = i;
                st.set(i, 1);
                // cout << "Pongo " <<i<< " en 1" << endl;
            } else {
                m[a[i]] = i;
                st.set(i, 1);
                // cout << "Pongo " <<i<< " en 1" << endl;
            }
            i++;
            continue;
        }
        // cout << "I = " << i << endl;
        // cout << "l = " << l << ", r = " << r << " , index = " << index << endl; 
        // fre(m){
        //     cout << "m["<< e.first <<"] = " << e.second << '\n';
        // }
        // i es igual a r, tengo que responder queries
        ans[index] = st.get(l,r);
        it++;
    }
    fr(0,q){
        cout << ans[i] << '\n';
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