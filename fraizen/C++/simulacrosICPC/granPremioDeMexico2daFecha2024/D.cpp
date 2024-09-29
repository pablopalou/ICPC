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
#define MOD 1000000007
#define MAXN 801
ll dp[2][MAXN*9*2+100]; //dejo las ultimas dos filas o columnas como sea.
//dp[N][suma] => cantidad de parejas de N digitos que la resta de digitos entre a y b, es suma.
//para lidiar con negativo, a todo le sumamos 7200. 
#define offset 7200

ll ans[MAXN];

void solve() {
    memset(dp, 0, sizeof(dp));
    int n = 801; 
    fr(0,n+1) ans[i] = 0;
    dp[0][offset] = 1;
    ans[0] = 1;
    int maxi = 1;
    fr(1,n+1){
        rep(j,0,maxi*2){
            // cout << "I = " << i << ", j = " << j << endl;
            // if (dp[0][offset-maxi+j] != -1){
                // cout << "estoy en " << offset-maxi+j << endl;
                // cout << "dp => " << dp[0][offset-maxi+j] << endl;
                rep(na, 0, 10){
                    rep(nb,0,10){
                        if (na == nb) continue;
                        dp[1][offset-maxi+j+na-nb] = (dp[1][offset-maxi+j+na-nb] + dp[0][offset-maxi+j]) % MOD;
                        // cout << "actualizo dp[" << i << ", "<<offset-maxi+j+na-nb << "]=" << dp[1][offset-maxi+j+na-nb] <<endl;
                        //me parece que aca estoy sumando muchas veces el mismo valor, llamar a la dp de 0..
                        if (offset-maxi+j+na-nb == offset && na!=0 && nb!=0){
                            ans[i] = (ans[i] + dp[0][offset-maxi+j]) % MOD; 
                        }
                    }
                }
            // }
            // cout << dp[1][offset-maxi+j] << " "; 
        }
        swap(dp[1],dp[0]);
        fill(dp[1]+offset-maxi, dp[1]+offset+maxi+5, 0); //me parece que quedo mal
        maxi+=9;
        // cout << "ANS " << i << " = " << ans[i] << endl;
    }

    int q; cin >> q;
    fr(0,q){
        int fraizen; cin >> fraizen;
        cout << ans[fraizen] << '\n';
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