#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100
#define mod 1000000007

vector<vector<int>> adj(MAXN);
ll n;
ll dp[MAXN][2];
bool visited[MAXN];

void fillDP(int i, int padre){
    if (visited[i]) return;
    visited[i] = true;
    dp[i][0] = dp[i][1] = 1;
    fre(adj[i]){
        if (e == padre) continue;
        fillDP(e, i);
        dp[i][0] = ((dp[i][0] % mod ) * (dp[e][0] + dp[e][1]) % mod) % mod; 
        dp[i][1] = ((dp[i][1]) * (dp[e][0]) )% mod; 
    }
}

void solve() {
    cin >> n;
    fr(0,n-1){
        ll u,v; cin >> u >> v; u--;v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    memset(dp, -1, sizeof(dp));
    fillDP(0,-1);
    cout << (dp[0][0] + dp[0][1])%mod;
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