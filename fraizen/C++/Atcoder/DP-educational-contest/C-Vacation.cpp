#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll n;
ll a[100005][3];
ll dp[100005][3];

ll f(ll x, ll prev){
    ll &res = dp[x][prev];
    if (x == n) return 0;
    if (res >= 0) return res;
    res = max(f(x+1, (prev+1)%3) + a[x][(prev+1)%3], f(x+1, (prev+2)%3) + a[x][(prev+2)%3]);
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    memset(dp, -1, sizeof(dp));
    cout << max(f(0,0), f(0,1)) << "\n";
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