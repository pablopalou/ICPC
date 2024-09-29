#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)

const int MOD = 1e9+7;

typedef ll tipo;  // maybe use double or other depending on the problem
struct Mat {
  int N;  // square matrix
  vector<vector<tipo>> m;
  Mat(int n) : N(n), m(n, vector<tipo>(n, 0)) {}
  vector<tipo>& operator[](int p) { return m[p]; }
  Mat operator*(Mat& b) {  // O(N^3), multiplication
    assert(N == b.N);
    Mat res(N);
    forn(i, N) forn(j, N) forn(k, N)  // remove MOD if not needed
        res[i][j] = (res[i][j] + m[i][k] * b[k][j]) % MOD;
    return res;
  }
  Mat operator^(ll k) {  // O(N^3 * logk), exponentiation
    Mat res(N), aux = *this;
    forn(i, N) res[i][i] = 1;
    while (k)
      if (k & 1) res = res * aux, k--;
      else aux = aux * aux, k /= 2;
    return res;
  }
};

void solve() {
    ll n, k; cin>>n>>k;
    int a[n], c[n+1];
    fr(0, n) cin >> a[i];
    fr(1,n+1) cin>>c[i];
    int p,q,r; cin>>p>>q>>r;

    int d = (2*n)+6;
    Mat mat(d);
    fr(0,d) {
        rep(j,0,d) mat.m[i][j] = 0;
    }
    fr(0, n-1) mat.m[i][i+1] = 1;
    fr(0, n) mat.m[n-1][i] = c[n-i];
    mat.m[n-1][2*n] = 1;
    mat.m[n-1][2*n+3] = q;
    mat.m[n-1][2*n+5] = r;
    // Cs y pqr
    fr(n, 2*n+3) mat.m[i][i] = 1;
    // i+1
    mat.m[2*n+3][2*n+3] = 1;
    mat.m[2*n+3][2*n+4] = 1;
    // 1 para conseguir el 1
    mat.m[2*n+4][2*n+4] = 1;
    // i^2+2i+1
    mat.m[2*n+5][2*n+3] = 2;
    mat.m[2*n+5][2*n+4] = 1;
    mat.m[2*n+5][2*n+5] = 1;

    mat = mat^(k);

    int num = n;
    Mat vec(d);
    fr(0,d) {
        rep(j,0,d) vec.m[i][j] = 0;
    }
    fr(0, n) vec.m[i][0] = a[i];
    fr(n, 2*n) vec[i][0] = c[i-n+1];
    vec[2*n][0] = p;
    vec[2*n+1][0] = q;
    vec[2*n+2][0] = r;
    vec[2*n+3][0] = n;
    vec[2*n+4][0] = 1;
    vec[2*n+5][0] = n*n;

    mat = mat*vec;
    cout << mat[0][0];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
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