#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll dp[405][405];
ll n;
ll a[405];
ll ps[405];
#define inf 1e18

ll f(ll l, ll r){
    ll &res = dp[l][r];
    if (res != -1) return res;
    //caso base
    if (l == r - 1){
        return 0; // no tengo costo xq no necesito unir
    }
    //caso de largo 2 o mas, me fijo donde puedo cortar
    res = inf;
    for(int i = l+1; i<r; i++){
        res = min(res, ps[r] - ps[l] + f(l,i) + f(i, r));
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n) cin >> a[i];
    ps[0] = 0;
    memset(dp, -1, sizeof(dp));
    fr(1,n+1){
        ps[i] = ps[i-1] + a[i-1];
    }
    cout << f(0,n) << "\n";
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