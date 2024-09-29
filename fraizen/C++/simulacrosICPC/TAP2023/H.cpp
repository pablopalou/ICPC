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
#define mp make_pair
int n;
#define MAXN 1002
int col[MAXN];
int fil[MAXN];
pair<int,int> par[MAXN*MAXN];
int dp[MAXN*MAXN][2];

// f(x,b) => cantidad de giros desde x en adelante, viniendo de b (b=0 -> vine de fila, b=1 -> vine de columna)
void solve() {
    memset(col, 0, sizeof(col));memset(fil, 0, sizeof(fil));
    cin >> n;
    fr(0,n){
        rep(j,0,n){
            int num; cin >> num; num--;
            par[num]=mp(i,j); 
        }
    }
    //tengo que ir recorriendo de atras pa adelante
    for(int i = n*n-1; i>=0; i--){
        int fila = par[i].first;
        int columna = par[i].second;
        dp[i][0] = col[columna] + 1;
        dp[i][1] = fil[fila] + 1;
        col[columna] = max(col[columna], dp[i][1]);
        fil[fila] = max(fil[fila], dp[i][0]);
    }
    //la respuesta es el maximo de todos
    int res = 0;
    fr(0,n*n){
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    cout << res << '\n';
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