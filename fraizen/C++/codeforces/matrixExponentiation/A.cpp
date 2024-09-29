#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

typedef double tipo;  // maybe use double or other depending on the problem
struct Mat {
  int N;  // square matrix
  vector<vector<tipo>> m;
  Mat(int n) : N(n), m(n, vector<tipo>(n, 0)) {}
  vector<tipo>& operator[](int p) { return m[p]; }
  Mat operator*(Mat& b) {  // O(N^3), multiplication
    assert(N == b.N);
    Mat res(N);
    forn(i, N) forn(j, N) forn(k, N)  // remove MOD if not needed
        res[i][j] = (res[i][j] + m[i][k] * b[k][j]);
    return res;
  }
  Mat operator^(int k) {  // O(N^3 * logk), exponentiation
    Mat res(N), aux = *this;
    forn(i, N) res[i][i] = 1;
    while (k)
      if (k & 1) res = res * aux, k--;
      else aux = aux * aux, k /= 2;
    return res;
  }
};

void solve() {
    int n; cin >> n; double p; cin >> p;
    Mat mat(2);
    mat[0][0] = mat[1][1] = 1-p;
    mat[0][1] = mat[1][0] = p;
    mat = mat ^ n;
    cout << fixed << setprecision(12) << mat[0][0] << '\n';
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