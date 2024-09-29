#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007
ll dp[502][63000];

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

ll inverso(ll x) {                    // O(log MOD)
//   return expMod(x, eulerPhi(MOD) - 1);  // si mod no es primo(sacar a mano)
  return expMod(x, MOD - 2);            // si mod es primo
}

void solve() {
    ll n; cin >> n;
    ll suma = n * (n+1) / 2;
    if (suma & 1){
        cout << "0\n"; return;
    }
    memset(dp, 0, sizeof(dp));
    suma /=2;
    // cout << "suma " << suma << endl;
    dp[1][0] = 1;
    dp[1][1] = 1;
    fr(2,n+1){
        for(ll j = suma; j >= 0; j--){
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0){
                dp[i][j] = (dp[i][j] % MOD + dp[i-1][j-i] % MOD) % MOD;
            }
        }
    }
    // fr(0,n+1){
    //     rep(j,0,suma + 1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[n][suma] % MOD * inverso(2) % MOD) % MOD<< "\n";
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