#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3 * 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

int cntNodes(int u) {
    visited[u] = true;
    int res = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            res += cntNodes(v);
        }
    }
    return res;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int nodes_x, nodes_y;

    memset(visited, false, sizeof(visited));
    visited[x] = true;
    for (int v : adj[x]) {
        if (!visited[v]) {
            nodes_x = cntNodes(v);
            break;
        }
    }

    memset(visited, false, sizeof(visited));
    visited[y] = true;
    for (int v : adj[y]) {
        if (!visited[v]) {
            nodes_y = cntNodes(v);
            break;
        }
    }

    long long total = ((long long)n * (n - 1)) / 2;
    long long invalid = (long long)nodes_x * nodes_y;

    long long answer = total - invalid;
    cout << answer << '\n';

    return 0;
}
