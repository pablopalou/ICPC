#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007

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

//ESTE DA TLE (igual lo tengo hecho en la otra carpeta)
void solve() {
    ll n; cin >> n;
    //sumo los primeros raiz de n. (esto en definitiva queda O(sqrt(n)))
    ll res = 0;
    for(int i = 1; i * i <=n; i++){
        res = (res + ((i * (n/i)) % MOD)) % MOD;
    }
    //ahora veo los numeros despues de raiz de n (en realidad voy a ver cuantos hay que den suma de 1 a raiz de n, pero es lo mismo)
    ll l=(ll)sqrt(n) + 1;
    ll inv = inverso(2);
    for(ll i=sqrt(n);i>=1;i--){
        ll r = n/i;
        // cout << "L = " << l << " R = " << r << endl;
        ll cur = 0;
        //creo que esta bien todo esto, el tema que da tle de tantos mod que puse... asi que voy a simplificarlo
        //sumo de l+1 hasta r inclusive basicamente
        // cur = ((((r % MOD) * ((r+1) % MOD)) % MOD) * (inverso(2) % MOD) % MOD) % MOD;
        // ll restar = ((((l % MOD) * ((l-1) % MOD)) % MOD * (inverso(2) % MOD)) % MOD);
        // cur = (((cur - restar) % MOD) + MOD) % MOD;
        cur = (((r%MOD * (r+1) % MOD) % MOD )* inv)%MOD;
        cur = (cur - ((((l%MOD * (l-1) % MOD) % MOD )* inv)%MOD) + MOD) % MOD;
        l = r+1;
        // cout << "Cur = " << cur << endl;
        cur = (cur * i) % MOD;
        res = (res + cur) % MOD;
    }
    cout << res << '\n';
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