#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forn(i, n) forr(i, 0, n)
#define MAXN 1010
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define MOD 1000000007
ll comb[1010][1010];

void cargarComb() {  // O(MAXN^2)
  forn(i, MAXN) {    // comb[i][k]=i tomados de a k = i!/(k!*(i-k)!)
    comb[0][i] = 0;
    comb[i][0] = comb[i][i] = 1;
    forr(k, 1, i) comb[i][k] = (comb[i - 1][k - 1] + comb[i - 1][k]) % MOD;
  }
}
ll lucas(ll n, ll k, int p = MOD) {  // (n,k)%p, needs comb[p][p] precalculated
  ll aux = 1;
  while (n + k) {
    aux = (aux * comb[n % p][k % p]) % p;
    n /= p, k /= p;
  }
  return aux;
}

void solve() {
    int n; cin >> n; int c[n];
    fr(0,n) cin >> c[i];
    cargarComb();
    ll dp[n]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int bolas = c[0];
    fr(1,n){
        int n = bolas + 1;
        int m = c[i] - 1;
        dp[i] = (dp[i-1] % MOD * (lucas(n+m-1, m))) % MOD;
        bolas += c[i];
    }
    cout << dp[n-1] << "\n";
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
