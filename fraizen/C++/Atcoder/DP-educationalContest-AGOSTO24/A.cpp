#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[100100];
ll a[100100];

ll f(int i){
    if (i <= 1) return 0;
    ll &res = dp[i];
    if (res!=-1) return res;
    res = f(i-1) + abs(a[i]-a[i-1]);
    if (i-2 >= 1){
        res = min(res, f(i-2) + abs(a[i]-a[i-2]));
    }
    return res;
}

void solve() {
    ll n; cin >> n; fr(1,n+1) cin >> a[i];
    memset(dp, -1,sizeof(dp));
    cout << f(n) << '\n'; 
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