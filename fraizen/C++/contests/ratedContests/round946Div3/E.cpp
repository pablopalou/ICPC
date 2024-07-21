#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

const ll INF = 1e18;

void solve() {
    int m, x;
    cin >> m >> x;
    vector<pair<ll, ll>> offers(m); // Vector para almacenar las ofertas de (costo, felicidad)

    // Leer las ofertas
    for(int i = 0; i < m; ++i) {
        cin >> offers[i].first >> offers[i].second;
    }
    ll sumaHap = 0;
    fr(0,m){
        sumaHap+=offers[i].second;
    }

    // dp[j] representa el costo mínimo para obtener j de felicidad
    vector<ll> dp(sumaHap+1, INF);
    dp[0] = 0;

    // Iterar sobre cada mes
    for(ll i = 0; i < m; ++i) {
        // Actualizar el DP de forma decreciente para evitar usar el mismo mes múltiples veces
        for(ll happiness = sumaHap; happiness >= 0; --happiness) {
            if(dp[happiness] != INF && dp[happiness] + offers[i].first <= (i) * x) {
                dp[happiness + offers[i].second] = min(dp[happiness + offers[i].second], dp[happiness] + offers[i].first);
            }
        }
    }

    // Encontrar la máxima felicidad que se puede obtener con el dinero disponible
    ll max_happiness = 0;
    for(ll happiness = 0; happiness <= sumaHap; ++happiness) {
        if(dp[happiness] != INF) {
            max_happiness = max(max_happiness, happiness);
        }
    }

    cout << max_happiness << "\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}