#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())

typedef ll Elem;
typedef ll Alt;
const Elem neutro = 0;
const Alt neutro2 = 0;
Elem oper(const Elem& a, const Elem& b) { return a + b; }
struct ST {
  int sz;
  vector<Elem> t;
  vector<Alt> dirty;  // Alt and Elem could be different types
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<Elem>(2 * sz, neutro);
    dirty = vector<Alt>(2 * sz, neutro2);
  }
  Elem& operator[](int p) { return t[sz + p]; }
  void updall() { dforn(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  void push(int n, int a, int b) {  // push dirt to n's child nodes
    if (dirty[n] != neutro2) {      // n = node of range [a,b)
      t[n] += dirty[n] * (b - a);   // CHANGE for your problem
      if (n < sz) {
        dirty[2 * n] += dirty[n];      // CHANGE for your problem
        dirty[2 * n + 1] += dirty[n];  // CHANGE for your problem
      }
      dirty[n] = neutro2;
    }
  }
  Elem get(int i, int j, int n, int a, int b) {  // O(lgn)
    if (j <= a || b <= i) return neutro;
    push(n, a, b);                      // adjust value before using it
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
  // altera los valores en [i, j) con una alteracion de val
  void update(Alt val, int i, int j, int n, int a, int b) {  // O(lgn)
    push(n, a, b);
    if (j <= a || b <= i) return;
    if (i <= a && b <= j) {
      dirty[n] += val;  // CHANGE for your problem
      push(n, a, b);
      return;
    }
    int c = (a + b) / 2;
    update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
    t[n] = oper(t[2 * n], t[2 * n + 1]);
  }
  void update(Alt val, int i, int j) { update(val, i, j, 1, 0, sz); }
};  // Use: definir operacion, neutros, Alt, Elem, uso de dirty
// cin >> n; ST st(n); forn(i,n) cin >> st[i]; st.updall()

// Copiar obligatoriamente 0
void solve(int caso) {
    cout << "Case " << caso << " :\n"; 
    int t; cin >> t;
    string s;
    fr(0,t){
        int reps; string patron; cin >> reps >> patron;
        string patronInicial = patron;
        rep(j,0,reps){
            patron = patron + patronInicial;
        }
        s+=patron;
    }
    //armar st
    ST st = ST(s.size() + 2);
    int i = 0;
    for(auto ch: s){
        st[i] = ch - '0';
        i++;
    }
    st.updall();
    int q; cin >> q;
    fr(0,q){
        char c; cin >> c;
        int l,r; cin >> l >> r;
        if (c == 'F'){
            //update a 1 de l a r
            st.update(1, l, r+1);
        } else if (c=='I'){
            // no se como pero los tengo que invertir...
            st.update(1, l, r+1);
        } else if (c == 'S'){
            int res = st.get(l, r+1);
            cout << "Q" << i << ": " << res << "\n";
        } else {
            st.update(0,l,r+1);
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
    int caso = 1;
    cin >> cases;
    while(cases--){
        solve(caso);
        caso++;
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}