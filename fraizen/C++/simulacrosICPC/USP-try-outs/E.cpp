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
typedef long double ld;
// double cost[105][105];
struct edgecitos{
    int u,v,a,b,c;
};
vector<edgecitos> edges;

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

struct Edge {
  int a, b;
  ld w;
};
bool operator<(const Edge& a, const Edge& b) { return a.w < b.w; }
// Minimun Spanning Tree in O(E log E)
ld kruskal(vector<Edge> &E, int n) {
  ld cost = 0; sort(E.begin(), E.end()); 
  UnionFind uf(n);
  forall(it, E) if(!uf.join(it->a, it->b))
    cost += it->w;
  return cost;
}

ld evaluar(ll a, ll b, ll c, ld x){
    return a * x * x + b * x + c;
}

vector<ld> inter(int i, int j){
    ld a = edges[i].a - edges[j].a;
    ld b = edges[i].b - edges[j].b;
    ld c = edges[i].c - edges[j].c;
    ld dis = b*b-4*a*c;
    vector<ld> res;
    if (dis >= 0){
        ld root = sqrt(dis);
        ld x1 = (-b + root) / (2*a);
        ld x2 = (-b-root)/(2*a);
        res.pb(x1);
        res.pb(x2);
        return res;
    } else {
        return res;
    }
}

void solve() {
    int n,m; cin >> n>>m;
    vector<Edge> kruskalEdges;
    fr(0,m){
        int u,v; cin >> u >> v; u--;v--;
        int a,b,c; cin >> a >> b >> c;
        edges.pb({u,v,a,b,c});
        kruskalEdges.pb({u,v,0.0});
    }
    vector<ld> x;
    x.pb(-1e9);
    x.pb(1e9);
    fr(0,m){
        rep(j,i+1,m){
            //intersecto las parabolas y veo los puntos de interseccion
            vector<ld> v = inter(i,j);
            fre(v){
                x.pb(e);
            }
        }
    }
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(x.begin(), x.end());
    ld res = 2e18;
    fr(0,x.size()-1){
        //hago una ternaria entre dos puntos consecutivos porque se mantienen las mismas aristas
        //no cambia el orden relativo de las funciones
        ld l = x[i];
        ld r = x[i+1];
        rep(j,0,100){ 
            ld m1 = l + (r-l) /3.0;
            ld m2 = l + (r-l)*2.0 /3.0;
            //calculo los costos para t = m1;
            fr(0,kruskalEdges.size()){
                kruskalEdges[i].w = evaluar(edges[i].a, edges[i].b,edges[i].c, m1);
            }
            //mando el kruskal
            ld resM1 = kruskal(kruskalEdges, n);
            //same for m2
            fr(0,kruskalEdges.size()){
                kruskalEdges[i].w = evaluar(edges[i].a, edges[i].b,edges[i].c, m2);
            }
            ld resM2 = kruskal(kruskalEdges, n);
            res = min(res, min(resM1, resM2));
            if (resM1 < resM2){
                r = m2;
            } else {
                l = m1;
            }
        }
    }

    cout << fixed << setprecision(10) << res << '\n';
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