#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forn(i, n) forr(i, 0, n)
#define MAXN 500200
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define MOD 1000000007
#define dforn(i,n) for(int i=n-1; i>=0; i--)

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
// fact[i] = i!%MOD and ifact[i] = 1/(i!)%MOD
// inv is modular inverse function
ll fact[MAXN], ifact[MAXN];
void build_facts() {  // O(MAXN)
  fact[0] = 1;
  forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
  ifact[MAXN - 1] = inverso(fact[MAXN - 1]);
  dforn(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
  return;
}
// n! / k!*(n-k)!
// assumes 0 <= n < MAXN
ll comb(ll n, ll k) {
  if (k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

void solve() {
    ll n; cin >> n; ll a[n+1]; fr(0,n+1) cin >> a[i];
    ll ans = 0;
    build_facts();
    fr(0,n+1){
        ans = (ans % MOD + (comb(i + a[i], i+1) % MOD) ) % MOD;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}
