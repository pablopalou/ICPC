// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define pb push_back
// #define forr(i, a, b) for (int i = (a); i < (b); i++)
// #define forn(i, n) forr(i, 0, n)
// #define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
// #define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
// #define sz(c) ((int)c.size())

EL C2.CPP FUNCIONA
// struct Edge {
//   int u, v;
//   ll cap, flow;
//   Edge() {}
//   Edge(int uu, int vv, ll c) : u(uu), v(vv), cap(c), flow(0) {}
// };

// struct Dinic {
//   int N;
//   vector<Edge> E;
//   vector<vector<int>> g;
//   vector<int> d, pt;
//   Dinic(int n) : N(n), g(n), d(n), pt(n) {}  // clear and init
//   void addEdge(int u, int v, ll cap) {
//     if (u != v) {
//       g[u].pb(sz(E));
//       E.pb({u, v, cap});
//       g[v].pb(sz(E));
//       E.pb({v, u, 0});
//     }
//   }
//   bool BFS(int S, int T) {
//     queue<int> q({S});
//     fill(d.begin(), d.end(), N + 1);
//     d[S] = 0;
//     while (!q.empty()) {
//       int u = q.front();
//       q.pop();
//       if (u == T) break;
//       for (int k : g[u]) {
//         Edge& e = E[k];
//         if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
//           d[e.v] = d[e.u] + 1;
//           q.push(e.v);
//         }
//       }
//     }
//     return d[T] != N + 1;
//   }
//   ll DFS(int u, int T, ll flow = -1) {
//     if (u == T || flow == 0) return flow;
//     for (int& i = pt[u]; i < sz(g[u]); ++i) {
//       Edge& e = E[g[u][i]];
//       Edge& oe = E[g[u][i] ^ 1];
//       if (d[e.v] == d[e.u] + 1) {
//         ll amt = e.cap - e.flow;
//         if (flow != -1 && amt > flow) amt = flow;
//         if (ll pushed = DFS(e.v, T, amt)) {
//           e.flow += pushed;
//           oe.flow -= pushed;
//           return pushed;
//         }
//       }
//     }
//     return 0;
//   }
//   ll maxFlow(int S, int T) {  // O(V^2*E), unit nets: O(sqrt(V)*E)
//     ll total = 0;
//     while (BFS(S, T)) {
//       fill(pt.begin(), pt.end(), 0);
//       while (ll flow = DFS(S, T)) total += flow;
//     }
//     return total;
//   }
// };

// int color[2505];
// vector<vector<int> > adj(2505);

// void dfs(int node, int c){
//     if (color[node] != -1){
//         return;
//     }
//     color[node] = c;
//     fre(adj[node]){
//         if (color[e] == -1){
//             dfs(e, 1-c);
//         }
//     }
// }

// // Copiar obligatoriamente 0
// void solve() {
//     //leer grafo
//     int n,m;cin>>n>>m;
//     vector<vector<int> > adj(n+2);
//     char g[n][m];
//     vector<int> posibles;
//     bool first = true;
//     int fraizen = -1;
//     fr(0,n){
//         rep(j,0,m){
//             char c; cin >> c;
//             g[i][j] = c;
//             if (first && c == '.'){
//                 first = false;
//                 fraizen = i*m + j;
//             }
//         }
//     }
//     if (fraizen == -1){
//         cout << "0\n"; return;
//     }
//     memset(color, -1, sizeof(color));
//     //armar el grafo
//     fr(0,n){
//         rep(j,0,m){
//             if (g[i][j] == '.'){
//                 if (i < n-1 && g[i+1][j] == '.'){
//                     // adj[i*m+j].pb((i+1)*m + j);
//                     adj[(i+1)*m+j].pb(i*m+j);
//                 }
//                 if (j < m-1 && g[i][j+1] == '.'){
//                     adj[i*m+j].pb(i*m + j+1);
//                     adj[i*m + j+1].pb(i*m+j);
//                 }
//             }
//         }
//     }
//     dfs(fraizen, 0);
//     Dinic d = Dinic(n*m+2);
//     fr(0,n){
//         rep(j,0,m){
//             if (g[i][j] == '.'){
//                 // if (color[i*m+j] == -1){
//                 //     if (i < n-1 && (color[(i+1) * m + j] == 0 || color[(i+1) * m + j] == 1)){
//                 //         color[i*m+j] = 1-color[(i+1) * m + j];
//                 //     } else if (j < m-1 && (color[(i) * m + j+1] == 0 || color[(i) * m + j+1] == 0)){
//                 //         color[i*m+j] = 1- color[i*m + j + 1];
//                 //     } else {
//                 //         color[i*m+j] = 0;
//                 //     }
//                 //     // if (i < n-1 && color[(i+1) * m + j] == -1 && j < m-1 && color[(i) * m + j+1] == -1){
//                 //     //     color[i*m+j] = 0;
//                 //     //     cout << "Pinto " << i*m+j << " con " << 0 << endl;
//                 //     // } else if (i < n-1 && (color[(i+1) * m + j] == 0 || color[(i+1) * m + j] == 1)) {
//                 //     //     color[i*m+j] = 1-color[(i+1) * m + j];
//                 //     // } else if (i < m-1 && )
//                 // }
//                 int cur = color[i*m+j];
//                 if (cur == 0){
//                     if (i < n-1){
//                         if (g[i+1][j] == '.'){
//                             d.addEdge(i*m + j + 2, (i+1)*m + j + 2, 1);
//                             color[(i+1)*m + j] = 1-cur;
//                         }
//                     }
//                     if (j < m-1){
//                         if (g[i][j+1] == '.'){
//                             d.addEdge(i*m + j +2, i*m + j+1 + 2, 1);
//                             color[(i*m) + j + 1] = 1-cur;
//                         }
//                     }
//                 } else {
//                     if (i < n-1){
//                         if (g[i+1][j] == '.'){
//                             d.addEdge((i+1)*m + j + 2,i*m + j + 2, 1);
//                             color[(i+1)*m + j] = 1-cur;
//                         }
//                     }
//                     if (j < m-1){
//                         if (g[i][j+1] == '.'){
//                             d.addEdge(i*m + j+1 + 2,i*m + j +2, 1);
//                             color[(i*m) + j + 1] = 1-cur;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     fr(0,n*m){
//         cout << color[i] << ' ';
//     }
//     cout << endl;
//     //tendria que hacer coloracion para saber cual conectar al sink y cual al source. 
//     rep(k,0,n*m){
//         if (color[k] == 0){
//             d.addEdge(0, k + 2, 1);
//         } else if (color[k] == 1){
//             d.addEdge(k + 2, 1, 1);
//         }
//     }
//     int flow = d.maxFlow(0,1); 
//     cout << "FLUJO REAL " << flow << endl;
//      fre(d.E){
//             cout << e.u - 2 << ' ' << e.v -2 << ' ' << e.cap << endl;
//         }
//         cout << endl;

