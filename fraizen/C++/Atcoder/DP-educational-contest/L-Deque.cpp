#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll dp[3005][3005]; //podria tener cualquier valor
bool vis[3005][3005];
ll n;
ll a[3005];

ll f(ll l, ll r){
    ll &res = dp[l][r];
    if (vis[l][r]) return res;
    if (l == r) return a[l];
    vis[l][r] = true;
    res = max(a[l] - f(l+1, r), a[r] - f(l, r-1));
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n) cin >> a[i];
    cout << f(0,n-1) << "\n";
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