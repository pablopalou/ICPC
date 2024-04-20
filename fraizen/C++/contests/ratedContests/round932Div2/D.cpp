#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    ll n, c; cin >> n >> c;
    ll a[n];
    fr(0,n) cin >> a[i];
    ll res = ((c+1) * (c+2) )/ 2;
    int pares = 0;
    int impares = 0;
    //ahora voy restando.
    fr(0,n){
        res -= (a[i]/2) + 1;
        res -= (c+1 - a[i]);
        res++; //sumo el que conte dos veces
        //todavia tengo que sumar los repetidos con los anteriores.
        if (a[i] % 2 == 1){
            res += impares;
            impares++;
        } else {
            res += pares;
            pares++;
        }
    }
    cout << res << "\n";
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