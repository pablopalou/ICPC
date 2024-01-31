#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mp make_pair

// Copiar obligatoriamente 0
void solve() {
    ll n, k; cin >> n >> k;
    --k;
    int a[n];
    fr(0,n){
        cin >> a[i];
    }
    if (k == 0 || k == n-1){
        cout << "YES" << "\n";
        return;
    }
    // armar grupos buenos (cosos positivos mas chicos posibles o que me permitan salir)
    vector<pair<ll,ll>> izq,der;
    ll cur = 0;
    ll minimo = 0;
    fr(k+1, n){
        cur = cur + a[i];
        minimo = min(minimo, cur);
        if (cur >= 0){
            der.push_back(mp(cur, minimo));
            cur = 0;
            minimo = 0;
        }
    }
    der.push_back(mp(cur, minimo));
    // fre(der){
    //     cout << e.first << ' ' << e.second << endl;
    // }
    cur = 0;
    minimo = 0;
    for(int i = k-1; i>=0; i--){
        cur = cur + a[i];
        minimo = min(minimo, cur);
        if (cur >= 0){
            izq.push_back(mp(cur, minimo));
            cur = 0;
            minimo = 0;
        }
    }
    izq.push_back(mp(cur, minimo));

    cur = a[k]; //incializo puntuacion
    //tengo que ver si puedo ir yendo a la derecha y a la izquierda.
    auto l = izq.begin();
    auto r = der.begin();
    while (l != izq.end() && r != der.end()){
        if (cur + l->second >= 0){
            cur += l->first;
            l++;
        } else if (cur + r->second >= 0){
            cur += r->first;
            r++;
        } else {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";

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