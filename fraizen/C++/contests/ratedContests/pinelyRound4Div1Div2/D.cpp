#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

#define MAXP 200002  // no necesariamente primo
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

// factoriza bien numeros hasta MAXP, llamar crearCriba antes
void fact2(ll n, map<ll, ll>& f) {  // O (lg n)
  while (criba[n]) {
    f[criba[n]]++;
    n /= criba[n];
  }
  if (n > 1) f[n]++;
}

// Usar asi: divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(map<ll, ll>& f, vector<ll>& divs, map<ll, ll>::iterator it,
               ll n = 1) {
  if (it == f.begin()) divs.clear();
  if (it == f.end()) {
    divs.pb(n);
    return;
  }
  ll p = it->first, k = it->second;
  ++it;
  forn(_, k + 1) divisores(f, divs, it, n), n *= p;
}

void solve() {
    int n; cin >> n;
    
    map<ll,ll> m;
    buscarPrimos();
    fr(1,n-1){
        fact((i ^ n), m);
        // cout << "I = " << i << endl;
        // cout << "factorizacion de "  << (i ^n) << endl;
        bool salir = false;
        fre(m){
            // cout << e.first << endl;
            if (e.first != (i^n)){
                salir = true;
                break;
            }
            // cout << e.first << " ";
        }
        m.clear();
        if (salir){
            continue;
        }
        cout << i << endl;

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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}