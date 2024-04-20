#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define fre(s) for(auto e: s)
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

void solve(int n){
    //el minimo es la multiplicacion de los primos
    //la cantidad de operaciones es...
    //si son todos la misma potencia de 2 => log de eso.
    //sino es 1 + log(potencia siguiente a la mas grande)
    buscarPrimos();
    map<ll, ll> m;
    fact(n, m);
    int primero = 1;
    int iguales = true;
    ll num = m.begin()->second;
    ll maximo = m.begin()->second;
    fre(m){
        primero *= e.first;
        if (e.second != num){
            iguales = false;
        }
        maximo = max(maximo, e.second);
    }
    cout << primero << " ";
    // cout << iguales << endl;
    if (iguales && ((maximo & (maximo-1)) == 0)){
        cout << (int)ceil(log2(maximo)) << endl; 
    } else {
        cout << (int)ceil(log2(maximo)) + 1 << endl; 
    }
    
}

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
        int n; cin >> n;
        solve(n);
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}