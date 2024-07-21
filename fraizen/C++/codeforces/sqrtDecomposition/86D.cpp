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
#define MAXN 200100
ll n, sq, nq;  // array size, sqrt(array size), #queries
struct Qu {     //[l, r)
  ll l, r, id;
};
Qu qs[MAXN];
ll ans[MAXN]; 
bool qcomp(const Qu& a, const Qu& b) {
  if (a.l / sq != b.l / sq) return a.l < b.l;
  return (a.l / sq) & 1 ? a.r < b.r : a.r > b.r;
}
ll res = 0;

// unordered_map<ll,ll> cnt; CON ESTO DA TLE
ll cnt[1000003];

ll get_ans(){
    return res;
}

void add(ll index, ll a[]){
    ll viejo = cnt[a[index]];
    cnt[a[index]]++;
    res -= (viejo * viejo * a[index]);
    res += ((viejo+1) * (viejo+1) * a[index]);
}

void remove(ll index, ll a[]){
    ll viejo = cnt[a[index]];
    cnt[a[index]]--;
    res -= (viejo * viejo * a[index]);
    res += ((viejo-1) * (viejo-1) * a[index]);
}

void mos(ll a[]) {
//   forn(i, nq) qs[i].id = i;
  sq = sqrt(n) + .5;
  sort(qs, qs + nq, qcomp);
  int l = 0, r = 0;
//   init();
  forn(i, nq) {
    Qu q = qs[i];
    while (l > q.l) add(--l, a);
    while (r < q.r) add(r++, a);
    while (l < q.l) remove(l++, a);
    while (r > q.r) remove(--r, a);
    ans[q.id] = get_ans();
  }
}

void solve() {
    cin >> n >> nq;
    ll a[n];
    fr(0,n) {
        cin >> a[i];
    }
    fr(0,nq){
        ll l,r; cin >> l >> r; l--;
        qs[i] = {l,r,i};
    }
    mos(a);
    fr(0,nq){
        cout << ans[i] << '\n';
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