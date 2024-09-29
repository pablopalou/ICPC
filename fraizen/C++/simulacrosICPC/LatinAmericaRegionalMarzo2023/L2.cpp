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

// LCP(sa[i], sa[j]) = min(lcp[i+1], lcp[i+2], ..., lcp[j])
// example: "banana", sa = {5,3,1,0,4,2}, lcp = {0,1,3,0,0,2}
// Num of dif substrings: (n*n+n)/2 - (sum over lcp array)
// Build suffix array (sa) before calling
vector<int> computeLCP(string& s, vector<int>& sa) {
  int n = s.size(), L = 0;
  vector<int> lcp(n), plcp(n), phi(n);
  phi[sa[0]] = -1;
  forr(i, 1, n) phi[sa[i]] = sa[i - 1];
  forn(i, n) {
    if (phi[i] < 0) {
      plcp[i] = 0;
      continue;
    }
    while (s[i + L] == s[phi[i] + L]) L++;
    plcp[i] = L;
    L = max(L - 1, 0);
  }
  forn(i, n) lcp[i] = plcp[sa[i]];
  return lcp;  // lcp[i]=LCP(sa[i-1],sa[i])
}

// Solo para funciones idempotentes (como min y max, pero no sum)
// Usar la version dynamic si la funcion no es idempotente
typedef int tipo;

struct RMQ {
#define LVL 20  // LVL such that 2^LVL>n
  tipo vec[LVL][1 << (LVL + 1)];
  tipo& operator[](int p) { return vec[0][p]; }
  tipo get(int i, int j) {  // intervalo [i,j) - O(1)
    int p = 31 - __builtin_clz(j - i);
    return min(vec[p][i], vec[p][j - (1 << p)]);
  }
  void build(int n) {  // O(nlogn)
    int mp = 31 - __builtin_clz(n);
    forn(p, mp) forn(x, n - (1 << p)) vec[p + 1][x] =
        min(vec[p][x], vec[p][x + (1 << p)]);
  }
};  // Use: define LVL y tipo; insert data with []; call build; answer queries

int lcp_ij(int i, int j, vector<int>& rank, RMQ& rmq, int n, vector<int> &sa) {
    if (i == j)
        return n - i; // Entire suffix is common
    int pos_i = rank[i];
    int pos_j = rank[j];
    if (pos_i > pos_j)
        swap(pos_i, pos_j);
    if (pos_i + 1 > pos_j)
        return n - sa[pos_i]; // Adjacent in suffix array
    // RMQ get function uses interval [i, j)
    return rmq.get(pos_i + 1, pos_j + 1); // Query minimum in lcp[pos_i+1 .. pos_j]
}


void solve() {
    string s; cin >> s; int d; cin >> d; 
    s.pb('$');
    vector<int> suffix = constructSA(s); 
    vector<int> lcp = computeLCP(s, suffix); 
    suffix.erase(suffix.begin()); 
    lcp.erase(lcp.begin());
    s.pop_back();
    int n = s.size();
    RMQ rmq;
    for (int i = 0; i < n; i++) rmq[i] = lcp[i];
    rmq.build(n);
    vector<int> rank(n);
    for (int i = 0; i < n; i++) rank[suffix[i]] = i;
    int pos = 0; int ans = 0;
    while(pos < n){
        ans++;
        int mx = d; // puedo agarrar d seguro, veo si me puedo estirar mas..
        fr(1,d+1){
            if (pos+i < n){
                int cur = lcp_ij(pos, pos+i, rank, rmq, n, suffix);
                mx = max(mx, cur+i);
            }
        }
        pos+=mx;
    }
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