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
#define MAXN 1003
#define MAXM 102
int mat[MAXN][MAXM];
int n,m;
bool vis[MAXN][MAXM];

bool compatible(int i, int j){
    //me fijo si la tira i no tiene muros donde la tira del inicio rotada j, quiere poner algo
    bool res = true;
    rep(cur,0,m){
        if (mat[i][cur] == 1 && mat[0][(j+cur)%m] == 1){
            res = false;
        }
    }
    return res;
}

bool valid(int i, int j){
    if (i < 0) return false;
    if (i == n) return true; //legue al final, retorno que es valido
    if (vis[i][j]) return false; //no deberia llegar aca.
    vis[i][j] = true;
    //veo si puedo ir para arriba, izquierda, derecha y abajo
    bool puedo = false;
    if (!vis[i+1][j] && compatible(i+1,j)){ //abajo
        puedo |= valid(i+1,j);
    }
    if (!vis[i-1][j] && compatible(i-1,j)){//arriba
        puedo|=valid(i-1,j);
    }
    if (!vis[i][(j-1+m)% m] && compatible(i, (j-1+m)% m)){
        puedo|=valid(i,(j-1+m)% m);
    }
    if (!vis[i][(j+1)% m] && compatible(i, (j+1)% m)){
        puedo|=valid(i,(j+1)% m);
    }
    return puedo;
}

void solve() {
    cin >>n >>m;
    fr(0,n+1){
        string s; cin >> s;
        rep(j,0,m){
            mat[i][j] = (s[j]=='1');
        }
    }
    // fr(0,n+1){ rep(j,0,m){
    //     cout << mat[i][j] << ' ';
    // }
    // cout << endl;}
    bool ans = false;
    fr(0,MAXN) rep(j,0,MAXM) vis[i][j] = false;
    fr(0,m){
        ans |= valid(0,i);
    }
    reverse(mat[0], mat[0]+m);
    fr(0,MAXN) rep(j,0,MAXM) vis[i][j] = false;
    fr(0,m){
        ans |= valid(0,i);
    }
    if (ans){
        cout <<"Y\n";
    } else {
        cout <<"N\n";
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