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
  UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
  int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
  bool join(int i, int j) {  // returns true if already in the same set
    int a = comp(i), b = comp(j);
    if (a != b) {
      if (setsz[a] > setsz[b]) swap(a, b);
      f[a] = b;  // the bigger group (b) now represents the smaller (a)
      nsets--, setsz[b] += setsz[a];
    }
    return a == b;
  }
};

// Copiar obligatoriamente 0
void solve() {
    int n,r;
    while(cin>>n>>r){
        if (n==0 && r == 0) return;
        string a[n];
        map<string, int> m;
        fr(0,n){
            cin >> a[i];
            m[a[i]] = i;
        }
        //hacer uf
        UnionFind uf= UnionFind(n);
        fr(0,r){
            string s1, s2; cin >> s1 >> s2;
            uf.join(m[s1], m[s2]);
        }
        map<int, int> comps;
        fr(0,n){
            comps[uf.comp(i)]++;
        }
        int maxi = 0;
        fre(comps){
            maxi = max(maxi, e.second);
        }
        cout << maxi <<"\n";
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