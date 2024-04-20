#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mod 1000000007

ll n,k;

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> k;
    vector<int> a(n + 1);
    fr(0,n) cin >> a[i];
    vector<vector<int> > dp(n + 1, vector<int>(1 << 6, 0));
    fr(1,n+1){
        rep(mask,0,1<<6){
            dp[i][mask] = dp[i-1][mask];
            if (dp[i][mask] > mod) dp[i][mask] -= mod;
            dp[i][mask & (a[i-1])] += dp[i-1][mask];
            if (dp[i][mask & (a[i-1])] > mod) dp[i][mask & (a[i-1])] -= mod;
        }
        dp[i][a[i-1]]++;
        if (dp[i][a[i-1]] > mod) dp[i][a[i-1]] -= mod;
    }
    ll res = 0;
    fr(0,64){ //paso por cada una de las mascaras de 0 hasta 111111
        if (__builtin_popcount(i) == k){
            res += dp[n][i];
            if (res > mod){
                res-=mod;
            }
        }
    }
    cout << res << "\n";
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