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
    int n,m;
    while(cin>>n>>m){
        vector<pair<int,int>> adj[n];
        fr(0,n){
            int cant; cin >> cant;
            int a[cant];
            int b[cant];
            rep(j,0,cant){
                cin >> a[j];
            }
            rep(j,0,cant){
                cin >> b[j];
            }
            rep(j,0,cant){
                adj[i].pb(mp(a[j], b[j]));
            }
        }
        // fr(0,n){
        //     rep(j,0,adj[i].size()){
        //         cout << "("<<adj[i][j].first << ", " << adj[i][j].second << ") ";
        //     }
        //     cout << endl;
        // }
        // return;
        vector<pair<int,int>> res[m+1];
        fr(0,n){
            rep(j,0,adj[i].size()){
                res[adj[i][j].first].pb(mp(i, adj[i][j].second));
            }
        }
        // return;
        // fr(0,m){
        //     rep(j,0,res[i].size()){
        //         cout << "("<<res[i][j].first << ", " << res[i][j].second << ") ";
        //     }
        //     cout << endl;
        // }
        // return;
        cout << m << " " << n << "\n";
        fr(1,m+1){
            if (res[i].size() == 0){
                cout << 0 << "\n\n";
            } else {
                cout << res[i].size() << ' ';
                rep(j,0,res[i].size()){
                    if (j < res[i].size()-1){
                        cout << res[i][j].first +1<< ' ';
                    } else {
                        cout << res[i][j].first +1;
                    }
                }
                cout << "\n";
                rep(j,0,res[i].size()){
                    if (j < res[i].size()-1){
                        cout << res[i][j].second << ' ';
                    } else {
                        cout << res[i][j].second;
                    }
                }
                cout << "\n";
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