#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
 //local el primer caso anda y en cf se rompe
 //alguna variable debe no estar bien inicializada
struct HopcroftKarp {  // [0,n)->[0,m) (ids independent in each side)
    int n, m;
    vector<vector<int>> g;
    vector<int> mt, mt2, ds;
    HopcroftKarp(int nn, int mm) : n(nn), m(mm), g(n) {}
    void add(int a, int b) { g[a].push_back(b); }
    bool bfs() {
        queue<int> q;
        ds = vector<int>(n, -1);
        fr(0, n) if (mt2[i] < 0) ds[i] = 0, q.push(i);
        bool r = false;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x]) {
            if (mt[y] >= 0 && ds[mt[y]] < 0) {
                ds[mt[y]] = ds[x] + 1, q.push(mt[y]);
            } else if (mt[y] < 0) r = true;
            }
        }
        return r;
    }
    bool dfs(int x) {
        for (int y : g[x]) {
            if (mt[y] < 0 || ds[mt[y]] == ds[x] + 1 && dfs(mt[y])) {
            mt[y] = x, mt2[x] = y;
            return true;
            }
        }
        ds[x] = 1 << 30;
        return false;
    }
    int mm() {  // O(sqrt(V)*E)
        int r = 0;
        mt = vector<int>(m, -1);
        mt2 = vector<int>(n, -1);
        while (bfs()) fr(0, n) if (mt2[i] < 0) r += dfs(i);
        return r;
    }
};
 
void solve() {
    int n, m; cin >> n >> m;
    int c_row, c_col = 0;
    int color[n][m];
    int id_l = 0, id_r = 0;
    map<int, int> pos_to_id;
    rep(i, 0, n) {
        c_row ^= 1;
        c_col = c_row;
        rep(j, 0, m) {
            char in; cin >> in;
            if (in == '.') {
                color[i][j] = c_col;
                if (c_col==0) {
                    pos_to_id[i*m+j] = id_l;
                    id_l++;
                } else {
                    pos_to_id[i*m+j] = id_r;
                    id_r++;
                }
            } else color[i][j] = -1;
            c_col ^= 1;
        }
    }
    HopcroftKarp h(n*m, n*m);
    pair<int, int> moves[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(color[i][j]==0) {
                fre(moves) {
                    int new_x=i+e.first, new_y=j+e.second;
                    if (new_x>=0 && new_x<n && new_y>=0 && new_y<m) {
                        if(color[new_x][new_y]==1) {
                            h.add(pos_to_id[i*m+j], pos_to_id[new_x*m+new_y]);
                        }
                    }
                }
            }
        }
    }
    int mm = h.mm(), ans = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            HopcroftKarp new_hk = h;
            if (color[i][j] == 0) {
                // Saco ese nodo y corro mm de nuevo
                new_hk.g[pos_to_id[i*m+j]].clear();
                if (new_hk.mm() == mm) ans++;
            } else if (color[i][j] == 1) {
                // Lo busco en todos los nodos
                rep(k, 0, new_hk.g.size()) {
                    rep(z, 0, new_hk.g[k].size()) {
                        if (new_hk.g[k][z] == pos_to_id[i*m+j]) {
                            new_hk.g[k].erase(new_hk.g[k].begin()+z);
                        }
                    }
                }
                if (new_hk.mm() == mm) ans++;
            }
        }
    }
    cout(ans);
}
 
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    #ifdef JP
        freopen("A.in", "r", stdin);
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