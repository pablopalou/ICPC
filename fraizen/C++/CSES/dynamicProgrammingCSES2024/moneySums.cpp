#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100

// En local da sigsev por tema de memoria (10 millones), pero cuando lo subo anda joya.
void solve() {
    int n; cin >> n;
    int a[n]; fr(0,n) cin >> a[i];
    bool dp[100][MAXN];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    dp[0][a[0]] = true;
    fr(1,n){
        for(int j = MAXN-1; j >= 0; j--){
            dp[i][j] = dp[i-1][j];
            if (j - a[i] >= 0){
                dp[i][j] |= dp[i-1][j-a[i]];
            }
        }
    }
    // fr(0,n){
    //     rep(j,0,15){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<ll> res;
    fr(1,MAXN-2){
        if (dp[n-1][i]){
            res.pb(i);
        }
    }
    cout << res.size() << "\n";
    fre(res){
        cout << e << ' ';
    }
    cout << '\n';
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