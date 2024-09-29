#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100
ll dp[MAXN];
ll n,k;
ll h[MAXN];
#define inf 1e18;

ll f(int i){
    if (i == 0) return 0;
    if (i < 0) return inf;
    ll &res = dp[i];
    if (res != -1) return res;
    res = inf;
    rep(j,1,k+1){
        if (i-j >= 0){
            res = min(res, f(i-j) + abs(h[i]-h[i-j]));
        }
    }
    return res;
}

void solve() {
    cin >> n >> k; fr(0,n) cin >> h[i];
    memset(dp, -1, sizeof(dp));
    cout << f(n-1) << '\n';
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