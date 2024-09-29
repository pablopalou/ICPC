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
// #define MOD 1000000007
typedef __int128 T;
// const T MOD = 2305843009255636993LL, RT = 5;
typedef double ld;
typedef vector<T> poly;
const T MAXN = (1 << 21);  // MAXN must be power of 2,
// MOD-1 needs to be a multiple of MAXN, big mod and primitive root for NTT
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

std::ostream& operator<<(std::ostream& o, const __int128& x) {
    if (x == std::numeric_limits<__int128>::min()) return o << "-170141183460469231731687303715884105728";
    if (x < 0) return o << "-" << -x;
    if (x < 10) return o << (char)(x + '0');
    return o << x / 10 << (char)(x % 10 + '0');
}


void solve() {
    poly p1,p2;
    int n; cin >> n; bool a[200200]; 
    fr(0,200200) a[i] = false;
    a[0] = true;
    fr(0,n){
        int num; cin >> num; a[num] = true;
    }
    int m; cin >> m; int b[m];
    fr(0,m) {
        cin >> b[i];
    }
    // fr(0,m){
    //     cout << b[i] << " \n";
    // }
    fr(0,200200){
        if (a[i]){
            p1.pb(1);
        } else {
            p1.pb(0);
        }
    }
    // reverse(p1.begin(), p1.end());
    // reverse(p2.begin(), p2.end());
    poly res = multiply(p1, p1);
    ll ans = 0;
    fr(0,m){
        if (res[b[i]] >= 1){
            ans++;
        }
    }
    // fr(0,50){
    //     cout << res[i];
    // }
    cout << ans << '\n';
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