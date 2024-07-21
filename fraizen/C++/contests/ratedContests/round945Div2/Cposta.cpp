#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    vector<pair<int,int>> par, impar;
    bool nImpar = false;
    int ans[n];
    fr(0,n){
        if (n == a[i] && (i%2==1)) nImpar = true;
    }
    if (nImpar){
        reverse(a, a+n);
    }
    
    fr(0,n){
        if (i % 2 == 0){
            par.pb({a[i], i});
        } else {
            impar.pb({a[i], i});
        }
    }
    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());
    int sumar = n;
    fr(0,par.size()){
        // cout << par[i].first << " " << par[i].second << endl;
        ans[par[i].second] = sumar;
        sumar--;
    }
    fr(0,impar.size()){
        // cout << impar[i].first << " " << impar[i].second << endl;
        ans[impar[i].second] = sumar;
        sumar--;
    }
    if (nImpar){
        reverse(ans, ans+n);
    }
    fr(0,n){
        cout << ans[i] << ' ';
    }
    cout << '\n';
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