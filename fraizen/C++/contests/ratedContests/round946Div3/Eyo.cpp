#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define inf 1e18

void solve() {
    ll m,x; cin >> m>> x;
    ll cost[m];
    ll hap[m];
    ll totHap = 0;
    fr(0,m){
        cin >> cost[i] >> hap[i];
        totHap += hap[i];
    }
    ll dp[totHap+1];
    fr(0,totHap+1){
        dp[i] = inf;
    }
    dp[0] = 0;
    fr(0,m){
        for(int j = totHap; j>=0; j--){
            if ((j + hap[i] <= totHap) && (dp[j] + cost[i] <= (i*x))){
                dp[j + hap[i]] = min(dp[j + hap[i]], dp[j] + cost[i]);
            }
        }
    }
    ll res = 0;
    fr(0, totHap+1){
        if (dp[i] != inf){
            res = max(res, i);
        }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}