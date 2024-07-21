#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n, k, e; cin >> n >> k >> e;
    int izq = e;
    int der = n - k - e;
    bool dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; //lleno algo de 0 y otra cosa de 0, entonces es true xq ya esta completo
    rep(tile,1,n){
        if (tile == k) continue;
        for(int i = izq; i>=0; i--){
            for(int j=der; j>=0; j--){
                if (i >= tile){
                    dp[i][j] |= dp[i-tile][j];
                }
                if (j >= tile){
                    dp[i][j] |= dp[i][j-tile];
                }
            }
        }
    }
    int ans = k;
    fr(0,izq+1){
        rep(j,0,der+1){
            if (dp[i][j]){
                ans = max(ans, k + i + j);
            }
        }
    }
    cout << n - ans << '\n';
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