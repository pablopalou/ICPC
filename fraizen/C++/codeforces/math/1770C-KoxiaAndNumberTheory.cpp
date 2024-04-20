#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)

#define MAXP 55  // no necesariamente primo
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

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    sort(a, a+n);
    fr(0,n-1){
        if (a[i] == a[i+1]){
            cout << "NO\n"; return;
        }
    }
    //son distintos, entonces tengo que agarrar los primos menores a 51 y ver si en todos tengo que algun modulo de 0 o 1.
    // si los numeros modulo el primo son todos 2 o mas, entonces por mas que sume, siempre voy a tener un 2 en el 0 en el mod p, por lo que  va a haber 2 numeros que compartan un primo
    buscarPrimos();
    fre(primos){
        int cant[e];
        memset(cant, 0, sizeof(cant));
        fr(0,n){
            cant[a[i]%e]++;
        }
        if (*min_element(cant, cant+e) >= 2){
            cout << "NO\n";return;
        }
    }
    cout << "YES\n";
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