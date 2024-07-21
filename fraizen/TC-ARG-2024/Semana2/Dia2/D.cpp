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

#define MAXP 100000  // no necesariamente primo
int criba[MAXP + 1];
void crearCriba() {
  int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
  for (int p = 25; p <= MAXP; p += 10) criba[p] = 5;
  for (int p = 9; p <= MAXP; p += 6) criba[p] = 3;
  for (int p = 4; p <= MAXP; p += 2) criba[p] = 2;
  for (int p = 7, cur = 0; p * p <= MAXP; p += w[cur++ & 7])
    if (!criba[p])
      for (int j = p * p; j <= MAXP; j += (p << 1))
        if (!criba[j]) criba[j] = p;
}
vector<int> primos;
void buscarPrimos() {
  crearCriba();
  forr(i, 2, MAXP + 1) if (!criba[i]) primos.push_back(i);
}

// factoriza bien numeros hasta MAXP^2, llamar a buscarPrimos antes
void fact(ll n, map<ll, ll>& f) {  // O (cant primos)
  forall(p, primos) {
    while (!(n % *p)) {
      f[*p]++;  // divisor found
      n /= *p;
    }
  }
  if (n > 1) f[n]++;
}

map<ll, ll> dp;
//la dp me da el numero grundy
ll solveDP(ll mask){
    if (mask == 0) return 0;
    if (dp.count(mask) != 0) return dp[mask];
    // vector<bool> mexes[35];
    set<ll> mexes;
    fr(1,32){
        //shifteo 1 o mas pero con el or (xq si ya estaba prendido lo dejo asi)
        //el numero de grundy es el mex de todas las trancisiones de mi a otra cosa
        ll newMask = (mask >> i) | (mask & ((1<<(i-1))-1));
        if (newMask != mask){
            mexes.insert(solveDP(newMask));  
        }
    }
    ll res = 0;
    fre(mexes){
        if (e == res){
            res++;
        }
    }
    dp[mask] = res;
    return res;
}

void solve() {
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    buscarPrimos();
    map<ll, ll> f;
    map<ll, ll> masks;
    fr(0,n){
        fact(a[i], f);
        fre(f){
            masks[e.first] |= (1 << (e.second-1));
        }
        f.clear();
    }

    ll res = 0;
    //cada grundy es como una pila del nim, entonces hago el xor
    fre(masks){
        res ^= solveDP(e.second);
    }
    if (res != 0){
        cout << "Mojtaba\n";
    } else {
        cout << "Arpa\n";
    }
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