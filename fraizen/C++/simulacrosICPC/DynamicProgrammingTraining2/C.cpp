#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
int dp[105][105][105];
int vengo[105][105][105];

void solve() {
    int n,energy,m; cin >>n>>energy >>m;
    vector<tuple<int,int,int>> v;
    fr(0,n){
        int val,f,t; cin >> val >> f >> t; v.pb({val,f,t});
    }
    memset(dp, 0, sizeof(dp));
    memset(vengo, 0, sizeof(vengo));
    fr(1,n+1){
        rep(j,0,102){
            rep(k,0,102){
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= get<1>(v[i-1]) && k >= get<2>(v[i-1])){
                    if (dp[i-1][j-get<1>(v[i-1])][k-get<2>(v[i-1])] + get<0>(v[i-1]) > dp[i][j][k]){
                        vengo[i][j][k] = 1;
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-get<1>(v[i-1])][k-get<2>(v[i-1])] + get<0>(v[i-1]));
                }
            }
        }
    }

    tuple<int,int,int> maxi;
    int res = 0;
    rep(j,0,energy+1){
        rep(k,0,m+1){
            if (dp[n][j][k] > res){
                maxi = {n,j,k};
            }
            res = max(res, dp[n][j][k]);
        }
    }
    cout << res << '\n';
    vector<int> ans;
    for(int i = n; i>=1; i--){
        if (vengo[i][get<1>(maxi)][get<2>(maxi)] == 1){
            ans.pb(i);
            maxi = {i,get<1>(maxi) - get<1>(v[i-1]), get<2>(maxi) - get<2>(v[i-1])};
        }
    }
    sort(ans.begin(), ans.end());
    fre(ans){
        cout << e << ' ';
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