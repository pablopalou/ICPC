#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
ll n; 
#define MAXN 3003
ll a[MAXN];
ll dp[MAXN][MAXN];

ll f(int l, int r){
    if (l == r) return a[l];
    ll &res = dp[l][r];
    if (res!=-1) return res;
    return dp[l][r] = max(-f(l+1,r)+a[l], a[r] - f(l,r-1));
}

void solve() {
    cin >> n; fr(0,n) cin >> a[i];
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