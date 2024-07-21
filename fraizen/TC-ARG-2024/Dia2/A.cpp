#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n, d,e; cin >> n >> d >> e;
    e = e*5;
    //pruebo comprar euros (tipo de 0 a lo maximo)
    ll res = 1e9;
    ll maxi = n/e;
    fr(0,maxi+1){
        //compro i euros
        ll cur = n;
        cur = n-e*i;
        //me sobran cur, ahora veo de usar el maximo posible de dolares
        ll dol = cur / d;
        cur -= dol*d;
        res = min(res, cur);
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}