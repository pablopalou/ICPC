#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,m; cin >> n >>m;
    int a[n+1]; fr(1,n+1) cin >> a[i];
    if (n>=m) {
        cout << "YES\n"; return;}
    //n es menor que m
    bool dp[n+1][m];
    memset(dp, 0, sizeof(dp));
    fr(1,n+1){
        rep(j,0,m){
            if (dp[i-1][j]){
                dp[i][j] = true;
                dp[i][(j%m + a[i]%m)%m] = true;
            }            
        }
        dp[i][a[i]%m] = true;
    }
    if (dp[n][0]){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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