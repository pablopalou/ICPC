#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n,m,k; cin >>n>>m>>k; int a[n]; int b[m];
    unordered_map<int, int> mapa;
    unordered_map<int,int> mapaB;
    fr(0,n) cin >> a[i];
    fr(0,m) cin >> b[i];
    fr(0,m) mapaB[b[i]]++;
    int cont = 0;
    fr(0,m) {
        // cout << a[i] << ' ' << mapa[a[i]] << endl;
        if (mapaB.find(a[i]) != mapaB.end() && mapa[a[i]] < mapaB[a[i]]){
            cont++;
            mapa[a[i]]++;
            // cout << "Agrgo " << a[i] << endl;
        } else if (mapaB.find(a[i]) != mapaB.end()){
            mapa[a[i]]++;
        }
    }
    int res = 0;
    if (cont >= k){
        res++;
    }
    // cout << "mapa " << endl;
    // fre(mapa){
    //     cout << e.first << ' ' << e.second << endl;
    // }
    // cout << endl;
    // cout << "mapaB " << endl;
    // fre(mapaB){
    //     cout << e.first << ' ' << e.second << endl;
    // }
    // cout << endl;
    // cout << "cont" << cont << endl;

    fr(m,n){
        // cout << "veo de agregar el " << a[i] << endl;
        if (mapaB.find(a[i-m]) != mapaB.end()){
            // cout << "saco el " << a[i-m] << endl;
            mapa[a[i-m]]--;
            if (mapa[a[i-m]] < mapaB[a[i-m]]){
                // cout << "Bajo " << endl;
                cont--;
            }
            // mapa[a[i-m]]--;
            // if (mapa[a[i-m]] < ){
            //     mapa.erase(a[i-m]);
            // }
        }
        if (mapaB.find(a[i]) != mapaB.end() && mapa[a[i]] < mapaB[a[i]]){
            // cout << "Agergo el " << a[i] << endl;
            mapa[a[i]]++;
            // cout << "subo " << endl;
            cont++;
        } else if (mapaB.find(a[i]) != mapaB.end()){
            mapa[a[i]]++;
        }
        // fre(mapa){
        //     cout << e.first << ' ' << e.second << endl;
        // }
        // cout << endl;
        if (cont >= k){
            res++;
        }
        // cout << "cont " << cont << endl;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}