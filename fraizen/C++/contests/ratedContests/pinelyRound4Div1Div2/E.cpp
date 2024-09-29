#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

bool isBipartite(const vector<vector<int> >& adj, vector<int>& colors, int src) {
    queue<int> q;
    q.push(src);
    colors[src] = 0; // Start coloring the source with color 0
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (colors[v] == -1) { // If the vertex is not colored
                colors[v] = 1 - colors[u]; // Color with the opposite color
                q.push(v);
            } else if (colors[v] == colors[u]) {
                return false; // If the adjacent vertex has the same color, it's not bipartite
            }
        }
    }
    return true;
}

vector<int> minimumColors(int N, int E, ll U[], ll V[]) {
    vector<vector<int> > adj(N);
    vector<int> colors(N, -1); // -1 means uncolored

    // Create adjacency list
    for (int i = 0; i < E; i++) {
        adj[U[i] - 1].push_back(V[i] - 1);
        adj[V[i] - 1].push_back(U[i] - 1);
    }

    bool bipartite = true;
    for (int i = 0; i < N; i++) {
        if (colors[i] == -1) {
            if (!isBipartite(adj, colors, i)) {
                bipartite = false;
                break;
            }
        }
    }

    return colors;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> Ufraizen(m);
    vector<ll> Vfraizen(m);
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        Ufraizen[i] = u;
        Vfraizen[i] = v;
    }

    vector<int> colors = minimumColors(n, m, Ufraizen.data(), Vfraizen.data());
    int minColor = *max_element(colors.begin(), colors.end()) + 1; // Adjust color count

    // cout << "min color = " << minColor << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << colors[i] << " ";
    // }
    // cout << endl;

    if (minColor >= 3) { // Choose Alice and always pick colors 1 and 2
        cout << "Alice" << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ' << 2 << endl;
            int vertex, colorcito;
            cin >> vertex >> colorcito;
        }
    } else { // Choose Bob
        cout << "Bob" << endl;
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for (int i = 0; i < m; i++) {
            adj[Ufraizen[i] - 1].push_back(Vfraizen[i] - 1);
            adj[Vfraizen[i] - 1].push_back(Ufraizen[i] - 1);
        }
        vector<int> vecinos;
        int color[n];
        memset(color, -1, sizeof(color));
        int primerColor = -1;
        rep(j,0,n){
            colors[j] = colors[j]+1;
        }
        vector<int> c1, c2;
        fr(0,n){
            if (colors[i] == 1){
                c1.push_back(i);
            } else {
                c2.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int color1, color2;
            cin >> color1 >> color2;
            if (i == 0) {
                cout << 1 << ' ' << color1 << endl;
                visited[0] = true;
                for (int neighbor : adj[0]) {
                    vecinos.push_back(neighbor);
                    visited[neighbor] = true;
                }
                color[0] = color1;
                primerColor = color1;
            } else {
                bool salir = false;
                fre(c1){
                    if (color[e] == -1){
                        //veo si esta el colorPrimerio
                        if (primerColor == color1){
                            cout << e << ' ' << color1 << endl;
                            for(auto e2: adj[e]){
                                vecinos.push_back(e2);
                                visited[e2] = true;
                            }
                            color[e] = color1;
                            salir = true;
                            break;
                        } else if (primerColor == color2){
                            cout << e << ' ' << color1 << endl;
                            for(auto e2: adj[e]){
                                vecinos.push_back(e2);
                                visited[e2] = true;
                            }
                            color[e] = color1;
                            salir = true;
                            break;
                        }
                    }
                }
                if(salir){
                    continue;
                }
                //ya pinte todos los del color 1 creo
                fre(c2){
                    if (color[e] == -1){
                        if (color1 != primerColor){
                            cout << e+1 << ' ' << color1 << endl;
                            for(auto e2: adj[e]){
                                vecinos.push_back(e2);
                                visited[e2] = true;
                            }
                            color[e] = color1;
                            salir = true;
                            break;
                        } else if (primerColor != color2){
                            cout << e+1 << ' ' << color1 << endl;
                            for(auto e2: adj[e]){
                                vecinos.push_back(e2);
                                visited[e2] = true;
                            }
                            color[e] = color1;
                            salir = true;
                            break;
                        }
                    }
                }
                fr(0,n){
                    if (color[i]==-1){
                        color[i] = color1;
                    }
                }

                //TODO. 
                // PAINT HERE. 
                //i have to paint all the primer color
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }

    return 0;
}