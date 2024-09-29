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

void solve() {
    ll n,t; cin >> n >> t;
    ll row[n];
    ll col[n];
    ll rowcol[n];
    ll maxiRowCol = 0;
    ll maxRow = 0;
    ll maxCol = 0;
    fr(0,n){
        rowcol[i]=0; row[i]= 0; col[i] = 0;
    }
    ll caminos = 0;
    fr(0,t){
        int u,v; cin >> u >> v; u--; v--;
        //se suma uno a la fila u, y uno a la columna v. Ojo si son iguales que suma 1 mas.
        caminos += col[u];
        caminos += row[v];
        if (u == v) caminos++;
        row[u]++;
        col[v]++;
        rowcol[u]++;
        rowcol[v]++;
        maxiRowCol = max(maxiRowCol, max(rowcol[u], rowcol[v]));
        maxRow = max(maxRow, row[u]);
        maxCol = max(maxCol, col[v]);
        //se puede actualizar con (rowx + coly) o (rowx+colx+1)
        cout << caminos << " " << max(maxRow+maxCol, maxiRowCol+1)<< endl;
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