#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)

const ll MAXN = 3e5;
ll freq[MAXN] = {};  // Frequency array
ll distinct = 0; // Number of distinct elements
ll n,sq,nq; // array size, sqrt(array size), #queries
struct Qu{ //[l, r)
    ll l,r,id;
};
Qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query

bool qcomp(const Qu &a, const Qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

void add(ll index, ll a[]) {
    if (freq[a[index]] == 0) {
        distinct++;
    }
    freq[a[index]]++;
}

void remove(ll index, ll a[]) {
    assert(freq[a[index]] > 0);
    freq[a[index]]--;
    if (freq[a[index]] == 0) {
        distinct--;
    }
}

ll get_ans() {
    return distinct;
}

void mos(ll a[]){
    sq = sqrt(n) + 0.5; // without updates
    sort(qs, qs + nq, qcomp);
    ll l = 0, r = 0;
    for (ll i = 0; i < nq; i++) {
        Qu q = qs[i];
        while (l > q.l) add(--l, a);
        while (r < q.r) add(r++, a);
        while (l < q.l) remove(l++, a);
        while (r > q.r) remove(--r, a);
        ans[q.id] = get_ans();
    }
}
void compressCoordinates(vector<ll>& a) {
    vector<ll> allValues = a; // Copy all values
    sort(allValues.begin(), allValues.end()); // Sort the values
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end()); // Remove duplicates

    for (ll& x : a) {
        x = lower_bound(allValues.begin(), allValues.end(), x) - allValues.begin(); // Map to index
    }
}

void solve() {
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    compressCoordinates(a);
    for (ll i = 0; i < nq; i++) {
        ll l, r; cin >> l >> r;
        l--; // Converting to 0-indexed
        qs[i] = {l, r, i};
    }
    mos(a.data()); // Passing the underlying array to mos
    for (ll i = 0; i < nq; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    ll cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}
