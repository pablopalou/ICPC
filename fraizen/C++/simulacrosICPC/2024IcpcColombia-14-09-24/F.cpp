#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
    int n,m; cin >> n >> m;
    char mat[n][m];
    fr(0,n) rep(j,0,m) cin >> mat[i][j];
    pair<int,int> posP, posG;
    fr(0,n) rep(j,0,m) {
        if (mat[i][j] == 'P') posP = {i,j};
        if (mat[i][j] == 'G') posG = {i,j}; 
    }
    string s; cin >> s;
    int i = posP.first;
    int j = posP.second;
    //muevo el pacman
    int tiempo[n][m];
    memset(tiempo, -1, sizeof(tiempo));
    int curTime = 1;
    fre(s){
        if (e == 'R'){
            if (mat[i][(j+1)%m] != '#'){
                j = (j+1)%m;
            }
        } else if (e=='L'){
            if (mat[i][(((j-1)%m)+m)%m] != '#'){
                j = (((j-1)%m)+m)%m;
            }
        } else if (e=='D'){
            if (mat[(i+1)%n][j] != '#'){
                i = (i+1)%n;
            }
        } else {
            if (mat[(((i-1)%n)+n)%n][j] != '#'){
                i = (((i-1)%n)+n)%n;
            }
        }
        tiempo[i][j] = curTime;
        curTime++;
    }
    // fr(0,n){
    //     rep(j,0,m){
    //         cout << tiempo[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //hago BFS desde el coso
    queue<pair<int, int>> q;
    q.push(posG);
    int dist[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }
    dist[posG.first][posG.second] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int current_distance = dist[p.first][p.second];
        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int newX = p.first + dx[i];
            int newY = p.second + dy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= m)
                continue;
            if (mat[newX][newY] == '#')
                continue;
            if (dist[newX][newY] == -1) {
                dist[newX][newY] = current_distance + 1;
                if (dist[newX][newY] <= tiempo[newX][newY]) {
                    cout << "Yes\n";
                    return;
                }
                q.push({newX, newY});
            }
        }
    }
    cout << "No\n";
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}