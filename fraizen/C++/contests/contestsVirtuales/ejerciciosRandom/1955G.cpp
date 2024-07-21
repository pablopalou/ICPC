#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n,m; cin >> n >>m;
    int a[n][m];
    fr(0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }
    int g = gcd(a[0][0], a[n-1][m-1]);
    int ans = 1;
    //yo necesito probar solo los divisores de g, no sirve hacer todo el loop, 
    //hacer hasta raiz de n y luego probar el otro divisor
    fr(1, sqrt(g) + 1){
        if (g % i != 0) continue;
        vector<int> sirve = {i, g/i};
        // cout << "Pruebo " << i << endl;
        //i divide a g, podría ser una respuesta.
        rep(fraizen, 0,2){
            bool dp[n][m];
            memset(dp, sizeof(dp), false);
            dp[0][0] = true;
            rep(j, 0, n){
                rep(k, 0, m){
                    if (j == 0 && k == 0){
                        dp[0][0] = true; continue;
                    }
                    if (a[j][k] % (sirve[fraizen]) != 0){
                        dp[j][k]= false; //ya esta inicializado en false
                        // cout << "Pongo dp["<< j << "]["<<k<<"] = " << dp[j][k] << endl;
                        // cout << "continue " << endl;
                        continue;
                    }
                    if (j > 0 && dp[j-1][k] || (k>0 && dp[j][k-1])){
                        dp[j][k] = true;
                    } else {
                        dp[j][k] = false;
                    }
                    // cout << "Pongo dp["<< j << "]["<<k<<"] = " << dp[j][k] << endl;
                }
            }
            if (dp[n-1][m-1]){
                ans = max(ans, sirve[fraizen]);
            }
        }
    }
    cout << ans << '\n';
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