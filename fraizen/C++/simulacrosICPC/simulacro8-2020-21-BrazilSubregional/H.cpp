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
#define MAXN 55
// #define MOD 1000000007
// #define MAXMOD 15485867
// ll inv[MAXMOD];     // inv[i]*i=1 mod MOD
// void calc(int p) {  // O(p)
//   inv[1] = 1;
//   forr(i, 2, p) inv[i] = p - ((p / i) * inv[p % i]) % p;
// }

// ll expMod(ll b, ll e, ll m = MOD) {  // O(log e)
//   if (e < 0) return 0;
//   ll ret = 1;
//   while (e) {
//     if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
//     b = b * b % m;                 // b = mulMod(b,b,m);
//     e >>= 1;
//   }
//   return ret;
// }

// int inverso(int x) {                    // O(log MOD)
// //   return expMod(x, eulerPhi(MOD) - 1);  // si mod no es primo(sacar a mano)
//   return expMod(x, MOD - 2);            // si mod es primo
// }

// // fact[i] = i!%MOD and ifact[i] = 1/(i!)%MOD
// // inv is modular inverse function
// ll fact[MAXN], ifact[MAXN];
// void build_facts() {  // O(MAXN)
//   fact[0] = 1;
//   forr(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
//   ifact[MAXN - 1] = inverso(fact[MAXN - 1]);
//   dforn(i, MAXN - 1) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
//   return;
// }

long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;
    
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);       // Multiply the next numerator term
        res /= (i + 1);       // Divide by the denominator term
    }
    return res;
}

// n! / k!*(n-k)!
// assumes 0 <= n < MAXN
// ll comb(ll n, ll k) {
//   if (k < 0 || n < k) return 0;
//   return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
// }

void solve() {
    ll n,k; cin >> n >> k;
    ll w[n]; fr(0,n) cin >> w[i];
    ll a,b; cin >> a >> b;
    sort(w, w+n, greater<ll>());
    ll res = 0;
    // build_facts();
    int voy = 0;
    ll cur = 0;
    fr(0, n){
        if (cur + w[i] <= b){
            res += comb(n-i-1, k-voy); // no meto la caja i, entonces combino todo el resto
            cur += w[i];
            voy++; //meto la caja i 
        }
    }
    if (voy == k) res++;
    // cout << "res " << res << '\n';
    cur = 0;
    voy = 0;
    fr(0, n){
        // cout <<" I = " << i << endl;
        // cout << " res = " << res << endl;
        if (cur + w[i] <= a-1){
            res = res - comb(n-i-1, k-voy);
            cur += w[i];
            voy++;
        }
    }
    if (voy == k) res--;
    cout << res << '\n';
    // cout << "res " << res << endl;
    // voy = 0;
    // fr(0,n){
    //     // cout << " estoy en i = " << i << endl;
    //     if (w[i] > a-1){
    //         continue;
    //     }
    //     res -= comb(n-i-1, k-voy);
    //     // cout << "resto " << comb(n-i-1, k-voy) << endl;
    //     //puedo no poner este y hacer cualquier comb mas chica: 
    //     voy++; //pongo este y paso al siguiente
    //     a-=w[i];
    // }
    // cout << res << '\n';
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