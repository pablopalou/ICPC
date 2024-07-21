#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mp make_pair

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
indexedSet;
// find_by_order(i) returns iterator to the i-th elemnt
// order_of_key(k): returns position of the lower bound of k (0-indexed)
// Ej: 12, 100, 505, 1000, 10000.
// order_of_key(10) == 0, order_of_key(100) == 1,
// order_of_key(707) == 3, order_of_key(9999999) == 5

// Copiar obligatoriamente 0
void solve() {
    //ESTO SOLUCION COMENTADA DA TLE
    // ll n,t; cin >>n >>t; int a[n];
    // fr(0,n) cin >> a[i];
    // set<ll> s;
    // ll suma = 0;
    // fr(0,n){
    //     suma+=a[i];
    //     s.insert(suma);
    // }
    // ll res = 0;
    // ll fraizen = 0;
    // fr(0,n){
    //     auto it = lower_bound(s.begin(), s.end(), t + fraizen);
    //     res += distance(s.begin(), it);
    //     fraizen+=a[i];
    //     s.erase(fraizen);
    // }
    // cout << res << '\n';

    //si yo dejo el indexed_set solo con el valor, hay problema con los repetidos obviamente. Entonces guardo parejas adentro
    ll n,t; cin >>n >>t; ll a[n];
    fr(0,n) cin >> a[i];
    indexedSet s;
    ll suma = 0;
    fr(0,n){
        suma+=a[i];
        s.insert(mp(suma,i));
    }
    ll res = 0;
    ll fraizen = 0;
    fr(0,n){
        res += s.order_of_key(mp(t+fraizen,0));
        fraizen+=a[i];
        s.erase(mp(fraizen,i));
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