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

void solve() {
    int n,m; cin >> n >>m; int a[n]; int b[m]; fr(0,n) cin >> a[i]; fr(0,m) cin >> b[i];
    //primero me conviene hacer el array oficial 
    int mini = b[0];
    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // fr(0,n){
    //     cout << 
    // }
    vector<int> modulos;
    modulos.pb(mini);
    fr(1,m){
        if (b[i] >= mini){
            //no va
        } else {
            mini = min(mini, b[i]);
            modulos.pb(b[i]);
        }
    }
    // fr(0,modulos.size()){
    //     cout << modulos[i] << ' ';
    // }
    // cout << endl;
    // return;
    sort(modulos.begin(), modulos.end());
    fr(0,n){
        //calculo la respuesta pa cada uno
        int res = a[i];
        //tengo que ir repartiendo los alfajores. 
        while(true){
            auto it = upper_bound(modulos.begin(), modulos.end(), res);
            if (it == modulos.begin()){
                break;
            }
            it--; //aca seguro quedo en un rango valido
            res = res % *it;
        }
        cout << res << " ";
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