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
const ll MOD = 1000000007; 
#define mp make_pair

ll mulMod(ll a, ll b, ll m = MOD) {  // O(log b)
  ll x = 0, y = a % m;
  while (b > 0) {
    if (b % 2 == 1) x = (x + y) % m;
    y = (y * 2) % m;
    b /= 2;
  }
  return x % m;
}

ll gcd (ll a, ll b) {
      while (b) {
        a %= b;
        swap(a, b);
      }
      return a;
}

ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = mulMod(ret,b,m);  // ret = mulMod(ret,b,m); //if needed
    b = mulMod(b,b,m);                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

ll expSinMod(ll b, ll e) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b;  // ret = mulMod(ret,b,m); //if needed
    b = b * b;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

bool es_primo_prob(ll n, int a) {
  if (n == a) return true;
  ll s = 0, d = n - 1;
  while (d % 2 == 0) s++, d /= 2;
  ll x = expMod(a, d, n);
  if ((x == 1) || (x + 1 == n)) return true;
  forn(i, s - 1) {
    x = mulMod(x,x,n);
    // x = (x * x) % n;  // mulMod(x, x, n);
    if (x == 1) return false;
    if (x + 1 == n) return true;
  }
  return false;
}

bool rabin(ll n) {  // devuelve true si n es primo
  if (n == 1) return false;
  const int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  forn(j, 9) if (!es_primo_prob(n, ar[j])) return false;
  return true;
}

ll rho(ll n) {
  if ((n & 1) == 0) return 2;
  ll x = 2, y = 2, d = 1;
  ll c = rand() % n + 1;
  while (d == 1) {
    // may want to avoid mulMod if possible
    // maybe replace with * operator using __int128?
    x = (mulMod(x, x, n) + c) % n;
    y = (mulMod(y, y, n) + c) % n;
    y = (mulMod(y, y, n) + c) % n;
    if (x - y >= 0) d = gcd(n, x - y);
    else d = gcd(n, y - x);
  }
  return d == n ? rho(n) : d;
}
void factRho(ll n, map<ll, ll>& f) {  // O ((n ^ 1/4) * logn) 500.000
  if (n == 1) return;
  if (rabin(n)) {
    f[n]++;
    return;
  }
  ll factor = rho(n);
  factRho(factor, f);
  factRho(n / factor, f);
}

void solve() {
    ll m,n,k; cin >> m>>n >> k;
    set<ll> res;
    fr(0,n){
        ll num; cin >> num;
        map<ll,ll> f;
        factRho(num,f);
        fre(f){
            res.insert(e.first);
        }
    }
    fre(res){
        cout << e << ' ';
    }
    // ll m,n,k; cin >> m>>n >> k;
    // ll a[n]; fr(0,n) cin >> a[i];
    // vector<pair<int,int>> g[n+m];
    // fr(0,k){
    //     int l,r,d; cin >> l >> r >> d; l--;r--; r+=m;
    //     g[r].pb(mp(l,d));
    // }
    // fr(m, m+n){
    //     sort(g[i].begin(), g[i].end());
    // }
    // ll res[m]; fr(0,m) res[i] = -1;
    // fr(0,n){
    //     for(auto e:g[i+m]){
    //         if (res[e.first]!=-1){
    //             a[i] /= expSinMod(res[e.first], e.second);
    //         }
    //     }
    //     map<ll,ll> f;
    //     factRho(a[i], f);
    //     auto it = f.begin();
    //     rep(j,0,g[i+m].size()){
    //         if (res[g[i+m][j].first] == -1){
    //             res[g[i+m][j].first] = it->first;
    //             it++;
    //         }
    //     }
    // }
    // fr(0,m){
    //     cout << res[i] << ' ';
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}