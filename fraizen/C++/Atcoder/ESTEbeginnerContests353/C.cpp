#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mod 100000000

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n; ll a[n];
    fr(0,n) cin >> a[i];
    map<ll,ll> m;
    ll res = 0;
    sort(a,a+n);
    fr(0,n){
        m[a[i]]++;
    }
    fr(0,n){
        res += (a[i] * (n-1));
        // cout << "i " << i << endl;
        ll cant = 0;
        //ahora tengo que sacarle de a 100 millones a todas las combinaciones malas
        if (a[i] >= 50000000){
            cant = (a+n) - lower_bound(a,a+n, a[i]+1);
            m[a[i]]--;
            cant+=m[a[i]];
        } else {
            cant = (a+n) - lower_bound(a, a+n, mod - a[i]);
        }
        // cout << cant << endl;
        res -= cant * mod; 
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}