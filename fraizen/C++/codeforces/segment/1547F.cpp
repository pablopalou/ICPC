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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return gcd(a,b); }
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
    int n; cin >> n; int a[n];
    fr(0,n){
        cin >> a[i];
    }
    ST st(2*n); //pongo los elementos dos veces en principio para hacermela mas facil, aunque ojo el tiempo...
    fr(0,n){
        st[i] = a[i];
        st[i+n] = a[i];
    }
    st.updall();
    int d = 0;
    fr(0,n){
        d = gcd(d, a[i]);
    }
    // cout << "GCD = " << d << endl; 
    int res = 0;
    //para cada numero, veo cuantas iteraciones le lleva llegar al gcd
    fr(0,n){
        int cur = n;
        int l = i; int r = i+n-1;
        // cout << "i = " << i << endl;
        while(l<=r){
            int mid = l + (r-l) / 2;
            // cout << "Puebo mid = " << mid << endl;
            if (st.get(i,mid+1) > d){
                l = mid+1;
            } else { //gcd es igual, ya llegue, tengo que ver cuanto antes llegue digamos
                // cout << "El gcd es igual en " << mid-i << endl;
                cur = min(cur, mid-i);
                r = mid-1;
            }
        }
        // cout << "I = " << i << ", cur = " << cur << endl;
        res = max(res, cur);
    }
    cout << res << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}