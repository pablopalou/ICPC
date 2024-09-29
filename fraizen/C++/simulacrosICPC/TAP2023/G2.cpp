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
#define MAXN 100100
#define mp make_pair
#define mt make_tuple

struct UnionFind {
  int nsets;
  vector<int> f, setsz;  // f[i] = parent of node i
  UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
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

int n2;

struct Ar {
  int a, b, w;
};
bool operator<(const Ar& a, const Ar& b) { return a.w < b.w; }
vector<Ar> E;

// Minimun Spanning Tree in O(e log e)
ll kruskal() {
  ll cost = 0;
  sort(E.begin(), E.end());  // ordenar aristas de menor a mayor
  UnionFind uf = UnionFind(n2);
assert(E.size() < 1000000);
  forall(it, E) {
    if (uf.comp(it->a) != uf.comp(it->b)) {  // si no estan conectados
      uf.join(it->a, it->b);                 // conectar
      cost += it->w;
    }
  }
  return cost;
}

int n;
int h[MAXN],l[MAXN],r[MAXN];

set<pair<int,int> > alturas;

void manejarSet(int suma, int id){
    if (suma == -1){
        alturas.insert(mp(h[id], id));
    } else {
        alturas.erase(mp(h[id], id));
    }
}

void agregarArista(set<pair<int, int> >::iterator it, int id){
    Ar ar; 
    ar.a = id;
    ar.b = (*it).second;
    ar.w = abs(h[id] - it->first);
    E.pb(ar);
}

void addEdgeAndHandleSet(set<pair<int, int> >::iterator it, int id, int suma){
    agregarArista(it, id);
    manejarSet(suma,id);
}

void sweepline(vector<tuple<int,int,int> > e){
    sort(e.begin(), e.end());
    fr(0,e.size()){
        int pos, suma, id; 
        tie(pos,suma,id) = e[i];
        if (alturas.size() == 0){
            manejarSet(suma, id); continue;
        }
        auto it = alturas.upper_bound(mp(h[id],id));
        // auto it = upper_bound(alturas.begin(), alturas.end(), mp(h[id],id));
        if (it == alturas.end()){
            it--;
            addEdgeAndHandleSet(it, id, suma);
            continue;
        }
        if (it == alturas.begin()){
            addEdgeAndHandleSet(it, id, suma);
            continue;
        }
        agregarArista(it, id);
        it--;
        addEdgeAndHandleSet(it, id, suma);
    }
}

void solve() {
    cin >> n;
    n2 = n+1; //agrego el piso
    h[n] = 0;
    fr(0,n){
        cin >> h[i] >> l[i] >> r[i];
    }
    vector<tuple<int,int,int>> e;
    fr(0,n){
        e.pb(mt(l[i] + h[i], -1, i));
        e.pb(mt(r[i] + h[i], 1, i));
    }
    e.pb({-2e9-100, -1, n}); e.pb({2e9+100, 1, n});
    #ifdef JP
		cerr << "Time elapsed antes del primer sweepline: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    sweepline(e);
    e.clear();
    fr(0,n){
        e.pb(mt(l[i] - h[i], -1, i));
        e.pb(mt(r[i] - h[i], 1, i));
    }
    e.pb({-2e9-100, -1, n}); e.pb({2e9+100, 1, n});
    alturas.clear();
    #ifdef JP
		cerr << "Time elapsed antes del segundo sweepline: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    sweepline(e);
    #ifdef JP
		cerr << "Time elapsed antes del kruskal: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    cout << kruskal() << "\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("G.in", "r", stdin);
        // freopen("A.out", "w", stdout);
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