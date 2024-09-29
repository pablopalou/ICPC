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
#define MOD 4294967296

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
    ll n; cin >> n;
    Mat mat(8);
    for(int i = 0; i < 8; i+=7){
        mat[i][0] = 2;
        mat[i][1] = 3;
        mat[i][2] = 4;
        mat[i][3] = 4;
        mat[i][4] = 4;
        mat[i][5] = 4;
        mat[i][6] = 3;
        mat[i][7] = 2;
    }
    for(int i = 1; i < 8; i+=5){
        mat[i][0] = 3;
        mat[i][1] = 4;
        mat[i][2] = 6;
        mat[i][3] = 6;
        mat[i][4] = 6;
        mat[i][5] = 6;
        mat[i][6] = 4;
        mat[i][7] = 3;
    }
    for(int i = 2; i < 6; i++){
        mat[i][0] = 4;
        mat[i][1] = 6;
        mat[i][2] = 8;
        mat[i][3] = 8;
        mat[i][4] = 8;
        mat[i][5] = 8;
        mat[i][6] = 6;
        mat[i][7] = 4;
    }
    mat = mat^(n-1);
    fr(0,8){
        rep(j,0,8){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return;
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