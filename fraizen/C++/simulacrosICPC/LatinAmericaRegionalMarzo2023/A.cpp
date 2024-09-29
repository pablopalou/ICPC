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

//tengo que ver si con un padre y sus dos hijos, en el grafo reverso los 3 llegan a un mismo nodo. Si llegan los 3 al mismo, esto significaria que arrancando en ese nodo,
//este podria pedirle al padre y a los dos hijos, entonces luego el padre no podria recuperar. El padre en este caso pierde plata. 

#define MAXN 1010
vector<int> g[MAXN];
vector<int> rev[MAXN]; //grafo reverso
bool visited[3][MAXN];

void dfs(int i, int num, int proh){
    visited[num][i] = true;
    fre(rev[i]){
        if (!visited[num][e] && e != proh){
            dfs(e, num, proh);
        }
    }
}

void solve() {
    int n; cin >> n;
    fr(0,n){
        int u,v; cin >> u >> v; u--; v--;
        g[i].pb(u);
        g[i].pb(v);
        rev[u].pb(i);
        rev[v].pb(i);
    }
    bool ans[n]; fr(0,n) ans[i] = false;
    fr(0,n){ //veo si pierde este padre
        rep(j,0,3) rep(k,0,MAXN) visited[j][k] = false;
        //hago el dfs de el mismo y sus dos hijos
        dfs(i, 0, i);
        dfs(g[i][0], 1, i);
        dfs(g[i][1], 2, i);
        rep(j,0,n){
            if (i!=j && visited[0][j] && visited[1][j] && visited[2][j]){
                ans[i] = true;
                break;
            }
        }
    }
    fr(0,n){
        if (ans[i]){
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    cout << '\n';
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