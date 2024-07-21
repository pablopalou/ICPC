#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[1000100];

ll solveDP(ll n){
    if (n < 10){
        return 1;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    //saco cada digito y veo
    ll res = 1000000000;
    string s;
    s = to_string(n);
    fre(s){
        ll probar = e - '0';
        if (probar > 0){
            res = min(res, solveDP(n-probar) + 1);
        }
    }
    return dp[n] = res;    
}

void solve() {
    ll n; cin >>n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    cout << solveDP(n) << "\n";
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