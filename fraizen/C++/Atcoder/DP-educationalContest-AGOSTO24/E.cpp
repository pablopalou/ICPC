#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 101
ll n,w;
ll pesos[MAXN];
ll v[MAXN];
ll dp[MAXN][MAXN*1001];
#define inf 10000000000

ll f(int i, int val){
    if (val < 0) return 100000000000000000;
    ll &res = dp[i][val];
    if (res!=-1) return res;
    return dp[i][val] = min(f(i+1, val), f(i+1, val-v[i]) + pesos[i]);
}

void solve() {
    cin >> n >> w;
    ll maxVal = 0;
    fr(0,n){
        cin >> pesos[i] >> v[i];
        maxVal+=v[i];
    }
    memset(dp,-1,sizeof(dp));
    ll res = 0;
    //si quedan por poner n (o sea no puse ninguno), tengo 0 de valor, logrando eso con 0 de peso, en cualquier otro caso, es imposible.
    dp[n][0] = 0;
    fr(1,maxVal+1){
        dp[n][i] = 100000000000000000;
    }
    fr(0,maxVal+1){
        if (f(0,i) <= w){
            res = max(res, ll(i));
        }
    }
    cout << res; 
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