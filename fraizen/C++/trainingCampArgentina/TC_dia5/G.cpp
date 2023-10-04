#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vi> adj_list;
vector<bool> visited;
vector<ll> costs;

void dfs(int u, ll& min_cost) {
    visited[u] = true;
    min_cost = min(min_cost, costs[u]);
 
    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, min_cost);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj_list.resize(n);
    visited.resize(n, false);
    costs.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; 
        --y; 
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    ll total_cost = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ll min_cost = costs[i];
            dfs(i, min_cost);
            total_cost += min_cost;
        }
    }

    cout << total_cost << endl;
    return 0;
}