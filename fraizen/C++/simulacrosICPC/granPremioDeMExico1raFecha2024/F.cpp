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

#define RB(x) (x < n ? r[x] : 0)
void csort(vector<int>& sa, vector<int>& r, int k) {  // counting sort O(n)
  int n = sa.size();
  vector<int> f(max(255, n), 0), t(n);
  forn(i, n) f[RB(i + k)]++;
  int sum = 0;
  forn(i, max(255, n)) f[i] = (sum += f[i]) - f[i];
  forn(i, n) t[f[RB(sa[i] + k)]++] = sa[i];
  sa = t;
}
vector<int> constructSA(string& s) {  // O(n logn)
  int n = s.size(), rank;
  vector<int> sa(n), r(n), t(n);
  forn(i, n) sa[i] = i, r[i] = s[i];  // r[i]: equivalence class of s[i..i+k)
  for (int k = 1; k < n; k *= 2) {
    csort(sa, r, k);
    csort(sa, r, 0);      // counting sort, O(n)
    t[sa[0]] = rank = 0;  // t : equivalence classes array for next size
    forr(i, 1, n) {
      // check if sa[i] and sa[i-1] are in te same equivalence class
      if (r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))
        rank++;
      t[sa[i]] = rank;
    }
    r = t;
    if (r[sa[n - 1]] == n - 1) break;
  }
  return sa;
}

void solve() {
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    string s = s1 + s1 + "$" + s2 + s2 + "{";
    vector<int> v = constructSA(s);
    ll res = 0;
    ll faltan = n;
    fr(0,v.size()){
        if (v[i] < n){
            res += faltan;
            continue;
        }
        if (v[i] >= 2*n+1 && v[i] <= 3*n){
            faltan--;
        }
    }
    cout << res << '\n';
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