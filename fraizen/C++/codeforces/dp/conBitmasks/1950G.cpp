#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mp make_pair

void solve() {
    int n; cin >> n;
    vector<string> vals;
    vector<string> v1;
    vector<string> v2;
    int a[n];
    int b[n];
    fr(0,n){
        string s1,s2; cin >> s1 >>s2;
        vals.pb(s1);
        vals.pb(s2);
        v1.pb(s1);
        v2.pb(s2);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    fr(0,n){
        a[i] = lower_bound(vals.begin(), vals.end(), v1[i]) - vals.begin();
        b[i] = lower_bound(vals.begin(), vals.end(), v2[i]) - vals.begin(); 
    }
    //ahora tenemos en a y en b en vez de strings, numeros, que son mejor pa comparar.
    //ahora si arranco la dp con bitmasks
    vector<vector<int>> dp(1<<n, vector<int>(n, 0));
    fr(0,n) dp[1 << i][i] = 1;
    rep(mask, 0,1<<n){
        rep(last,0,n){
            rep(k,0,n){
                if ((mask >> k) & 1) continue; //ya esta prendido ese bit
                //prendo el bit si puedo...
                if (a[last] == a[k] || b[last] == b[k]){
                    dp[mask | (1<<k)][k] |= dp[mask][last];
                }
            }
        }
    }
    int ans = 0;
    rep(mask, 0, 1 << n){
        fr(0,n){
            if (dp[mask][i]){
                ans = max (ans, __builtin_popcount(mask));
            }
        }
    }
    cout << n - ans << '\n';
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
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}