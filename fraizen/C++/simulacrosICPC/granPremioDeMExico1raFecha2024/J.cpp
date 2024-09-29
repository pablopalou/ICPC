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
#define inf 1e9

ll dp[501][501][501]; //de l a r, de largo k. 
string s;
ll f(ll l, ll r, ll k){
    if (l > r+1){
        return inf;
    }
    if (k == 0){
        return 0;
    }
    if (l > r or k < 0){
        return inf;
    }
    if (k <= 1){
        return 0; //siempre puedo agarrar uno de largo 1 (y de largo 0 seria que ya termine)
    }
    if (dp[l][r][k]!=-1) return dp[l][r][k];
    ll &res = dp[l][r][k];
    res = min({f(l+1, r, k), f(l, r-1, k), f(l+1, r-1, k-2) + (s[l]!=s[r])});
    return res;
}

void solve() {
    ll n,k; cin >> n >> k; cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << f(0, n-1, k);   
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