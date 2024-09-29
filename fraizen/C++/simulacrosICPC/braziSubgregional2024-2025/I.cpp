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

#define MAXP 1001000  // no necesariamente primo
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
// void fact(ll n, map<ll, ll>& f) {  // O (cant primos)
//   forall(p, primos) {
//     while (!(n % *p)) {
//       f[*p]++;  // divisor found
//       n /= *p;
//     }
//   }
//   if (n > 1) f[n]++;
// }

// factoriza bien numeros hasta MAXP, llamar crearCriba antes
void fact2(int n, map<int, int>& f) {  // O (lg n)
  while (criba[n]) {
    f[criba[n]]++;
    n /= criba[n];
  }
  if (n > 1) f[n]++;
}

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

// Usar asi: divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(map<int, int>& f, vector<int>& divs, map<int, int>::iterator it,
               ll n = 1) {
  if (it == f.begin()) divs.clear();
  if (it == f.end()) {
    divs.pb(n);
    return;
  }
  int p = it->first, k = it->second;
  ++it;
  forn(_, k + 1) divisores(f, divs, it, n), n *= p;
}

#define MAXN 1000010
void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    crearCriba();
    // map<int,int> mDiv;
    int mDiv[MAXN];
    memset(mDiv, 0, sizeof(mDiv));
    fr(0,n){
        map<int,int> f;
        fact2(a[i], f);
        vector<int> divs;
        divisores(f,divs,f.begin());
        fre(divs){
            mDiv[e]++;
        }
    }
    // fre(mDiv){
    //     cout << "m[" << e.first << "] = " << e.second << endl;
    // }
    // cout << endl;
    int q; cin >> q;
    fr(0,q){
        int num; cin >> num;
        int total = n;
        map<int,int> f;
        fact2(num, f);
        int nuevoNumero = 1;
        int cant = 0;
        int conversor[8];
        fre(f){
            nuevoNumero *= e.first;
            conversor[cant] = e.first;
            cant++;
        }
        // cout << "Nuevo numero => " << nuevoNumero << endl;
        // cout << "PRIMOS " << endl;
        // fr(0,cant){
        //     cout << conversor[i] << " ";
        // }
        // cout << endl;
        // cout << "CANT = " << cant << endl;
        // cout << endl;
        int noPuede = 0; //aca tendria que hacer lo de bitmasking en primos ? 
        //ahora si hago bitmasking, como mucho tengo 7 creo. (128 posibilidades)
        rep(mask, 1, (1<<cant)){
            // cout <<"Mask = " << mask << endl;
            int numerito = 1;
            int cantNum = 0;
            rep(j,0,cant){
                if ((mask & (1<<j)) != 0){
                    cantNum++;
                    numerito *= conversor[j];
                }
            }
            if (cantNum % 2 == 1){
            // cout << "SUMO Numerito => " << numerito << endl;
                noPuede += mDiv[numerito]; 
            } else {
                // cout << "RESTO Numerito => " << numerito << endl;
                noPuede -= mDiv[numerito]; 
            }
        }

        cout << expMod(2, total-noPuede) << '\n';
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
