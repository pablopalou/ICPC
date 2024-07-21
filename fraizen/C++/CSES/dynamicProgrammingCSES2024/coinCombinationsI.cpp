#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MOD 1000000007

int dp[1000006];

void solve() {
    int n, x; cin >> n >> x; int a[n]; fr(0,n) cin >> a[i];
    fr(0,n){
        dp[a[i]] = 1;
    }
    fr(1,x+1){
        rep(j,0,n){
            if (i - a[j] > 0){
                dp[i] = (dp[i] +  dp[i-a[j]] % MOD)% MOD; //si agrego un mod mas aca, da tle
            }
        }
    }
    cout << dp[x] << "\n";
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