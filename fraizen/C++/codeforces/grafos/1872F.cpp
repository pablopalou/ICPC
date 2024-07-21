#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void findCycles(int n, int adj[], vector<vector<int>>& cycles) {
    vector<int> color(n, 0); // 0: unvisited, 1: visiting, 2: visited
    vector<int> parent(n, -1); // To store the parent nodes
    vector<int> path; // To store the current path

    function<void(int)> dfs = [&](int u) {
        color[u] = 1; // Mark node as visiting
        path.push_back(u);

        int v = adj[u];
        if (color[v] == 0) { // Node v is unvisited
            parent[v] = u;
            dfs(v);
        } else if (color[v] == 1) { // Found a cycle
            vector<int> cycle;
            for (int i = path.size() - 1; i >= 0; i--) {
                cycle.push_back(path[i]);
                if (path[i] == v) break;
            }
            reverse(cycle.begin(), cycle.end());
            cycles.push_back(cycle);
        }

        path.pop_back();
        color[u] = 2; // Mark node as visited
    };

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
}

void solve() {
    int n; cin >> n;
    int adj[n];
    int in[n];
    int c[n];
    int used[n];
    memset(in, 0, sizeof(in));
    memset(used, 0, sizeof(used));
    fr(0,n){
        int a; cin >> a; a--;
        adj[i] = a;
        in[a]++;
    }
    fr(0,n){
        cin >> c[i];
    }
    // ll res = 0;
    queue<int> q;
    fr(0,n){
        if (in[i] == 0){
            q.push(i);
        }
    }
    int usados = 0;
    while(q.size() > 0){
        int f = q.front();
        used[f] = 1;
        cout << f+1 << ' ';
        usados++;
        q.pop();
        // res += c[f] * 2;
        in[adj[f]]--;
        if (in[adj[f]] == 0){
            q.push(adj[f]);
        }
    }

    vector<vector<int>> cycles;
    findCycles(n, adj, cycles);

    for (const auto& cycle : cycles) {
        int mini = 1e9+2;
        int pos = -1;
        // cout << "Nodos" << endl;
        for (int node : cycle) {
            // cout << node << endl;
            if (c[node] < mini){
                pos = node;
            }
            mini = min(c[node], mini);
        }
        pos=adj[pos];
        fr(0,cycle.size()){
            cout << pos+1 << " ";
            used[pos] = 1;
            usados++;
            pos = adj[pos];
        }
    }
    cout<< '\n';
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