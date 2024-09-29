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
#define MAXN 504
#define inf 1e9+10

ll dp[MAXN][MAXN];
ll n,m;
ll mat[MAXN][MAXN];

//OJO QUE DE ESTA FORMA QUEDAMOS EN LOOP, no podemos transicionar a la derecha y a la izquierda asi nomas...
// ll f(ll i, ll j){
//     if (i == 0){ //caso base, ya lo calcule antes
//         return dp[i][j];
//     }
//     ll &res = dp[i][j];
//     ll best = inf;
//     if (j>0){
//         best = min(best, f(i, j-1));
//     }
//     if (j<m-1){
//         best = min(best, f(i, j+1));
//     }
//     best = min(best, f(i-1,j));
//     res = max(res, best);
//     return res;
// }

void solve() {
    cin >> n >> m;  
    fr(0,n){
        rep(j,0,m){
            cin >> mat[i][j];
            dp[i][j] = inf;
        }
    }  
    dp[0][0] = 0;
    fr(1,m){
        dp[0][i] = max(mat[0][i], dp[0][i-1]); 
    }    
    fr(1,n){
        rep(j,0,m){
            //me guardo un array que indique desde k hasta algo, cual es el maximo. 
            ll a[m];
            a[j] = mat[i][j];
            ll l = j-1;
            while(l >= 0){
                a[l] = max(mat[i][l], a[l+1]);
                l--;
            }
            ll r = j+1;
            while(r <= m-1){
                a[r] = max(mat[i][r], a[r-1]);
                r++;
            }
            rep(k,0,m){
                //baje en k, entonces... 
                dp[i][j] = min(dp[i][j], max(dp[i-1][k], a[k]));
            }
        }
    }
    cout << dp[n-1][m-1] << '\n';
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