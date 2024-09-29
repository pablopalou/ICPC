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
#define mp make_pair

void solve() {
    int k; cin >> k;
    int n = 100;
    int res = 0; int aux = 1;
    while(aux < k){
        aux*=2;
        res++;
    }
    cout << res << "\n";
    //ahora tengo que armar cada color
    //igualmente ya se que todos los pongo en la 
    vector<pair<int,int>> ans[res];
    vector<pair<int,int>> todos;
    fr(0,100){
        rep(j,0,100){
            if (i==0 or j%2 == 0){
                todos.pb(mp(i,j));
            }
        }
    }
    int curI = 1;
    int curJ = 1;
    for(int mask = 1; mask <= k-2; mask++){
        // cout << "mask = " << mask << endl;
        rep(j,0,res){
            if (mask & (1<<j)){
                ans[j].pb(mp(curI, curJ));
            }
        }
        curI+=1;
        if (curI == 98){
            curI = 1;
            curJ += 2;
        }
    }
    // fr(0,res){
    //     rep(j,0,ans[i].size()){
    //         cout << ans[i][j].first << " " << ans[i][j].second << " ";
    //     }
    //     cout << endl;
    // }
    // return;
    fr(0,res){ //imprimir cada uno
        cout << todos.size() + ans[i].size() << " ";
        rep(j,0,todos.size()){
            cout << todos[j].first+1 << " " << todos[j].second+1 << " ";
        }
        rep(j,0,ans[i].size()){
            cout << ans[i][j].first+1 << " " << ans[i][j].second+1 << " ";
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}