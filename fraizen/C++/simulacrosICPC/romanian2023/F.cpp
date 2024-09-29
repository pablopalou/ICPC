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

ll mulMod(ll a, ll b, ll m) {  // O(log b)
  ll x = 0, y = a % m;
  while (b > 0) {
    if (b % 2 == 1) x = (x + y) % m;
    y = (y * 2) % m;
    b /= 2;
  }
  return x % m;
}

ll expMod(ll b, ll e, ll m ) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

ll suma(ll r, ll mod){
    if (r == 0){
        return 0;
    }
    if (r == 1){
        return 1;
    }
    if (r == 2){
        return 2;
    }
    ll potencias;
    if (r % 2 == 1){
        int mitad = r/2;
        ll fraizen = expMod(2,mitad, mod);
        potencias = fraizen - 1;
        potencias = mulMod(potencias,2, mod);
        //sumo el que estoy parado
        potencias = (potencias + fraizen) % mod;
    } else {
        int mitad = r/2;
        ll fraizen = expMod(2,mitad, mod);
        potencias = fraizen - 1;
        potencias = mulMod(potencias,2,mod);
    }
    return potencias;
}

void solve() {
    ll l,r,mod; cin >> l >> r >> mod;
    cout << ((suma(r,mod) - suma(l-1,mod)) + mod )% mod << '\n';
    // int f[100];
    // f[0]=1; f[1] = 1;
    // fr(2,100){
    //     f[i] = abs(f[i-1] - f[i-2]) ^ (f[i-1] + f[i-2]);
    // }
    // fr(0,100){
    //     cout << f[i] <<  " ";
    // }

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