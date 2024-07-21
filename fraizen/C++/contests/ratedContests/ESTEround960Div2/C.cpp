#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll mad[n];
    fr(0,n){
        mad[i] = 0;
    }
    ll res = 0;
    fr(0,n){
        res += a[i];
    }
    map<ll,ll> m, m2;
    fr(0,n){
        m[a[i]]++;
        if (m[a[i]] == 2){
            m2[a[i]] = 1;
        }
        if (m2.size() > 0){
            mad[i] = m2.rbegin()->first;
        }
    }
    map<ll,ll> m3;
    ll repetido = 0;
    fr(0,n){
        m3[mad[i]]++;
        if (m3[mad[i]] == 2){
            repetido = i;
            break;
        }
    }
    fr(0,n){
        res += mad[i];
    }
    if (repetido == 0){
        cout << res << '\n'; return;
    }
    // fr(0,n){
    //     cout << mad[i] << " ";
    // }
    // cout << endl;
    map<ll,vector<ll>> pos;
    fr(0,n){
        if (mad[i] > 0){
            pos[mad[i]].pb(i);
        }
    }
    // cout << "here res = " << res << endl;
    ll cur = 0;
    //todo lo de abajo esta en 0 digamos.
    // lo voy cambiando
    ll i = 0;

    fre(pos){
        if (e.second.size() >= 2){
            // cout << "Estoy con " << e.first << " xq tiene repetidos " << endl;
            // cout << "posisciones " << endl;
            // for(auto e2: e.second){
            //     cout << e2 << ' ';
            // }
            // cout << endl;
            //tengo que cambiar desde el segundo hasta el final.
            //calculo la cantidad de posiciones
            ll cant = 0;
            //sumar desde i-1 hasta que termine todo ? 
            i = e.second[1];
            // cout << "i - "
            // cout << "i = " << i << endl;
            ll j = i-1;
            // cant = ((n-1) * (n-2) / 2) - (j*(j-1)/2);
            // cout << "prim " << (n * (n-1) / 2) << endl;
            // cout << "sec " <<(j*(j-1)/2) << endl;
            cant = (n+1-i)*(n-i)/2;
            // cout << "dif " << n-i << endl;
            // cout << "cant = " << cant << endl;
            res += (cant * (e.first - cur));
            cur = e.first;
        }
    }

    // int j = 1;
    // for(int i = n-1; i >= 0; i--){
    //     res += (mad[i] * j);
    //     j++;
    // }
    cout << res << '\n';
    // cout << '\n';
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