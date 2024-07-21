#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int dp[1001][100100];
int cost[1001];
int pages[1001];

//DA TLE
ll solveDP(int n, int plata){
    if (n < 0 or plata < 0){
        return 0;
    }
    if (dp[n][plata] != -1){
        return dp[n][plata];
    }
    ll res =(solveDP(n-1, plata));
    if (plata >= cost[n]){
        res = max(res, solveDP(n-1, plata - cost[n]) + pages[n]);
    }
    return dp[n][plata] = res;
}

void solve() {
    int n, plata; cin >> n >> plata;
    fr(0,n) cin >> cost[i];
    fr(0,n) cin >> pages[i];
    // memset(dp,-1,sizeof(dp));
    // cout << solveDP(n-1, plata) << "\n"; DA TLE EL RECURSIVO
    memset(dp,0,sizeof(dp));
    //lo hago iterativo aca
    fr(1,n+1){
        rep(j,0,plata+1){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j >= cost[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i-1]] + pages[i-1]);
            }
        }
    }
    cout << dp[n][plata] << endl;
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