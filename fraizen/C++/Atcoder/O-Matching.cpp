#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mod 1000000007

ll a[22];
ll dp[22][(1<<21) + 20];
ll n;

ll f(ll x, ll y){ // y representa los disponibles
    ll &res = dp[x][y];
    if (res != -1) return res;
    if (x == n) return 1; //caso base => matching vacio pues no hay nada, unica opcion
    //caso normal, sumo todos los matchings anteriores digamos y armo la nueva pareja si es posible
    res = 0;
    ll m = y & a[x]; //agarro los disponibles y los cruzo con los que yo soy compatible.
    fr(0,n){
        //pruebo unirme con el m
        if ((1<<i) & m){ //si me puedo unir entonces sumo eso
            res += f(x+1, y^(1<<i)); //apago el disponible.
            if (res > mod) res-=mod;
        }
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n){
        ll mask = 0;
        rep(j,0,n){
            int leer; cin >> leer;
            mask*=2;
            mask+= leer;
        }
        a[i] = mask;
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, (1<<n)-1) << "\n";
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