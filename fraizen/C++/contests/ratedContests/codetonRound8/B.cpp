#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

int v[200005];
int used[200005];
// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    vector<int> res;
    memset(v, 0, sizeof(v));
    memset(used, 0, sizeof(used));
    int mex = 0;
    if (a[0] == 1){
        res.pb(0);
        v[0] = 1;
        mex = 1;
    } else {
        res.pb(-a[0]);
        v[-a[0]] = 1;
    }
    fr(1,n){
        if (a[i] > 0){ //pongo el mex
            v[mex] = 1;
            res.pb(mex);
        } else { //pongo a huevo
            res.pb(mex-a[i]);
            v[mex-a[i]] = 1;
        }
        //update mex
        int j = mex;
        while(v[j]){
            j++;
        }
        mex = j;
    }
    
    // fr(1,n){
    //     //supongo que pongo pi = mex y me fijo si quedaria bien
    //     // cout << "i = " <<  i << " con mex = " << mex << endl;
    //     v[mex] = 1;
    //     int j = mex+1;
    //     while(v[j] == 1){
    //         j++;
    //     }
    //     int curMex = j;
    //     if (a[i] == curMex - mex){
    //         res.pb(mex);
    //         mex = curMex;
    //         continue;
    //     } else { //ahora pongo el que queda en realidad sin cambiar el mex...
    //         v[mex] = 0;
    //         res.pb(mex-a[i]);
    //         v[mex-a[i]] = 1;
    //     }
    // }
    fr(0,n){
        cout << res[i] << ' ';
    }
    cout << "\n";
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