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

char g[50][50];
int n,m;

struct Edge {
  int u, v;
  ll cap, flow;
  Edge() {}
  Edge(int uu, int vv, ll c) : u(uu), v(vv), cap(c), flow(0) {}
};
struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  Dinic(int n) : N(n), g(n), d(n), pt(n) {}  // clear and init
  void addEdge(int u, int v, ll cap) {
    if (u != v) {
      g[u].pb(sz(E));
      E.pb({u, v, cap});
      g[v].pb(sz(E));
      E.pb({v, u, 0});
    }
  }
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge& e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.push(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  ll DFS(int u, int T, ll flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int& i = pt[u]; i < sz(g[u]); ++i) {
      Edge& e = E[g[u][i]];
      Edge& oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (ll pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  ll maxFlow(int S, int T) {  // O(V^2*E), unit nets: O(sqrt(V)*E)
    ll total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = DFS(S, T)) total += flow;
    }
    return total;
  }
  void clear(){
    E.clear();
    fr(0,N){
        g[i].clear();
    }
  }
};

int dfsMasFlujo(int numberToRemove, Dinic &d){
    int first = -1;
    if (numberToRemove!=-1){
        if (g[numberToRemove/m][numberToRemove%m] == '#'){
            return -1;
        }
    }
    d.clear();

    fr(0,n){
        rep(j,0,m){
            if (i*m + j == numberToRemove){
                continue;
            }
            if (g[i][j] == '.'){
                if ((i+j) % 2 == 0){
                    if (i < n-1 && g[i+1][j] == '.' && ((i+1)*m + j != numberToRemove)){
                        d.addEdge(i*m+j + 2, (i+1)*m+j + 2,1);
                    }
                    if (j < m-1 && g[i][j+1] == '.' && (i*m + j+1 != numberToRemove)){
                        d.addEdge(i*m+j+2, i*m + j + 3, 1);
                    }
                } else {
                    if (i < n-1 && g[i+1][j] == '.' && ((i+1)*m + j != numberToRemove)){
                        d.addEdge((i+1)*m+j + 2, i*m+j + 2, 1);
                    }
                    if (j < m-1 && g[i][j+1] == '.' && (i*m + j+1 != numberToRemove)){
                        d.addEdge(i*m + j + 3,i*m+j+2, 1);
                    }
                }
            }
        }
    }
    fr(0,n){
        rep(j,0,m){
            if (g[i][j] == '.'){
                if ((i+j) % 2 == 0){
                    d.addEdge(0, i*m +j + 2, 1);
                } else {
                    d.addEdge(i*m +j + 2 ,1, 1);
                }
            }
        }
    }
    return d.maxFlow(0,1);
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n>> m;
    fr(0,n){
        rep(j,0,m){
            cin >> g[i][j];
        }
    }
    Dinic d = Dinic(n*m + 2);
    int flujo = dfsMasFlujo(-1, d);
    int res = 0;
    fr(0,n*m){
        int cur = dfsMasFlujo(i, d);
        if (cur == flujo){
            res++;
        }
    }
    cout << res << "\n";
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