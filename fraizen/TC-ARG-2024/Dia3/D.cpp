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
#define MAXN 100005
#define MOD 998244353

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

int inverso(int x) {                    // O(log MOD)
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
    int n; cin >> n; string s; cin >> s;
    string newS;
    int i = 0;
    int stars = 0;
    while(i < n){
        if (s[i] == '0'){
            //lo meto al string
            newS += s[i];
            i++;
        } else if (s[i] == '1'){
            int cont = 1;
            i++;
            while(i < n && s[i] == '1'){
                cont++;
                i++;
            }
            if (cont % 2 == 1){
                newS += '1';
                if (cont >= 3){
                    stars += cont / 2;
                }
            } else {
                stars+=cont/2;
            }
        }
    }
    //deberia tener el nuevo string, busco posiciones pa poner (a ambos lados de los ceros salvo que haya un uno)
    int lugares = 1 + newS.size();
    fr(0,newS.size()){
        if (newS[i] == '1'){
            lugares--;
        }
    }
    // cout << newS << endl;
    // cout << stars << endl;
    // cout << lugares << endl;
    cout << comb(stars+lugares-1, stars) << '\n';
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
    build_facts();
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