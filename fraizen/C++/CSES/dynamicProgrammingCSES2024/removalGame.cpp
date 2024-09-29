#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[5001][5001];
ll a[5001];
ll solveDP(ll l, ll r){
    if (l > r){
        return 0;
    }
    if (l == r){
        return a[l];
    }
    if (dp[l][r]!=-1){
        return dp[l][r];
    }
    return dp[l][r] = max(- solveDP(l+1, r) + a[l], - solveDP(l, r-1) + a[r]);
}

void solve() {
    ll n; cin >> n; fr(0,n) cin >> a[i];
    ll diferencia = solveDP(0,n-1);
    ll total = 0;
    fr(0,n) total+=a[i];
    if (diferencia >= 0){
        cout << (total - diferencia) / 2 + diferencia << '\n';
    } else {
        diferencia *= -1;
        cout << total - ((total - diferencia) / 2 + diferencia) << '\n';
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
        memset(dp, -1, sizeof(dp));
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}