//         cout << endl;

//     int res = 0;
//     //para cada una que se pueda correr, armo el grafo y corro maxflow
//     // rep(k,0,n*m){
//     //     // cout << "ESTOY EN K = " << k << endl;
//     //     // cout << k/m << " " << k%n << endl;
//     //     if (g[k/m][k%m] == '#'){
//     //         // cout << "NO DBEERIA HACER FLUJO" << endl;
//     //         continue;
//     //     }
//     //     Dinic d = Dinic(n*m+2);
//     //     memset(color, -1, sizeof(color));
//     //     fr(0,n){
//     //         rep(j,0,m){
//     //             if (g[i][j] == '.'){
//     //                 if (i*m + j == k){
//     //                     continue;
//     //                 }
//     //                 if (color[i*m+j] == -1){
//     //                     if (i < n-1 && (color[(i+1) * m + j] == 0 || color[(i+1) * m + j] == 1)){
//     //                         color[i*m+j] = 1-color[(i+1) * m + j];
//     //                     } else if (j < m-1 && (color[(i) * m + j+1] == 0 || color[(i) * m + j+1] == 0)){
//     //                         color[i*m+j] = 1- color[i*m + j + 1];
//     //                     } else {
//     //                         color[i*m+j] = 0;
//     //                     }
//     //                     // if (i < n-1 && color[(i+1) * m + j] == -1 && j < m-1 && color[(i) * m + j+1] == -1){
//     //                     //     color[i*m+j] = 0;
//     //                     //     cout << "Pinto " << i*m+j << " con " << 0 << endl;
//     //                     // } else if (i < n-1 && (color[(i+1) * m + j] == 0 || color[(i+1) * m + j] == 1)) {
//     //                     //     color[i*m+j] = 1-color[(i+1) * m + j];
//     //                     // } else if (i < m-1 && )
//     //                 }
//     //                 int cur = color[i*m+j];
//     //                 if (cur == 0){
//     //                     if (i < n-1){
//     //                         if (g[i+1][j] == '.' && (i+1)*m + j != k){
//     //                             d.addEdge(i*m + j + 2, (i+1)*m + j + 2, 1);
//     //                             color[(i+1)*m + j] = 1-cur;
//     //                             cout << "Pinto " << (i+1)*m+j << " con " << cur << endl;
//     //                         }
//     //                     }
//     //                     if (j < m-1 && k!= i*m + j+1){
//     //                         if (g[i][j+1] == '.'){
//     //                             d.addEdge(i*m + j +2, i*m + j+1 + 2, 1);
//     //                             color[(i*m) + j + 1] = 1-cur;
//     //                             cout << "Pinto " << i*m+j+1 << " con " << cur << endl;
//     //                         }
//     //                     }
//     //                 } else {
//     //                     if (i < n-1){
//     //                         if (g[i+1][j] == '.' && (i+1)*m + j != k){
//     //                             d.addEdge((i+1)*m + j + 2,i*m + j + 2, 1);
//     //                             color[(i+1)*m + j] = 1-cur;
//     //                             cout << "Pinto " << (i+1)*m+j << " con " << cur << endl;
//     //                         }
//     //                     }
//     //                     if (j < m-1 && k!= i*m + j+1){
//     //                         if (g[i][j+1] == '.'){
//     //                             d.addEdge(i*m + j+1 + 2,i*m + j +2, 1);
//     //                             color[(i*m) + j + 1] = 1-cur;
//     //                             cout << "Pinto " << i*m+j+1 << " con " << cur << endl;
//     //                         }
//     //                     }
//     //                 }
//     //             }
//     //         }
//     //     }
//     //     rep(k,0,n*m){
//     //         if (color[k] == 0){
//     //             d.addEdge(0, k + 2, 1);
//     //         } else if (color[k] == 1){
//     //             d.addEdge(k + 2, 1, 1);
//     //         }
//     //     }
//     //     // fre(d.E){
//     //     //     cout << e.u - 2 << ' ' << e.v -2 << endl;
//     //     // }
//     //     // cout << endl;
//     //     int curFlow = d.maxFlow(0,1);
//     //     // cout << "FLUJO = "<< curFlow << endl;
//     //     // cout << endl;
//     //     if (curFlow == flow){
//     //         res++;
//     //     }

//     // }

//     cout << res << "\n";
// }

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     // cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }
