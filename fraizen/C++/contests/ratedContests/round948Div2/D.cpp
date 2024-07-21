#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,m; cin >> n >> m;
    string a[n];
    fr(0,n){
        // rep(j,0,m){
            cin >> a[i];
        // }
    }
    int cant[m];
    memset(cant, 0, sizeof(cant));
    fr(0,m){
        rep(j,0,n){
            if (a[j][i] == '1'){
                cant[i]++;
            }
        }
    }
    int res = 0;
    int cur = 0;
    fr(0,m){
        if (cant[i] == 1){
            cur++;
        }
    }
    res = cur;
    vector<int> ans(n, 0);
    //ahora pruebo xoreando de a una
    fr(0,n){
        int cur = 0;
        //apago la i
        rep(j,0,m){
            if (a[i][j] == '0' && cant[j] == 0){
                cur++;
            } else if (a[i][j] == '1' && cant[j] == 2){
                cur++;
            }
        }
        if (cur > res){
            res = cur;
            fr(0,ans.size()){
                ans[i] = 0;
            }
            // memset(ans.begin(), ans.end(), 0);
            ans[i] = 1;
        }
    }

    cout << res << '\n';
    fr(0,n){
        cout << ans[i];
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