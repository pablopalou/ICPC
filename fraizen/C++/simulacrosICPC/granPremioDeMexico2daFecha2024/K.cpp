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
const ll MOD = 1000000007;  // Change according to problem

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
// struct frac {
//   ll p, q;
//   frac(ll p = 0, ll q = 1) : p(p), q(q) { norm(); }
//   void norm() {
//     ll a = gcd(q, p);
//     if (a) {
//         p /= a, q /= a;
//     }
//     else q = 1;
//     if (q < 0) q = -q, p = -p;
//   }
//   frac operator+(const frac& o) {
//     ll a = gcd(o.q, q);
//     return frac(p * (o.q / a) + o.p * (q / a), q * (o.q / a));
//   }
//   frac operator-(const frac& o) {
//     ll a = gcd(o.q, q);
//     return frac(p * (o.q / a) - o.p * (q / a), q * (o.q / a));
//   }
//   frac operator*(frac o) {
//     ll a = gcd(o.p, q), b = gcd(p, o.q);
//     return frac((p / b) * (o.p / a), (q / a) * (o.q / b));
//   }
//   frac operator/(frac o) {
//     ll a = gcd(o.q, q), b = gcd(p, o.p);
//     return frac((p / b) * (o.q / a), (q / a) * (o.p / b));
//   }
//   bool operator<(const frac& o) const { return p * o.q < o.p * q; }
//   bool operator==(frac o) { return p == o.p && q == o.q; }
// };

ll inverso(ll x) {                    // O(log MOD)
  return expMod(x, MOD - 2);            // si mod es primo
}

void solve() {
    ll n,k; cin >> n >> k;
    ll e[1000100];
    if (k > n){
        e[n+1] = 0;
        for(int i = n;i>=0;i--){
            e[i] = (1 + (e[i+1] * (((n-i)%MOD) * (inverso(n) % MOD) % MOD)) % MOD) % MOD;
        }
        cout << e[0]% MOD << '\n';
        return;
    }
    n%=MOD;
    //k <= n
    //el caso base es cuando llego a k computadoras, porque ahi tengo e[k] = e[k+1] = e[k+2] ...
    e[k] = ((n % MOD) * (inverso(k-1)%MOD)) % MOD;
    for(int i = k-1;i>=0;i--){
        e[i] = (1 + (e[i+1] * (((n-i)%MOD) * (inverso(n) % MOD) % MOD)) % MOD) % MOD;
    }
    cout << e[0]<< '\n';
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