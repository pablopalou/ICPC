#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
const int MAXN = 105;
ll n,w;
ll pesos[MAXN];
ll v[MAXN];
ll dp[MAXN][100005];
#define inf 10000000000

ll f(ll x, ll val){
    if (val < 0) return inf;
    ll &res = dp[x][val];
    if (x==n && val==0) {
        dp[x][0] = 0;
        return 0;
    }
    if (x==n) return inf;
    if (res != -1) return res;
    res = min(f(x+1,val), f(x+1,val-v[x]) + pesos[x]);
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> w;
    fr(0,n){
        cin >> pesos[i] >> v[i];
    }
    fr(0,100){
        rep(j, 0, 1000*100+1){
            dp[i][j] = -1;
        }
    }
    int maximo = 1000 * 100;
    for(int i = maximo; i > 0; i--){
        if (f(0,i) <= w){
            cout << i << "\n";return;
        }
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