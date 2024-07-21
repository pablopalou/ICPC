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
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

// Usage:
// 1. Create with n = number of variables (0-indexed)
// 2. Add restrictions through the existing methods, using ~X for
//    negating variable X for example.
// 3. Call satisf() to check whether there is a solution or not.
// 4. Find a valid assigment by looking at verdad[cmp[2*X]] for each
//    variable X
struct Sat2 {
  // We have a vertex representing a variable and other for its
  // negation. Every edge stored in G represents an implication.
  vector<vector<int>> G;
  // idx[i]=index assigned in the dfs
  // lw[i]=lowest index(closer from the root) reachable from i
  // verdad[cmp[2*i]]=valor de la variable i
  int N, qidx, qcmp;
  vector<int> lw, idx, cmp, verdad;
  stack<int> q;
  Sat2(int n) : G(2 * n), N(n) {}
  void tjn(int v) {
    lw[v] = idx[v] = ++qidx;
    q.push(v), cmp[v] = -2;
    forall(it, G[v]) if (!idx[*it] || cmp[*it] == -2) {
      if (!idx[*it]) tjn(*it);
      lw[v] = min(lw[v], lw[*it]);
    }
    if (lw[v] == idx[v]) {
      int x;
      do { x = q.top(), q.pop(), cmp[x] = qcmp; } while (x != v);
      verdad[qcmp] = (cmp[v ^ 1] < 0);
      qcmp++;
    }
  }
  bool satisf() {  // O(N)
    idx = lw = verdad = vector<int>(2 * N, 0);
    cmp = vector<int>(2 * N, -1);
    qidx = qcmp = 0;
    forn(i, N) {
      if (!idx[2 * i]) tjn(2 * i);
      if (!idx[2 * i + 1]) tjn(2 * i + 1);
    }
    forn(i, N) if (cmp[2 * i] == cmp[2 * i + 1]) return false;
    return true;
  }
  // a -> b, here ids are transformed to avoid negative numbers
  void addimpl(int a, int b) {
    a = a >= 0 ? 2 * a : 2 * (~a) + 1;
    b = b >= 0 ? 2 * b : 2 * (~b) + 1;
    G[a].pb(b), G[b ^ 1].pb(a ^ 1);
  }
  void addor(int a, int b) { addimpl(~a, b); }  // a | b = ~a -> b
  void addeq(int a, int b) {                    // a = b, a <-> b (iff)
    addimpl(a, b);
    addimpl(b, a);
  }
  void addxor(int a, int b) { addeq(a, ~b); }  // a xor b
  void force(int x, bool val) {                // force x to take val
    if (val) addimpl(~x, x);
    else addimpl(x, ~x);
  }
  // At most 1 true in all v
  void atmost1(vector<int> v) {
    int auxid = N;
    N += sz(v);
    G.rsz(2 * N);
    forn(i, sz(v)) {
      addimpl(auxid, ~v[i]);
      if (i) {
        addimpl(auxid, auxid - 1);
        addimpl(v[i], auxid - 1);
      }
      auxid++;
    }
    assert(auxid == N);
  }
};

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; 
    int a[3][n];
    Sat2 sat(n+1);
    fr(0,3){
        rep(j,0,n){
            cin >> a[i][j];
            // a[i][j]*=-1;
        }
    }
    rep(i,0,n){
        rep(j,0,3){
            int x = a[j][i];
            int y = a[(j+1)%3][i];
            if (x<0){
                x = ~abs(x);
            }
            if (y < 0){
                y = ~abs(y);
            }
            sat.addor(x,y);
        }
    }

    //de esta manera tambien funciona joya y me parece mas facil de entender. 
    //(acordarse de hacer el a[i][j]*=-1; xq queremos como mucho uno falso y en el 2sat la funcion es como mucho uno verdadero.
    // rep(j,0,n){
    //     vector<int> v;
    //     rep(i,0,3){
    //         if (a[i][j] > 0){
    //             v.pb(a[i][j]);
    //         } else {
    //             v.pb(~abs(a[i][j]));
    //         }
    //     }
    //     sat.atmost1(v);
    // }

    if (sat.satisf()){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

//la otra forma es hacer addor(x,y) addor(y,z) addor(z,x) para cada columna

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