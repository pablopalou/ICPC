#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n, k; cin >> n >> k;
    char a[n][n];
    fr(0,n){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }
    // fr(0,n){
    //     rep(j,0,n){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    fr(0,n/k){
        rep(j,0,n/k){
            cout << a[i * k][j*k];
        }
        cout << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}