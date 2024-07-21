#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FOREACH(e, s) for(auto e : s)
#define ADD push_back

vector<vector<int>> graph;
vector<int> distFromA, distFromB, parent;
int n, start, endfraizen;

void bfs(int startNode, const vector<vector<int>>& adjList, vector<int>& distances, vector<int>& parents) {
    queue<int> q;
    q.push(startNode);
    distances[startNode] = 0;
    parents[startNode] = -1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adjList[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                parents[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

void solve() {
    cin >> n >> start >> endfraizen;
    start--; endfraizen--; // Convert to 0-based indexing
    
    graph.assign(n, vector<int>());
    distFromA.assign(n, -1);
    distFromB.assign(n, -1);
    parent.assign(n, -1);
    
    FOR(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Convert to 0-based indexing
        graph[x].ADD(y);
        graph[y].ADD(x);
    }
    
    bfs(start, graph, distFromA, parent);
    bfs(endfraizen, graph, distFromB, parent);

    int maxDistance = 0;
    FOR(i, 0, n) {
        if (distFromB[i] > distFromA[i]) {
            maxDistance = max(maxDistance, distFromB[i]);
        }
    }
    
    cout << maxDistance << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
