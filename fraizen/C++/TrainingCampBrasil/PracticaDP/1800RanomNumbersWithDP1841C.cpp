#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define inf 1e18;

// Copiar obligatoriamente 0
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll dp[2][5][2]; //posicion i depende solo de la i-1 entonces llevo dos filas, luego la letra maxima y por ultimo si ya cambie o no.
    fr(0,5){
        rep(j,0,2){
            dp[0][i][j] = -inf;
        }
    }
    dp[0][0][0] = 0;
    map<char, int> valor;
    valor[0] = 1;
    valor[1] = 10;
    valor[2] = 100;
    valor[3] = 1000;
    valor[4] = 10000;
    for (char c: s){
        int x = c - 'A';
        //pongo todo en -inf;
        fr(0,5){
            rep(j,0,2){
                dp[1][i][j] = -inf;
            }
        }

        for (int j = 0; j < 5; j++){
            for (int t = 0; t < 2; t++){
                for (int newValue = 0; newValue <5; newValue++){
                    bool cambio = newValue != x;
                    if (t && cambio){
                        continue;
                    }
                    int newJ = max(j, newValue);
                    int newT = t;
                    if (cambio) {
                        newT = 1;
                    }
                    dp[1][newJ][newT] = max(dp[1][newJ][newT], dp[0][j][t] + (newJ > newValue ? - valor[newValue] :+ valor[newValue]));
                }
            }
        }
        //swapeo
        swap(dp[0], dp[1]);
    }

    ll ans = -inf;
    fr(0,5){
        rep(j,0,2){
            ans = max(ans, dp[0][i][j]);
        }
    }
    cout << ans << "\n";
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