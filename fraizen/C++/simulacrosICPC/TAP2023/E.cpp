#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (ll i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((ll)c.size())
#define rsz resize
#define MAXP 1001000  // no necesariamente primo
int criba[MAXP + 1];
#define EPSILON 1e-9
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
vector<ll> primos;
void buscarPrimos() {
  crearCriba();
  forr(i, 2, MAXP + 1) if (!criba[i]) primos.push_back(i);
}

// factoriza bien numeros hasta MAXP^2, llamar a buscarPrimos antes. 
void fact(ll n, map<ll, ll>& f) {  // O (cant primos) => OJO QUE SON 78500 primos.
  forall(p, primos) {
    if ((*p * *p) > n) break; //YO AGREGUE ESTA LINEA (OJO)
    while (!(n % *p)) {
      f[*p]++;  // divisor found
      n /= *p;
    }
  }
  if (n > 1) f[n]++;
}

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

bool isAlmostInteger(double x, double epsilon = 1e-6) {
    double rounded = round(x);
    return abs(x - rounded) < epsilon;
}
__int128 wholeRoot(__int128 x) {
    if (x == 0 || x == 1) return x;

    __int128 left = 0, right = x, mid, ans;

    // Binary search to find the largest integer r such that r*r <= x
    while (left <= right) {
        mid = left + (right - left) / 2;
        __int128 midSq = mid * mid;

        if (midSq == x) {
            return mid;
        } else if (midSq < x) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

void solve() {
    ll res = 0;
    ll a, s, l, r; cin >> a >> s >> l >> r;
    buscarPrimos();
    if (a == s){
        cout << 1; return;
    }
    ll iter = 0;
    fr(l,a+1){
        iter++;
        ll ini = i;
        map<ll,ll> f;
        vector<ll> divs;
        if (i == a){
            rep(j,1,r-l+2){
                divs.pb(j);
            }
        } else {
            fact(a-ini,f);
            divisores(f, divs, f.begin());
        }
        // cout << "INICIO = " << ini << endl;
        rep(j,0,divs.size()){
            ll d = divs[j];
            // cout << "D =" << d << endl;
            ll ba = d;
            ll bb = 2*ini-d;
            __int128_t bc = -2*s; //cambiar a 128 esto
            if (bb*bb-4*ba*bc < 0){
                continue;
            }
            //ARMAR FUNCION DE RAIZ ENTERA
            __int128_t raiz = wholeRoot(bb*bb-4*ba*bc);
            if (raiz * raiz != bb*bb-4*ba*bc){
                continue;
            }
            raiz = ll(raiz);
            if ((-bb+raiz) % (2*ba) == 0){
                ll x1 = (-bb + raiz )/ (2*ba);
                if (x1 >= 1){
                    if (ini + (x1-1)*d >= a && ini + (x1-1)*d <= r){
                        // cout << "Sumo" << endl;
                        res++;
                        continue;
                    }
                }
            }
            if ((-bb-raiz)%(2*ba) == 0){
                ll x2 = (-bb-raiz)/(2*ba);
                if (x2 >= 1){
                    if (ini + (x2-1)*d >= a && ini + (x2-1)*d <= r){
                        res++;
                        // cout << "Sumo" << endl;
                    }
                }
            }
        }
    }
    // ll ini = a;
    // rep(d,1,r-ini+2){
    //     ll ba = d;
    //     ll bb = 2*ini-d;
    //     __int128_t bc = -2*s;
    //     if (bb*bb-4*ba*bc < 0){
    //         continue;
    //     }
    //     double raiz = sqrt(double(bb*bb-4*ba*bc));
    //     if (isAlmostInteger(raiz)){
    //         double x1 = (-bb + raiz )/ double(2*ba);
    //         double x2 = (-bb - raiz )/ double(2*ba);
    //         bool yaSume = false;
    //         if ((isAlmostInteger(x1) && x1 >= 1) or (isAlmostInteger(x2) && x2>=1)){
    //             if ((isAlmostInteger(x1) && x1 >= 1)){
    //                 if (a + (x1-1)*d <= r){
    //                     res++;
    //                     yaSume = true;
    //                 }
    //             }
    //             if (yaSume){
    //                 continue;
    //             }
    //             if ((isAlmostInteger(x2) && x2 >= 1)){
    //                 if (a + (x2-1)*d <= r){
    //                     res++;
    //                     yaSume = true;
    //                 }
    //             }
    //         }
    //     } 
    // }
    cout << res << "\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("E.in", "r", stdin);
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