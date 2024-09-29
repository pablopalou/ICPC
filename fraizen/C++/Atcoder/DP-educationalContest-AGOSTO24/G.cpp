#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

#define MAXN 100100
int dp[MAXN];
vector<vector<int> > adj(MAXN);

int dfs(int i){
    int &res = dp[i];
    if (res != -1) return res;
    int ans = 0;
    fre(adj[i]){
        ans = max(ans, dfs(e) + 1);
    }
    return res =ans;
}

void solve() {
    int n,m; cin >> n >> m;
    fr(0,m){
        int u,v; cin >> u >> v; u--;v--;
        adj[u].pb(v);
    }
    memset(dp,-1,sizeof(dp));
    int res = 0;
    fr(0,n){
        res = max(res, dfs(i));
    }
    cout << res << '\n';
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