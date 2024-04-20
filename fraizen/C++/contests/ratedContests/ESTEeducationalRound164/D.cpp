#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define MOD 998244353

ll add(ll x, ll y){
    return (x%MOD + y %MOD) % MOD;
}

ll mul(ll x, ll y){
    return (x%MOD * y%MOD) % MOD;
}

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >>n; ll a[n];
    ll s = 0;
    fr(0,n) cin >> a[i];
    fr(0,n) s+=a[i];
    //primero tengo que ver cuantos conjuntos tienen exactamente j bolas, para esto hago una mochila
    //luego, itero sobre todo y sumo a la respuesta i/2 multiplicado por el dp[i]
    //por ultimo, tengo que tener cuidado con los que son dominantes
    ll dp[s+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    fr(0,n){
        for(int j = s; j>=a[i] ;j--){
            dp[j] = add(dp[j], dp[j-a[i]]);
        }
    }
    ll ans = 0;
    fr(0,s+1){
        ans = add(ans, mul(dp[i], (i+1)/2));
    }
    //cuido los dominantes (tengo que iterar la suma de los demas hasta a[i] digamos, porque mas que eso ya no seria dominante...)
    fr(0,n){
        for(int j = 0; j<a[i]; j++){
            ans = add(ans, mul(a[i] - (j+a[i]+1)/2, dp[j]));
        }
    }
    cout << ans << "\n";
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
