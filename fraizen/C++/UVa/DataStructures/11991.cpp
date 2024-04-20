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
    int n,m; 
    while(cin >> n>>m){
        int a[n];
        map<int, vector<int> > mapa;
        fr(0,n){
            cin >> a[i];
            mapa[a[i]].pb(i+1);
        }
        fr(0,m){
            int k,v; cin >> k >> v;
            if (k-1 < mapa[v].size()){
                cout << mapa[v][k-1] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
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