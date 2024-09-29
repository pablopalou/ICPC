#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
typedef long double ld;

void solve() {
    ll n,a,b; cin >> n>>a>>b;
    ld dp[101][601];
    memset(dp,0,sizeof(dp));
    rep(j,1,7){
        dp[1][j] = 1.0/6;
    }
    fr(2,n+1){
        rep(j,i,6*i+1){
            rep(k,1,7){
                if (j > k){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j] *= 1.0/6;
        }
    }
    ld res = 0.0;
    fr(a,b+1){
        res += dp[n][i];
    }
    cout << fixed << setprecision(6) << res << '\n';
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