#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,k; cin >> n >> k; ll a[n]; fr(0,n) cin >> a[i];
    ll p[n];
    p[0] = a[0];
    fr(1,n){
        p[i] = p[i-1] + a[i];
    }
    ll index = 0;
    ll maxi = a[0];
    fr(0,n){
        if (a[i] > maxi){
            index = i;
            maxi = a[i];
        }
    }
    ll i = index; ll sumaIzq = 0;
    if (i != 0){
        sumaIzq = p[i-1];
    }
    ll sumaDer = p[n-1]-p[i];
    // cout << "smar" << sumaDer << '\n';
    rep(h, 1, 100000000){
        ll mini = i * h + (n-1-i)*(h-1);
        ll maximo = sumaIzq * h + sumaDer * (h-1);
        ll nro = k - (h-1)* maxi;
        if (nro < 0 or mini > nro){
            break;
        }
        if (nro >= mini && nro <= maximo){
            cout << "YES\n";
            return;
        }
    }
    cout << "KEK\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // #ifdef JP
    //     freopen("A.in", "r", stdin);
    //     freopen("A.out", "w", stdout);
	// #endif
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

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

