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

typedef __int128 T;
typedef long double ld;
typedef vector<T> poly;
const T MAXN = (1 << 21);  // MAXN must be power of 2,
// MOD-1 needs to be a multiple of MAXN, big mod and primitive root for NTT
const T MOD = 2305843009255636993LL, RT = 5;
// const T MOD = 998244353, RT = 3;

// NTT
// struct CD {
//   T x;
//   CD(T x_) : x(x_) {}
//   CD() {}
// };
// T mulmod(T a, T b) { return a * b % MOD; }
// T addmod(T a, T b) {
//   T r = a + b;
//   if (r >= MOD) r -= MOD;
//   return r;
// }
// T submod(T a, T b) {
//   T r = a - b;
//   if (r < 0) r += MOD;
//   return r;
// }
// CD operator*(const CD& a, const CD& b) { return CD(mulmod(a.x, b.x)); }
// CD operator+(const CD& a, const CD& b) { return CD(addmod(a.x, b.x)); }
// CD operator-(const CD& a, const CD& b) { return CD(submod(a.x, b.x)); }
// vector<T> rts(MAXN + 9, -1);
// CD root(int n, bool inv) {
//   T r = rts[n] < 0 ? rts[n] = expMod(RT, (MOD - 1) / n) : rts[n];
//   return CD(inv ? expMod(r, MOD - 2) : r);
// }

