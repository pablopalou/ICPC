#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back


//hice todo pavada porque no lei bien. 


// Copiar obligatoriamente 0
void solve() {
    // int n,s,q; cin >> n >> s >> q;
    // vector<int> a[n]; 
    // int total = 0;
    // fr(0,n){
    //     int cant; cin >> cant;
    //     total += cant;
    //     rep(j,0,cant){
    //         int station; cin >> station;station--;
    //         a[i].pb(station);
    //     }
    // }
    // map<ll, ll> m;
    // int i = 0;
    // int res = 0;
    // int curElem = 0;
    // while(true){
    //     //primero descargo
    //     res += curElem;
    //     //me fijo cuales son iguales asi los descarto
    //     curElem -= m[i%n];
    //     //cargo los que ya tenia
    //     res += curElem;
    //     //cargo los nuevos
    //     if (i < n && a[i].size() > 0){
    //         rep(j,0,a[i].size()){
    //             m[a[i][j]]++;
    //         }
    //         curElem += a[i].size();
    //         res += a[i].size();
    //         total -= a[i].size();
    //         a[i].clear();
    //     }
    //     if (total == 0 && curElem == 0){
    //         break;
    //     }
    //     res += 2; //transiciono 
    //     i++;
    // }
    // cout << res << "\n";
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