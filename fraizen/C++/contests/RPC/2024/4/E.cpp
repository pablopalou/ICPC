#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mp make_pair

// Copiar obligatoriamente 0
void solve() {
    ll n,k; cin >> n>> k;
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    vector<pair<ll, ll>> res;
    ll suma = 0;
    ll valor = 0;
    fr(0,k){
        suma+=a[i];
        valor += a[i] * (i+1);
    }
    res.pb(mp(valor, 1));
    ll iter = k;
    while(iter < n){
        valor -= suma; 
        suma -= a[iter-k];
        suma += a[iter];
        valor += k * (a[iter]);
        res.pb(mp(valor, iter-k+2));
        iter++;
    }

    sort(res.begin(), res.end());
    fre(res){
        cout << e.second << " " << e.first << "\n";
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}