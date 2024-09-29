#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 405
ll n; ll a[MAXN];
ll dp[MAXN][MAXN];
ll p[MAXN];

ll suma(int l, int r){
    ll res = p[r];
    if (l > 0){
        res-=p[l-1];
    }
    return res;
}

ll f(int l, int r){
    if (l == r){
        return dp[l][r] = 0;
    }
    ll &res = dp[l][r];
    if (res != -1) return res;
    res = 1e18;
    // fr(l, r+1){
    //     if (i == l){
    //         res = min(res, f(i+1, r) + suma(l, r));
    //     } else if (i == r){
    //         res = min(res, f(l, i-1) + suma(l, r));
    //     } else {
    //         res = min(res, f(l, i-1) + f(i+1, r) + min(suma(l, i-1), suma(i+1, r)) + a[i] + suma(l,r));
    //     }
    // }
    fr(l, r){
        res = min(res, f(l, i) + f(i+1, r) + suma(l,r));
    }
    return dp[l][r] = res;
}

void solve() {
    cin >> n; fr(0,n) cin >> a[i];
    p[0] = a[0];
    fr(1,n){
        p[i] = p[i-1] + a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0,n-1);
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