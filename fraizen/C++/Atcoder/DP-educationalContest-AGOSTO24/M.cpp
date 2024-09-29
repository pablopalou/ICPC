#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 101
#define mod 1000000007

ll n,k; ll a[MAXN];
ll dp[102][100100];
ll p[102][100100];

void solve() {
    cin >> n >> k; fr(1,n+1) cin >> a[i]; a[0] = 0; 
    memset(dp, -1, sizeof(dp));
    fr(0,k+1){
        dp[0][i] = 0;
        p[0][i] = 1;
    }
    dp[0][0] = 1;
    fr(1,n+1){
        dp[i][0] = 1;
        p[i][0] = 1;
    }
    //agregar caso base 0 caramelos para x ninos
    fr(1,n+1){
        rep(j,1,k+1){
            dp[i][j] = p[i-1][j];
            if (j-a[i]-1 >= 0){
                dp[i][j] = (dp[i][j] - p[i-1][j-a[i]-1] + mod) % mod;
            }
            p[i][j] = (dp[i][j] + p[i][j-1]) % mod;
        }
    }

    cout << dp[n][k] << "\n";
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