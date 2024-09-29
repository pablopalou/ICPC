#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define MOD 1000000007

typedef ll tipo;  // maybe use double or other depending on the problem
struct Mat {
  ll N;  // square matrix
  vector<vector<tipo>> m;
  Mat(ll n) : N(n), m(n, vector<tipo>(n, 0)) {}
  vector<tipo>& operator[](ll p) { return m[p]; }
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
    ll n; cin >> n;
    if (n == 1) {cout << 1; return;}
    Mat m = Mat(6);
    fr(0,6){
        rep(j,0,6){
            m[i][j] = 0;
        }
    }
    rep(j,0,6){
        m[0][j] = 1;
    }
    m[1][0] = 1;
    m[2][1] = 1;
    m[3][2] = 1;
    m[4][3] = 1;
    m[5][4] = 1;
    m = m^(n);
    cout << m[0][0];
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