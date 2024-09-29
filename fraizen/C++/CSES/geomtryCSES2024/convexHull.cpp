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

typedef long long T;
const T EPS = 0;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator-(pto b) { return pto(x-b.x, y-b.y); }
    T operator^(pto b) { return x*b.y - y*b.x; }
    bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
    bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
};
// returns convex hull of p in CCW order
// left must return >=0 to delete collinear points
vector<pto> CH(vector<pto>& p) {
  if (sz(p) < 3) return p;  // edge case, keep line or point
  vector<pto> ch;
  sort(p.begin(), p.end());
  forn(i, sz(p)) {  // lower hull
    while (sz(ch) >= 2 && ch[sz(ch) - 1].left(ch[sz(ch) - 2], p[i]))
      ch.pop_back();
    ch.pb(p[i]);
  }
  ch.pop_back();
  int k = sz(ch);
  dforn(i, sz(p)) {  // upper hull
    while (sz(ch) >= k + 2 && ch[sz(ch) - 1].left(ch[sz(ch) - 2], p[i]))
      ch.pop_back();
    ch.pb(p[i]);
  }
  ch.pop_back();
  return ch;
}

void solve() {
    int n; cin>>n; vector<pto> p(n); fr(0,n) cin >> p[i].x >> p[i].y;
    vector<pto> res = CH(p);
    cout << res.size() << '\n';
    fre(res){
        cout << e.x << " " << e.y << '\n';
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