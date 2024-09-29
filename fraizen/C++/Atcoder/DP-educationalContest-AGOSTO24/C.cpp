#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100
ll dp[MAXN][3];
int n;
int a[MAXN], b[MAXN], c[MAXN];

ll f(int i, int cur){
    if (i == 0) return 0;
    ll &res = dp[i][cur];
    if (res != -1) return res;
    res = max(f(i-1, (cur+1)%3), f(i-1, (cur+2)%3));
    if (cur == 0){
        res += a[i];
    } else if(cur == 1){
        res += b[i];
    } else {
        res+= c[i];
    }
    return res;
}

void solve() {
    cin >> n;
    fr(1,n+1){
        cin >> a[i] >> b[i] >> c[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << max({f(n,0), f(n,1), f(n,2)});
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