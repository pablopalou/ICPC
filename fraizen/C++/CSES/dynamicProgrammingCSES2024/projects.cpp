#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 200100

ll dp[MAXN];
ll n;
ll s[MAXN], e[MAXN], w[MAXN];
tuple<ll,ll,ll> t[MAXN];

ll solveDp(ll i){
    // cout << "i = " << i << endl;
    if (i >= n){
        return 0;
    }
    if (dp[i] != -1){
        return dp[i];
    }
    auto it = upper_bound(s, s+n, e[i]);
    // cout <<"here " <<   *it << endl;
    // cout << e[i] << endl;
    // cout << "desde i = " << i << " , llamo al " << it-s << " yo tengo " << w[i] << endl;
    dp[i] = max(solveDp(i+1), w[i] + solveDp(it - s ));
    // cout << "dp[ "<< i <<"] = " << dp[i] << endl;
    return dp[i];
}

void solve() {
    cin >> n;
    fr(0,n){
        ll x,y,z; cin >> x >> y >> z;
        t[i] = {x,y,z};
    }
    sort(t, t+n);
    fr(0,n){
        s[i] = get<0>(t[i]);
        e[i] = get<1>(t[i]);
        w[i] = get<2>(t[i]);
    }
    // fr(0,n){
    //     cout << s[i] << ' ';
    // }
    // cout << endl;
    memset(dp,-1,sizeof(dp));
    cout << solveDp(0) << '\n';
    // fr(0,n){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
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