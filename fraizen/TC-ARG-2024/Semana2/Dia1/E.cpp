#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int MAXN = 100100;
vector<vector<int>> adj(MAXN);

struct UF {
  int nsets;
  vector<int> f, setsz;  // f[i] = parent of node i
  UF(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
  int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
  bool join(int i, int j) {  // returns true if already in the same set
    int a = comp(i), b = comp(j);
    if (a != b) {
      if (setsz[a] > setsz[b]) swap(a, b);
      f[a] = b;  // the bigger group (b) now represents the smaller (a)
      nsets--, setsz[b] += setsz[a];
    }
    return a == b;
  }
};

void solve() {
    int n,m; cin >> n >>m;
    fr(0,m){
        int u,v; cin >> u >> v; u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int menor = 0;
    int conexiones = m+1;
    fr(0,n){ //si o si hay un nodo con grado menor a raiz de MAXN
        //busco el mas chico (significa que tiene mas conectados gratis)
        if ((int)adj[i].size() < conexiones){
            menor = i;
        }
        conexiones = min(conexiones, (int)adj[i].size());
    }
    //ahora ya tengo el que tiene mas cosos 0 digamos.
    //lo conecto con todos
    UF uf = UF(n);
    set<int> s;
    fre(adj[menor]){
        s.insert(e);
    }
    fr(0,n){
        if (i != menor){
            if (s.find(i) == s.end()){
                uf.join(menor, i);
            }
        }
    }
    int comp = uf.comp(menor);
    //ahora todos los nodos que me sobraron, me fijo contra todos los otros a ver que onda.
    vector<int> faltan;
    fr(0,n){
        if (uf.comp(i) != comp){
            faltan.pb(i);
        }
    }
    fre(faltan){ //meto los vecinos de cada uno en un set
        set<int> vecinos;
        for (auto nei:adj[e]){
            vecinos.insert(nei);
        }
        fr(0,n){
            if (i != e){
                if (vecinos.find(i) == vecinos.end()){
                    uf.join(e, i);
                }
            }
        }
    }
    set<int> comps;
    fr(0,n){
        comps.insert(uf.comp(i));
    }
    cout << comps.size()-1 << '\n';
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