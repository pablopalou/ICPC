#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1; i>-0; i--)
#define sz(c) ((ll)c.size())
#define forall(it, v) for(auto it=v.begin(); it != v.end(); it++)
#define pb push_back

typedef ll tf;
typedef ll tc;
const tf INF_FLOW = 1e14;
const tc INF_COST = 1e14;
struct edge{
    int u,v;
    tf cap, flow;
    tc cost;
    tf rem() {return cap -flow; }
};

struct MCMF {
    vector<edge> e;
    vector<vector<int> > g;
    vector<tf> vcap;
    vector<tc> dist;
    vector<int> pre;
    tc minCost;
    tf maxFlow;

    MCMF(int n): g(n), vcap(n), dist(n), pre(n) {}
    void addEdge(int u, int v, tf cap, tc cost) {
        cout << u << " " << v << " " << cap << " " << cost << endl;
        g[u].pb(sz(e)); e.pb({u,v,cap,0,cost});
        g[v].pb(sz(e)); e.pb({v,u,0,0,-cost});
    }

    void run(int s, int t){
        vector<bool> inq(sz(g));
        maxFlow = minCost = 0;
        while(1){
            fill(vcap.begin(), vcap.end(), 0); vcap[s] = INF_FLOW;
            fill(dist.begin(), dist.end(), INF_COST); dist[s] = 0;
            fill(pre.begin(), pre.end(), -1); pre[s] = 0;
            queue<int> q; q.push(s); inq[s] = true;
            while(sz(q)) {
                int u = q.front(); q.pop(); inq[u] = false;
                for(auto eid: g[u]){
                    edge &E = e[eid];
                    if(E.rem() && dist[E.v] > dist[u] + E.cost){
                        dist[E.v] = dist[u] + E.cost;
                        pre[E.v] = eid;
                        vcap[E.v] = min(vcap[u], E.rem());
                        if(!inq[E.v]) q.push(E.v), inq[E.v] = true;
                    }
                }
            }
            if(pre[t] == -1) break;
            tf flow = vcap[t];
            maxFlow += flow;
            minCost += flow * dist[t];
            for(int v = t; v != s; v = e[pre[v]].u){
                e[pre[v]].flow += flow;
                e[pre[v]^1].flow -= flow;
            }
        }
    }
};

void solve(){
    int n_p, n_c; cin >> n_p >> n_c;
    vector<vector<int> > pais_colores(2+n_c+n_p);
    fr(2+n_c, 2+n_c+n_p) {
        int n_c_p; cin >> n_c_p;
        rep(j, 0, n_c_p) {
            int color; cin >> color; color--; color += 2;
            pais_colores[i].push_back(color);
        }
    }
    MCMF mcmf(n_p+n_c+2);
    int src = 0; int snk = 1;
    // Aristas de src a colores
    fr(2, 2+n_c) {
        mcmf.addEdge(src, i, INF_FLOW, 1);
    }
    // Aristas de src a paises
    fr(2+n_c, 2+n_c+n_p) {
        int cant_colores_pais = pais_colores[i].size();
        mcmf.addEdge(src, i, cant_colores_pais, 1);
    }
    // Aristas desde colores a paises
    fr(2+n_c, 2+n_c+n_p) {
        int pais = i;
        int cant_colores_pais = pais_colores[pais].size();
        rep(j, 0, cant_colores_pais) {
            int color = pais_colores[pais][j];
            mcmf.addEdge(color, pais, 1, 0);
        }
    }
    // Aristas desde paises a snk
    fr(2+n_c, 2+n_c+n_p) {
        int pais = i;
        int cant_colores_pais = pais_colores[i].size();
        mcmf.addEdge(pais, snk, cant_colores_pais, 0);
    }
    mcmf.run(src, snk);

    cout(mcmf.minCost);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("B.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >>  cases;
    while(cases--){
        solve();
    }

    #ifdef JF
        cerr << "Time elapsed: " << clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif


    return 0;
}