// FFT
struct CD {
  ld r, i;
  CD(ld r_ = 0, ld i_ = 0) : r(r_), i(i_) {}
  ld real() const { return r; }
  void operator/=(const int c) { r /= c, i /= c; }
};
CD operator*(const CD& a, const CD& b) {
  return CD(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}
CD operator+(const CD& a, const CD& b) { return CD(a.r + b.r, a.i + b.i); }
CD operator-(const CD& a, const CD& b) { return CD(a.r - b.r, a.i - b.i); }
const ld pi = acos(-1.0);

CD cp1[MAXN + 9], cp2[MAXN + 9];
int R[MAXN + 9];
void dft(CD* a, int n, bool inv) {
  forn(i, n) if (R[i] < i) swap(a[R[i]], a[i]);
  for (int m = 2; m <= n; m *= 2) {
    ld z=2*pi/m*(inv?-1:1); // FFT
    CD wi=CD(cos(z),sin(z)); // FFT
    // CD wi = root(m, inv);  // NTT
    for (int j = 0; j < n; j += m) {
      CD w(1);
      for (int k = j, k2 = j + m / 2; k2 < j + m; k++, k2++) {
        CD u = a[k];
        CD v = a[k2] * w;
        a[k] = u + v;
        a[k2] = u - v;
        w = w * wi;
      }
    }
  }
  if(inv) forn(i,n) a[i]/=n; // FFT
//   if (inv) {  // NTT
//     CD z(expMod(n, MOD - 2));
//     forn(i, n) a[i] = a[i] * z;
//   }
}
poly multiply(poly& p1, poly& p2) {
  int n = sz(p1) + sz(p2) + 1;
  int m = 1, cnt = 0;
  while (m <= n) m += m, cnt++;
  forn(i, m) {
    R[i] = 0;
    forn(j, cnt) R[i] = (R[i] << 1) | ((i >> j) & 1);
  }
  forn(i, m) cp1[i] = 0, cp2[i] = 0;
  forn(i, sz(p1)) cp1[i] = p1[i];
  forn(i, sz(p2)) cp2[i] = p2[i];
  dft(cp1, m, false);
  dft(cp2, m, false);
  forn(i, m) cp1[i] = cp1[i] * cp2[i];
  dft(cp1, m, true);
  poly res;
  n -= 2;
  forn(i,n) res.pb((T) floor(cp1[i].real()+0.5)); // FFT
//   forn(i, n) res.pb(cp1[i].x);  // NTT
  return res;
}

int n; 

void solucionate(vector<ll>& a, vector<ll>& b, vector<ll>& res){
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    deque<ll> da(a.begin(), a.end()); deque<ll> db(b.begin(), b.end());
    vector<ll> casiRes;
    //meto los del principio que seria negativo por negativo
    while(!da.empty() && da.front() <= 0 && !db.empty() && db.front() <= 0){
        casiRes.pb(da.front() * db.front());
        da.pop_front();
        db.pop_front();
    }
    //meto los del final que seria positivo por positivo
    while(!da.empty() && da.back() >= 0 && !db.empty() && db.back() >= 0){
        casiRes.pb(da.back() * db.back());
        da.pop_back(); 
        db.pop_back();
    }
    sort(casiRes.begin(), casiRes.end(), greater<ll>());
    ll cur = 0;
    ll fraizen = casiRes.size();
    fr(0,casiRes.size()){
        res.pb(casiRes[i] + cur);
        cur += casiRes[i];
    }
    //ahora falta los del medio, que seria uno negativo y el otro positivo digamos.
    //si tengo -3,-2,-1 y en el otro 1,2,3: 
    //si quiero solo 1, para maximizar lo que me conviene es hacer -1 * 1 = 1
    //si quiero solo 2, me conviene (-2*1) + (-1*2) = -4
    //si quiero 3, me conviene (-1*3) + (-2*2) + (-1*3) = -10
    //entonces si hago el polinomio 
    // -1x^0 -2x^1 -3x^2  (NOTAR QUE ESTA DADO VUELTA)
    // 1x^0 + 2x^1 + 3x^2
    // y los multiplico, los coeficientes me quedan: para x^0 => -1, para x^1 me quedaria el (-1x^0 * 2x^1) + (-2x^1*x^0) = -4 
    //basicamente me quedan las mismas cosas que yo queria
    
    //bueno ahora si sigo programando: 
    if (!da.empty()){ //tengo el caso de negativo y positivo, entonces aca hago fft
        //tengo que dar vuelta el que es negativo
        if (da.front() < 0) reverse(da.begin(), da.end());
        if (db.front() < 0) reverse(db.begin(), db.end());
        //ahora si ya tengo los numeritos para hacer fft (aunque me pide un "poly")
        vector<__int128_t> v1(da.begin(), da.end());
        vector<__int128_t> v2(db.begin(), db.end());
        vector<__int128_t> resFFT = multiply(v1, v2);
        //ahora todos estos resultados los pongo en el casiRes (no pasarse de n igual, acordarse que ya puse varios)
        int iter = 0;
        while(casiRes.size() < n){
            casiRes.pb(resFFT[iter]);
            iter++;
        }
    }

    fr(fraizen, n){
        res.pb(cur + casiRes[i]);
    }

    // cout << "CASI RES " << endl;
    // fr(0,n){
    //     cout << casiRes[i] << ' ';
    // }
    // cout << endl;
    // cout << "fraizen " << fraizen << endl;

    // ll tenia = 0;
    // fr(0,casiRes.size()){
    //     if (casiRes[i] > 0){
    //         tenia += casiRes[i];
    //     }
    // }
    // // cout << "tenia  =" << tenia << endl;
    // //ahora si ya tengo todo ordenadito los resultados
    // //hacer el prefix pa poner en el vector resultado (ojo que el prefix para cuando llego a los negativos por positivos, porque ahi fft ya tiene en cuenta todo)
    // ll cur = 0;
    // fr(0,n){
    //     if (i < fraizen){
    //         res.pb(ll(casiRes[i])+cur);
    //         cur+= casiRes[i];
    //     } else {
    //         res.pb(tenia + ll(casiRes[i]));
    //     }
    // }
}

void solve() {
    cin >> n;
    vector<ll> a(n),b(n),resMax, resMin;
    fr(0,n) cin >> a[i]; fr(0,n) cin >> b[i];
    solucionate(a,b,resMax);
    //para encontrar el minimo, cambio el signo de cualquier vector y maximizo (luego pongo el menos cuando voy a imprimir)
    fr(0,n) a[i]*=-1;
    solucionate(a,b,resMin);
    fr(0,n){
        cout << -resMin[i] << ' ' << resMax[i] << '\n';
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