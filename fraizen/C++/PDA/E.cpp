#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
int ent[1001];
int sal[1001];
#define pb push_back
int colored[1001];
bool impo = false;
vector<vector<int> > v(1001);

//siempre que le pase aca, no tengo que tener coloreado este nodo.
void dfs(int node, int color){
    colored[node] = color;
    fre(v[node]){
        if (colored[e]!=-1 && colored[e] == color){
            impo = true;
            return;
        } else if (colored[e]==-1){
            dfs(e, 1-color);
        }
    }
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    fr(1,2*n+1){
        string s; cin >> s;
        if (s[0] == '+'){
            ent[stoi(s.substr(1))] = i;
        } else {
            sal[stoi(s.substr(1))] = i;
        }
    }

    fr(1,n+1){
        rep(j, 1, n+1){
            if (ent[i] < ent[j] && ent[j] < sal[i] && sal[i] < sal[j]){
                v[i].pb(j);
                v[j].pb(i);
            }
        }
    }

    // fr(1,n+1){
    //     cout << i<<" => ";
    //     fre(v[i]){
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }

    //tengo que chequear si puedo pintar el grafo o no
    memset(colored, -1, sizeof(colored));
    fr(1,n+1){
        if (colored[i] == -1){
            dfs(i, 0);
        }
        if (impo){
            break;
        }
    }

    if (impo){
        cout << "*\n"; 
    } else {
        fr(1,n+1){
            if (colored[i] == 0){
                cout << "G";
            } else {
                cout << "S";
            }
        }
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