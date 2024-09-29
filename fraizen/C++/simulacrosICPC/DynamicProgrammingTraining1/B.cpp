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
#define mp make_pair

void solve() {
    ll n,b; cin >> n >> b;
    vector<tuple<ll,ll,ll>> revCost;
    fr(0,n){
        int cant; cin >> cant;
        rep(j,0,cant){
            int rev, cost; cin >> rev >> cost;
            revCost.pb({rev, cost, i});
        }
    }
    ll res = 0;
    for(int mask = 1; mask < (1 << revCost.size()); mask++){
        //me fijo si la mascara cumple las condiciones (1 forma de lanzar proyecto como mucho y ademas dentro del budget)
        bool cumple = true;
        bool tengo[20];
        fr(0,20) tengo[i] = false;
        ll ganancia = 0;
        ll costo = 0;
        for(int i = 0; i<revCost.size(); i++){
            if ((mask & (1<<i)) != 0){
                if (tengo[get<2>(revCost[i])]){
                    cumple = false;
                    break;
                }
                tengo[get<2>(revCost[i])] = true;
                costo += get<1>(revCost[i]);
                ganancia += get<0>(revCost[i]);
            }
        }
        if (cumple && costo <= b){
            res = max(res, ganancia);
        }
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