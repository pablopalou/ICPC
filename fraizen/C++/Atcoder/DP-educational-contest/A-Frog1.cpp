#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
const int MAXN = 100005;
int dp[MAXN];
int n;
int h[MAXN];

void fillDP(int x){
    if (dp[x] != -1){
        return dp[x];
    }
    if (n-1 == x){
        return dp[x] = abs(h[n-1] - h[n-2]);
    } else {
        return dp[x] = min(abs(h[x] - h[x+1]) + dp[x+1], abs(h[x] - h[x+2]) + dp[x+2]);
    }
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n){
        cin >> h[i];
    }
    fill(dp, dp+MAXN, -1);
    dp[n] = 0;
    fillDP(n-1);
    cout << dp[0] << "\n";
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