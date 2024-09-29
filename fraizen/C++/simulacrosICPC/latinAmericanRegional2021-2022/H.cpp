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

typedef ll td;
typedef vector<int> vi;
typedef vector<td> vd;
const td INF = 1e100;  // for maximum set INF to 0, and negate costs
bool zz(td x) { return abs(x) < 0; }  // change to x==0, for ints/ll
struct Hungarian {
  int n;
  vector<vd> cs;
  vi L, R;
  Hungarian(int N, int M) : n(max(N, M)), cs(n, vd(n)), L(n), R(n) {
    forn(x, N) forn(y, M) cs[x][y] = INF;
  }
  void set(int x, int y, td c) { cs[x][y] = c; }
  td assign() {  // O(n^3)
    int mat = 0;
    vd ds(n), u(n), v(n);
    vi dad(n), sn(n);
    forn(i, n) u[i] = *min_element(cs[i].begin(), cs[i].end());
    forn(j, n) {
      v[j] = cs[0][j] - u[0];
      forr(i, 1, n) v[j] = min(v[j], cs[i][j] - u[i]);
    }
    L = R = vi(n, -1);
    forn(i, n) forn(j, n) if (R[j] == -1 && zz(cs[i][j] - u[i] - v[j])) {
      L[i] = j, R[j] = i, mat++;
      break;
    }
    for (; mat < n; mat++) {
      int s = 0, j = 0, i;
      while (L[s] != -1) s++;
      fill(dad.begin(), dad.end(), -1);
      fill(sn.begin(), sn.end(), 0);
      forn(k, n) ds[k] = cs[s][k] - u[s] - v[k];
      while (1) {
        j = -1;
        forn(k, n) if (!sn[k] && (j == -1 || ds[k] < ds[j])) j = k;
        sn[j] = 1, i = R[j];
        if (i == -1) break;
        forn(k, n) if (!sn[k]) {
          td new_ds = ds[j] + cs[i][k] - u[i] - v[k];
          if (ds[k] > new_ds) ds[k] = new_ds, dad[k] = j;
        }
      }
      forn(k, n) if (k != j && sn[k]) {
        td w = ds[k] - ds[j];
        v[k] += w, u[R[k]] -= w;
      }
      u[s] += ds[j];
      while (dad[j] >= 0) {
        int d = dad[j];
        R[j] = R[d], L[R[j]] = j, j = d;
      }
      R[j] = s, L[s] = j;
    }
    td ret = 0;
    forn(i, n) ret += cs[i][L[i]];
    return ret;
  }
};

void solve() {
    int n; cin >> n;
    int a[n][n];
    fr(0,n){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }
    // fr(0,n){
    //     rep(j,0,n){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //tengo que ver los costos a las posiciones impares
    int cantImpar = n/2 + n%2;
    // cout << "cantimpar " << cantImpar << endl;
    int cost[cantImpar][cantImpar]; memset(cost, 0, sizeof(cost));
    //el primer caso es aparte:
    fr(0,cantImpar){
        cost[0][i] = a[1][2*i];
    }
    if (n&1){
        fr(0,cantImpar){
            cost[cantImpar-1][i] = a[n-2][2*i];
        }
    }
    fr(1,n/2){
        rep(j,0,cantImpar){
            cost[i][j] = a[j*2][i*2-1] + a[j*2][i*2+1];
        }
    }
    Hungarian hungarian(cantImpar,cantImpar);
    fr(0,cantImpar){
        rep(j,0,cantImpar){
            hungarian.set(i,j,cost[i][j]);
        }
    }
    cout << hungarian.assign();
    // fr(0,cantImpar){
    //     rep(j,0,cantImpar){
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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