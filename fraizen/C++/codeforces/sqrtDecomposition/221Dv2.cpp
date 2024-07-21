#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

// int compressedA[MAXN];
unordered_map<int, int> compress;

int n, sq, nq;  // array size, sqrt(array size), #queries
struct Qu {     //[l, r)
  int l, r, id;
};
Qu qs[MAXN];
int ans[MAXN];
int value = 0;
int cnt[MAXN];

int get_ans(){
    return value;
}

void add(int index, int a[]){
    cnt[compress[a[index]]]++;
    int cant = cnt[compress[a[index]]];
    if (cant == a[index]){
        value++;
    } else if (cant == a[index]+1){
        value--;
    }
}

void remove(int index, int a[]){
    cnt[compress[a[index]]]--;
    int cant = cnt[compress[a[index]]];
    if (cant == a[index]){
        value++;
    } else if (cant == a[index]-1){
        value--;
    }
}

bool qcomp(const Qu& a, const Qu& b) {
  if (a.l / sq != b.l / sq) return a.l < b.l;
  return (a.l / sq) & 1 ? a.r < b.r : a.r > b.r;
}

void mos(int a[]) {
//   forn(i, nq) qs[i].id = i;
  sq = sqrt(n) + .5;
  sort(qs, qs + nq, qcomp);
  int l = 0, r = 0;
//   init(); supongo que no lo necesito
  forn(i, nq) {
    Qu q = qs[i];
    while (l > q.l) add(--l, a);
    while (r < q.r) add(r++, a);
    while (l < q.l) remove(l++, a);
    while (r > q.r) remove(--r, a);
    ans[q.id] = get_ans();
  }
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> nq;
    int a[n];
    vector<pair<int,int>> v; 
    fr(0,n) {
        cin >> a[i];
        v.pb({a[i], i});
    }
    fr(0,nq){
        int l,r; cin >> l >> r; l--;
        qs[i] = {l,r,i};
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        compress[v[i].first] = i;
    }
    // for (int i = 0; i < n; i++) {
    //     compressedA[i] = compress[a[i]];
    // }

    memset(cnt, sizeof(cnt), 0);    
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