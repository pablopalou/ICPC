#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define inf 1e18
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n; ll a[n];
    fr(0,n) cin >> a[i];
    ll minimo = inf;
    ll maximo = -inf;
    fr(0,n){
        minimo = min(minimo, a[i]);
        maximo = max(maximo,a[i]);
    }
    int iter = 0;
    vector<int> res;
    while(minimo!=maximo){
        iter++;
        if (minimo % 2){
            res.pb(1);
            minimo = (minimo+1)/2;
            maximo = (maximo+1)/2;
        } else {
            res.pb(0);
            minimo = minimo/2;
            maximo = maximo/2;
        }
    }
    cout << iter << "\n";
    if (iter <= n && iter > 0){
        fr(0,res.size()){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
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