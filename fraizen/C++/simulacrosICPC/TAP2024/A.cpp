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

set<int> adj[9];
vector<vector<int>> grid(3, vector<int>(3,0)); // 0 significa que esta libre. 1 puso Alice (X, primero) y 2 puso el otro

int quienGana(){
    fr(0,3){
        if (grid[i][0] && grid[i][1] == grid[i][0] && grid[i][2] == grid[i][0]){
            return grid[i][0];
        }
    }
    fr(0,3){
        if (grid[0][i] && grid[1][i] == grid[0][i] && grid[2][i] == grid[0][i]){
            return grid[0][i];
        }
    }
    if (grid[0][0] && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        return grid[0][0];
    }
    if (grid[2][0] && grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2]){
        return grid[2][0];
    }
    return 0; //empate
}
int dp[20000][2];

int getMask(){
    int res = 0;
    fr(0,3){
        rep(j,0,3){
            res *= 3;
            res += grid[i][j];
        }
    }
    return res;
}

int f(int turno){
    int ganador = quienGana();
    if (ganador!=0) return ganador;
    int mask = getMask();
    int &res = dp[mask][turno];
    if (res != -1) return res;
    //voy por todos y veo si puedo poner y pongo...
    bool movi = false;
    vector<int> subproblemas;
    fr(0,3){
        rep(j,0,3){
            int cur = i*3 + j;
            bool can = grid[i][j] == 0;
            if (can){
                fre(adj[cur]){
                    if (grid[e/3][e%3] == 0){
                        can = false;
                    }
                }
            }
            if (!can) continue;
            movi = true;
            //puedo poner, entonces pongo el del turno digamos
            int poner = turno + 1;
            grid[i][j] = poner;
            subproblemas.pb(f(1-turno)); // 0 si es empate, 1 si gana X, 2 si gana O
            grid[i][j] = 0; //dejo el tablero como estaba
        }
    }
    if (!movi) {
        res = 0;
        return res;
    }
    if (turno == 0){
        fre(subproblemas){
            if (e == 1){
                res = 1;
                return res;
            } else if (e == 0){
                res = 0;
            } else {
                if (res == -1){
                    res = 2;
                }
            }
        }
    } else { // le toca jugar al 2
        fre(subproblemas){
            if (e == 2){ //si de alguna forma gano siempre, devuelvo eso
                res = 2;
                return res;
            } else if (e == 0){ //luego me sirve el empate
                res = 0;
            } else {
                if (res == -1){
                    res = 1; //pierdo si no hay otra 
                }
            }
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;
    fr(0,n){
        int a,b; cin >> a >> b; a--;b--;
        adj[b].insert(a);
    }
    memset(dp, -1, sizeof(dp));
    f(0); //le paso el turno nomas, la grid ya es global y la mascara la consigo adentro
    int res = dp[0][0];
    if (res == 0){
        cout << "E\n";
    } else if (res == 1){
        cout << "X\n";
    } else {
        cout << "O\n";
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}