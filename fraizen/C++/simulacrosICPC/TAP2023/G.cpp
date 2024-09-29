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
typedef pair<int, int> ii;
#define MAXN 100100
#define mp make_pair

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

void solve() {
    int n; cin >> n;
    n2 = n+1;
    //hago sweepline solo contando rayos hacia la derecha (si lo veo de arriba pa abajo)
    int h[n+1], l[n], r[n];
    h[n] = 0;
    fr(0,n){
        cin >> h[i] >> l[i] >> r[i];
    }
    vector<tuple<int,int,int>> e;
    fr(0,n){
        e.pb({l[i] + h[i], -1, i});
        e.pb({r[i] + h[i], 1, i});
    }
    //agrego el piso
    e.pb({-2e9-100, -1, n}); e.pb({2e9+100, 1, n});
    //tendria que hacer sweepline ahora con estos eventos
    sort(e.begin(), e.end());
    set<pair<int,int>> alturas; //segunda coordenada es id
    assert(e.size() < 200300);
    fr(0,e.size()){
        int pos = get<0>(e[i]);
        int sumo = get<1>(e[i]);
        int id = get<2>(e[i]);
        auto it = alturas.upper_bound(mp(h[id], id));
        //Da tle con esto 
        // auto it = upper_bound(alturas.begin(), alturas.end(), mp(h[id],id));
        if (alturas.size() == 0){
            //no hay conexiones, pusheo o elimino y me voy
            if (sumo == -1){
                alturas.insert(mp(h[id], id));
            } else {
                alturas.erase(mp(h[id], id));
            }
            continue;
        }
        if (it == alturas.end()){
            //no tengo conexiones mas grandes, me fijo si tengo mas chicas
            it--;
            //la conecto en el mst: 
            Ar ar; 
            ar.a = id;
            ar.b = (*it).second;
            ar.w = abs(h[id] - it->first);
            E.pb(ar);
            //pusheo o elimino y me voy
            if (sumo == -1){
                alturas.insert(mp(h[id], id));
            } else {
                alturas.erase(mp(h[id], id));
            }
            continue;
        }
        //tengo una mas grande seguro, ojo que capaz no tengo mas chica
        //me conecto con el mas grande: 
        Ar ar; 
        ar.a = id;
        ar.b = (*it).second;
        ar.w = abs(h[id] - it->first);
        E.pb(ar);
        // veo si hay mas chico
        if (it != alturas.begin()){
            it--;
            Ar ar; 
            ar.a = id;
            ar.b = (*it).second;
            ar.w = abs(h[id] - it->first);
            E.pb(ar);
        }
        if (sumo == -1){
            alturas.insert(mp(h[id], id));
        } else {
            alturas.erase(mp(h[id], id));
        }
    }

// cout << "PRIMERA PASADA " << endl;
//     fre(E){
//         cout << e.a <<" " << e.b << " con peso " << e.w << endl;
//     }
// cout << "FIN PRIMERA PASADA " << endl;
    //listo, ahora hay que hacer para el otro lado el sweepline: 
    e.clear();
    alturas.clear();
    fr(0,n){
        e.pb({l[i] - h[i], -1, i});
        e.pb({r[i] - h[i], 1, i});
    }
    //agrego el piso
    e.pb({-2e9-100, -1, n}); e.pb({2e9+100, 1, n});
    //tendria que hacer sweepline ahora con estos eventos
    sort(e.begin(), e.end());

    assert(e.size() < 200300);
    // set<pair<int,int>> alturas; //segunda coordenada es id
    fr(0,e.size()){
        int pos = get<0>(e[i]);
        int sumo = get<1>(e[i]);
        int id = get<2>(e[i]);
        auto it = alturas.upper_bound(mp(h[id], id));
        // auto it = upper_bound(alturas.begin(), alturas.end(), mp(h[id],id));
        if (alturas.size() == 0){
            //no hay conexiones, pusheo o elimino y me voy
            if (sumo == -1){
                alturas.insert(mp(h[id], id));
            } else {
                alturas.erase(mp(h[id], id));
            }
            continue;
        }
        if (it == alturas.end()){
            //no tengo conexiones mas grandes, me fijo si tengo mas chicas
            it--;
            //la conecto en el mst: 
            Ar ar; 
            ar.a = id;
            ar.b = (*it).second;
            ar.w = abs(h[id] - it->first);
            E.pb(ar);
            //pusheo o elimino y me voy
            if (sumo == -1){
                alturas.insert(mp(h[id], id));
            } else {
                alturas.erase(mp(h[id], id));
            }
            continue;
        }
        //tengo una mas grande seguro, ojo que capaz no tengo mas chica
        //me conecto con el mas grande: 
        Ar ar; 
        ar.a = id;
        ar.b = (*it).second;
        ar.w = abs(h[id] - it->first);
        E.pb(ar);
        // veo si hay mas chico
        if (it != alturas.begin()){
            it--;
            Ar ar; 
            ar.a = id;
            ar.b = (*it).second;
            ar.w = abs(h[id] - it->first);
            E.pb(ar);
        }
        if (sumo == -1){
            alturas.insert(mp(h[id], id));
        } else {
            alturas.erase(mp(h[id], id));
        }
    }

    ll res = kruskal();
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}