#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)

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
};

void solve() {
    int n; cin >> n;
    vector<vector<int> > elecciones(2,vector<int>(n/2));
    vector<vector<int> > res(2,vector<int>(n/2));
    fr(0, n/2) {
        cin >> elecciones[0][i];
    }
    fr(0, n/2) {
        cin >> elecciones[1][i];
    }
    ST st(n);
    fr(0, n) st[i] = 1;
    st.updall();
    int sz = 1 << (32 - __builtin_clz(n));
    fr(0, n/2) {
        rep(p, 0, 2) {
            int e = elecciones[p][i];
            int node = 1;
            while (node < sz) {
                int izq = node*2;
                int der = node*2+1;
                if (st.t[izq] >= e) {
                    node = izq;
                } else {
                    node = der;
                    e -= st.t[izq];
                }
            }
            st.set(node-sz, 0);
            res[p][i] = node-sz+1;
        }
    }
    fr(0, n/2) cout << res[0][i] << " ";
    cout(" ");
    fr(0, n/2) cout << res[1][i] << " ";
    cout(" ");
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("K.in", "r", stdin);
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