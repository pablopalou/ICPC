#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 101

ll n,peso;
ll w[MAXN];
ll v[MAXN];
ll dp[MAXN][100100];

ll f(int i, int curW){
    if (i < 0 or curW == 0) return 0;
    ll &res = dp[i][curW];
    if (res != -1) return res;
    res = f(i-1,curW);
    if (curW - w[i] >= 0){
        res = max(res, f(i-1, curW-w[i]) + v[i]);
    }
    return res;
}

void solve() {
    cin >> n >> peso;
    fr(0,n){
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(n-1,peso);
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