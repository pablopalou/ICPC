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

ll eulerPhi2(ll n) {  // O (sqrt n)
  ll r = n;
  forr(i, 2, n + 1) {
    if ((ll)i * i > n) break;
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      r -= r / i;
    }
  }
  if (n != 1) r -= r / n;
  return r;
}

ll expMod(ll b, ll e, ll m) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

ll inverso(ll x, ll mod) {                    
  return expMod(x, eulerPhi2(mod) - 1, mod);
}
#define MAXN 200100
ll inv[MAXN];
ll m = 0;

void solve() {
    // buscarPrimos();
    ll b, n; cin >> b >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    ll mod = b+1;
    //tengo que ver el modulo actual..
    fr(0,n){
        m = (((m%(mod) * b%mod)%mod) + (a[i]%mod))% mod;
    }
    if (m == 0){
        cout << "0 0\n"; return;
    }
    ll potB = 1;
    fr(0,n){
        inv[n-1-i] = inverso(potB, mod);
        potB = ((potB%mod) * (b%mod)) % mod;
    }
    // fr(0,n){
    //     cout << inv[i] << " ";
    // }
    // cout << endl;

    //veo del mas grande al mas chico, cual puedo decrementar
    //basicamente tengo que decrementar en m al modulo.
    //si c[i] es le digito que quiero en i, entonces necesito (a[i] - c[i]) * b^i = m (mod b+1) para poder sacar m del modulo y que quede multiplo de b+1. (Ademas necesito a[i] > c)
    fr(0,n){
        ll dif = (m*(inv[i]%mod))%mod;
        if (dif <= a[i]){
            cout << i+1 << ' ' << a[i]-dif << endl;
            return;
        }
    }
    cout << "-1 -1\n";
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