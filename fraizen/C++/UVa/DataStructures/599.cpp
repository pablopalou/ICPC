#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
vector<vector<int> > adj(30);
#define pb push_back
bool visited[30];

void dfs(int node){
    visited[node] = true;
    fre(adj[node]){
        if (!visited[e]){
            dfs(e);
        }
    }
}

//deberia haber hecho algo mucho mas sencillo, contar cantidad de nodos, cantidad de acorns y cantidad de aristas. Con eso podia calcular los arboles.
// Copiar obligatoriamente 0
void solve() {
    string s;
    fr(0,30){
        adj[i].clear();
        visited[i] = false;
    }
    while(cin >> s){
        if (s[0] == '*') break;
        if (s.size() > 3){
            adj[s[1]-'A'].pb(s[3]- 'A');
            adj[s[3]-'A'].pb(s[1]- 'A');
        }
    }
    vector<int> nodos;
    cin >> s;
    for(auto c : s){
        if (c !=','){
            nodos.pb(c-'A');
        }
    }
    int trees = 0;
    int acorns = 0;
    fr(0,nodos.size()){
        if (! visited[nodos[i]]){
            if (adj[nodos[i]].size() == 0){
                acorns++;
            }
            dfs(nodos[i]);
            trees++;
        }
    }
    cout << "There are " << trees-acorns << " tree(s) and " << acorns << " acorn(s)." << "\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}