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
#define MAXN 5005
ll dp[MAXN][MAXN];
ll n;
ll a[MAXN];

ll f(int l, int r){
    if (l > r){ return 0;}
    ll &res = dp[l][r];
    if (res != -1) return res;
    if (l == r){
        res = a[l] * n; 
        return res;
    }
    //ahora pruebo agarrar de la izq y de la derecha
    ll iter = 1 + l + (n-1-r);
    res = max(f(l+1, r) + a[l] * iter, f(l, r-1) + a[r] * iter);
    return res;
}

void solve() {
    cin >> n; fr(0,n) cin >> a[i];
    ll res = 0;
    memset(dp, -1, sizeof(dp));
    cout << f(0,n-1) << '\n';
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