#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 200002
vector<int> adj[MAXN];
bool vis[MAXN];
int node = -1;
bool encontre = false;

void dfs(int b, int parent){
    vis[b] = true;
    // cout << "B = " << b << endl;
    fre(adj[b]){
        // cout << "pruebo " << e << " estando en b = " << b << endl;
        if (e!=parent && vis[e] && !encontre){
            // cout << "actualizo nodo a " << e << endl;
            node = e; 
            encontre = true;
            return;
        } else if (!vis[e]){
            dfs(e, b);
        }
    }
}

int bfs(int start, int target, int totalNodes) {
    if (start == target) return 0;  // If start and target are the same, distance is zero.

    fill(vis, vis + totalNodes + 1, false);  // Reset vis array.
    queue<int> q;
    q.push(start);
    vector<int> dist(totalNodes + 1, 1e9);  // Initialize distances to a large number.
    dist[start] = 0;
    vis[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        fre(adj[current]) {
            if (!vis[e]) {
                vis[e] = true;
                dist[e] = dist[current] + 1;
                q.push(e);
                if (e == target) return dist[e];  // Return distance as soon as target is found.
            }
        }
    }
    return -1;  // Return -1 if the target node is not reachable from the start node.
}

void solve() {
    int n,a,b; cin >> n >> a >> b;
    fr(0,n){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    encontre = false;
    if (a == b) {
        cout << "NO\n"; 
        fr(0,n+1){
            adj[i].clear();
            vis[i] = false;
        }
        return;
    }
    //conseguir nodo de entrada de ciclo desde valerio 
    fr(0,n+1){
        vis[i] = false;
    }
    dfs(b,-1);
    // cout << "Nodo de entrada al ciclo es " << node << endl;
    //ahi ya puedo saber la distancia con bfs con valerio y con el otro
    //si llego primero con valerio entonces me escapo, sino no.
    fr(0,n+1){
        vis[i] = false;
    }
    int dist1 = bfs(a, node, n);
    fr(0,n+1){
        vis[i] = false;
    }
    int dist2 = bfs(b, node, n);
    // cout << "dist 1 => "  << dist1 << endl;
    // cout << "dist 2 => "  << dist2 << endl; 
    if (dist2 < dist1){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    fr(0,n+1){
        adj[i].clear();
        vis[i] = false;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}