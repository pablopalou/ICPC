#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
const ll MAXN = 2005;
ll dp[MAXN][MAXN];
ll a[MAXN];
// Copiar obligatoriamente 0

ll solveDP(ll l, ll r){
    if (l == r){
        return 0;
    }
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    return dp[l][r] = a[r] - a[l] + min(solveDP(l+1, r), solveDP(l, r-1));
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    memset(dp, -1, sizeof dp);
    cout << solveDP(0,n-1) << "\n";
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