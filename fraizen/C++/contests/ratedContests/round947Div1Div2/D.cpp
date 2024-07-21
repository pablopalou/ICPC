#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fre(s) for (auto e : s)
#define pb push_back

vector<vector<ll>> adj;
vector<ll> distA, distB, parentA, parentB;
ll n, a, b;

void bfs(ll start, const vector<vector<ll>> &adj, vector<ll> &dist, vector<ll> &parent) {
    queue<ll> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

ll calculateMaxDepth(ll node, ll par, const vector<vector<ll>> &adj) {
    ll maxDepth = 0;
    for (ll v : adj[node]) {
        if (v != par) {
            maxDepth = max(maxDepth, 1 + calculateMaxDepth(v, node, adj));
        }
    }
    return maxDepth;
}

void solve() {
    cin >> n >> a >> b;
    a--; b--; // Converting to 0-based index
    adj.assign(n, vector<ll>());
    parentA.assign(n, -1);
    parentB.assign(n, -1);
    distA.assign(n, -1);
    distB.assign(n, -1);

    fr(0, n - 1) {
        ll x, y;
        cin >> x >> y;
        x--; y--; // Converting to 0-based index
        adj[x].pb(y);
        adj[y].pb(x);
    }

    bfs(a, adj, distA, parentA);
    bfs(b, adj, distB, parentB);

    // Find the path from a to b using parentA
    vector<ll> path;
    ll current = b;
    while (current != -1) {
        path.pb(current);
        current = parentA[current];
    }

    reverse(path.begin(), path.end());

    ll mid = path.size() / 2;
    ll final_pos = path[mid];
    ll maxDepth = calculateMaxDepth(final_pos, -1, adj);
    ll steps = (2 * (n - 1)) - maxDepth;

    cout << steps << '\n';
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    #endif

    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }

    #ifdef JP
    cerr << "Time elapsed: " << clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}
