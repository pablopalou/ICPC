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

ll a[1005];
ll n; 
ll dp[1005][1005];

ll f(int p, int t){
    if (p == n){
        return 0;
    }
    ll &res = dp[p][t];
    if (res!=-1) return res;
    res = min(abs(a[p]-a[p+1]) + f(p+1, t), abs(a[p+1]-a[t]) + f(p+1, p));
    return res;
}

void solve() {
    cin >> n;  a[0]=0;fr(1,n+1) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << f(0,0);
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