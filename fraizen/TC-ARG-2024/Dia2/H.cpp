#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,m,k; cin >> n >> m >> k;
    ll a[n]; fr(0,n) cin >> a[i];
    ll res = 0;
    if (m <= k+1){ //puedo fixear todo
        fr(0,m){ //lado izq elijo i. lado derecho elijo m-i.
            //ahora tengo desde i hasta n-1-(k-i)
            ll cur = 1e18;
            cur = min(cur, max(a[i], a[n-1-(m-1-i)]));
            res = max(res, cur);
        }
        cout << res << '\n';
        return;
    }

    fr(0,min(k+1, m)){ //lado izq elijo i. lado derecho elijo k-i.
        //ahora tengo desde i hasta n-1-(k-i)
        ll cur = 1e18;
        rep(j,0,m-k){
            //saco j desde la izquierda. Desde la derecha elijo m-k-1-j
            //queda i+j hasta n-1-(k-i)-(m-k-1-j)
            //ahora me quedo con el maximo de las dos opciones:
            cur = min(cur, max(a[i+j], a[n-1-(k-i)-(m-k-1-j)]));
        }
        res = max(res, cur);
    }
    cout << res << '\n';
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