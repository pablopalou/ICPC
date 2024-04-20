#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

struct UnionFind {
  int nsets;
  vector<int> f, setsz;  // f[i] = parent of node i
  vector<int> res;
  UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1), res(n,0) {}
  int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
  bool join(int i, int j) {  // returns true if already in the same set
    int a = comp(i), b = comp(j);
    if (a != b) {
      if (setsz[a] > setsz[b]) swap(a, b);
      f[a] = b;  // the bigger group (b) now represents the smaller (a)
      //en b queda el polenta
      res[b] = (res[b] + abs(j-i)) % 1000;
      nsets--, setsz[b] += setsz[a];
    }
    return a == b;
  }
};

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; char c;
    UnionFind uf = UnionFind(n+1);
    while (cin >> c){
        int a, b; 
        if (c == 'O') return;
        if (c == 'E'){
            cin >> a;
            cout << uf.res[a] << "\n";
        } else {
            cin >> a >> b;
            uf.join(a,b);
            // cout << "uno y UF.res = ";
            // fr(0,n+1){
            //     cout << uf.res[i] << " ";
            // }
            // cout << endl;
        }
    }
    cout <<  "\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}