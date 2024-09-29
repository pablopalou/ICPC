#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fre(s) for (auto e : s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n)-1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define MOD 4294967296ULL
// SI NO PONGO EL ULL EN EL MOD, DA WA. MUY IMPORTANTE. 

typedef long long tipo;  // maybe use double or other depending on the problem
//NI IDEA XQ ACA NO NECESITA UNSIGNED LONG LONG (Si lo pongo tambien funciona obvio)

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
        while (k) {
            if (k & 1) res = res * aux;
            aux = aux * aux;
            k /= 2;
        }
        return res;
    }
};

void solve() {
    ll n;
    cin >> n; n++;
    Mat mat(65);
    rep(row, 0, 8) {
        rep(col, 0, 8) {
            for (int drow : {-2, -1, 1, 2}) {
                for (int dcol : {-2, -1, 1, 2}) {
                    if (abs(drow) != abs(dcol)) {
                        int newRow = row + drow;
                        int newCol = col + dcol;
                        if (newRow >= 0 && newRow <= 7 && newCol >= 0 && newCol <= 7) {
                            mat[row * 8 + col][8 * newRow + newCol] = 1;
                        }
                    }
                }
            }
        }
    }

    fr(0, 65) {
        mat[64][i] = 1;
    }
    mat = mat ^ n;
    cout << mat[64][0] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
    #endif

    int cases = 1;
    // cin >> cases;
    while (cases--) {
        solve();
    }

    #ifdef JP
        cerr << "Time elapsed: " << clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}