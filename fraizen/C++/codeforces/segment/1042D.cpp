#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
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

//DA TLE, hay que comprimir coordenadas


typedef int tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return a + b; }
// Compressed segtree, it works for any range (even negative indexes)
struct ST {
  ST *lc, *rc;
  tipo val;
  int L, R;
  ST(int l, int r, tipo x = neutro) {
    lc = rc = nullptr;
    L = l, R = r, val = x;
  }
  ST(int l, int r, ST* lp, ST* rp) {
    if (lp != nullptr && rp != nullptr && lp->L > rp->L) swap(lp, rp);
    lc = lp, rc = rp;
    L = l, R = r;
    val = oper(lp == nullptr ? neutro : lp->val,
               rp == nullptr ? neutro : rp->val);
  }
  // O(log(R-L)), parameter 'isnew' only needed when persistent
  // This operation inserts at most 2 nodes to the tree, i.e. the
  // total memory used by the tree is O(N), where N is the number
  // of times this 'set' function is called. (2*log nodes when persistent)
  void set(int p, tipo x, bool isnew = false) {  // return ST* for persistent
    // uncomment for persistent
    // if(!isnew) {
    //   ST* newnode = new ST(L, R, lc, rc);
    //   return newnode->set(p, x, true);
    // }
    if (L + 1 == R) {
      val = x;
      return;  // 'return this;' for persistent
    }
    int m = (L + R) / 2;
    ST** c = p < m ? &lc : &rc;
    if (!*c) *c = new ST(p, p + 1, x);
    else if ((*c)->L <= p && p < (*c)->R) {
      // replace by comment for persistent
      (*c)->set(p, x);
      // *c = (*c)->set(p,x);
    } else {
      int l = L, r = R;
      while ((p < m) == ((*c)->L < m)) {
        if (p < m) r = m;
        else l = m;
        m = (l + r) / 2;
      }
      *c = new ST(l, r, *c, new ST(p, p + 1, x));
      // The code above, inside this else block, could be
      // replaced by the following 2 lines when the complete
      // range has the form [0, 2^k)
      // int rm = (1<<(32-__builtin_clz(p^(*c)->L)))-1;
      // *c = new ST(p & ~rm, (p | rm)+1, *c, new ST(p, p+1, x));
    }
    val = oper(lc ? lc->val : neutro, rc ? rc->val : neutro);
    // return this; // uncomment for persistent
  }
  tipo get(int ql, int qr) {  // O(log(R-L))
    if (qr <= L || R <= ql) return neutro;
    if (ql <= L && R <= qr) return val;
    return oper(lc ? lc->get(ql, qr) : neutro, rc ? rc->get(ql, qr) : neutro);
  }
};  // Usage: 1- RMQ st(MIN_INDEX, MAX_INDEX) 2- normally use set/get

// Copiar obligatoriamente 0
void solve() {
    ll n, t; cin >> n >> t;
    ll a[n];
    fr(0,n) cin >> a[i];
    ll p[n+1];
    p[0] = 0;
    ST st(-2e14-2, 2e14+2);
    fr(1,n+1){
        p[i] = p[i-1] + a[i-1];
        st.set(p[i], st.get(p[i],p[i]+1)+1);
    }
    ll ans = 0;
    fr(1,n+1){
        ans += st.get(-2e14-1, t + p[i-1]);
        st.set(p[i], st.get(p[i], p[i]+1)-1);
    }
    cout << ans << '\n';
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