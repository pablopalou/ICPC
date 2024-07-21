#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007

ll dp[1000010][2];

void fillDp(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    fr(2,1000010){
        dp[i][0] = ((2*dp[i-1][0]) % mod + dp[i-1][1] % mod) % mod;
        dp[i][1] = ((4*dp[i-1][1]) % mod + dp[i-1][0] % mod) % mod;
    }
}

void solve() {
    int n; cin >> n;
    cout << ((dp[n][0] + dp[n][1]) % mod) << '\n';
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
    memset(dp, 0, sizeof(dp));
    fillDp();
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}