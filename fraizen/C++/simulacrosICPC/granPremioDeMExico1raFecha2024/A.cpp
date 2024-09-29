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
#define MAXN 10005
#define inf 1e9
int dp[MAXN][MAXN];

void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    for(int largo = 1; largo < n;largo++){
        if (largo == 1){
            rep(j,0,n-1){
                dp[j][j+1] = abs(a[j]-a[j+1]);
            }
        } else {
            rep(j,0,n-largo){
                int l = j;
                int r = j+largo;
                // cout << "L = " << l << " r = " << r << endl;
                dp[l][r] = min({dp[l][r-1], dp[l+1][r], abs(a[l]-a[r])});
            }
        }
    }
    int q; cin >> q;
    fr(0,q){
        int l,r; cin >> l >> r; l--; r--;
        cout << dp[l][r] <<'\n';
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