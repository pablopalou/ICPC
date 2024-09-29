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

// struct UnionFind {
//     int nsets;
//     vector<int> f,setsz;
//     UnionFind(int n): nsets(n), f(n,-1), setsz(n,1){}
//     int comp(int x){return (f[x]==-1?x:f[x]=comp(f[x]));}
//     bool join(int i,int j){
//         int a = comp(i), b = comp(j);
//         if (a!=b){
//             //ACA UNIR EN EL GRAFO
//             if (setsz[a] > setsz[b]) swap(a,b);
//             f[a] = b;
//             nsets--, setsz[b]+=setsz[a];
//         }
//         return a == b;
//     }
// };

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<int>> v(m, vector<int>());
    //grafo?
    fr(0,n){
        int cant; cin >> cant;
        rep(k,0,cant){
            int per; cin >> per;
            rep(j,0,v[per].size()){
                //TODO: 
                //conectar en el grafo: pelicula i con la pelicula de la persona (v[per][j]), si es que NO estan conectados todavia (valor de la arista seria la persona que conecta (per))
            }
            v[per].pb(i); //meto la pelicula en la persona
        }
    }
    int q; cin >> q;
    fr(0,q){
        int x,y; cin >> x >> y;
        //VEO SI PUEDO LLEGAR (TODO)
        if (! llego ){
            cout << "-1\n";
        } else {
            //TODO: PONER EL CAMINO con un dfs o algo
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