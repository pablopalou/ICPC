#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 1200000

void solve() {
    ll n, x; cin >> n >> x;
    ll w[n]; fr(0,n) cin >> w[i];
    pair<ll, ll> dp[MAXN];
    fr(0,MAXN){
        dp[i] = {1e25, 1e12};
    }
    dp[0] = {0, 0};
    for(int mask = 0; mask < (1<<n); mask++){
        // cout << "Mask = " << mask << endl;
        fr(0,n){
            if (((1<<i) & mask) == 0){
                // cout << "El bit i =" << i << " esta apagado " << endl; 
                int newMask = mask | (1<<i);
                // cout << "Nueva mascara = " << newMask << endl;
                pair<ll,ll> p = dp[mask];
                if (w[i] + p.second <= x){
                    dp[newMask] = min(dp[newMask], {p.first, p.second + w[i]});
                } else {
                    dp[newMask] = min(dp[newMask], {p.first + 1, w[i]});
                }
                // cout << dp[newMask].first << ' ' << dp[newMask].second << '\n';
            }
        }
    }
    if (dp[(1<<n) - 1].second > 0){
        cout << dp[(1<<n) - 1].first +1 << "\n";
    } else {
        cout << dp[(1<<n) - 1].first  << "\n";
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
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}