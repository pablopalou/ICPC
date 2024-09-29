#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; n--; ll a[n+1]; fr(1,n+1) cin >> a[i];
    a[0] = 0;
    // fr(0,n+1){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int b[n+1][30];
    memset(b, 0, sizeof(b));
    fr(1,n+1){
        rep(j,0,30){
            if ((a[i] & (1 << j)) != 0){
                b[i][j] = 1;
                b[i-1][j] = 1;
            }
        }
    }
    // fr(0,n+1){
    //     rep(j,0,5){
    //         cout << b[i][j] <<  ' ';
    //     }
    //     cout << endl;
    // }
    ll res[n+1];
    memset(res, 0, sizeof(res));
    fr(0,n+1){
        rep(j,0,30){
            if (b[i][j]){
                res[i] += (1 << j);
            }
        }
    }
    fr(0,n){
        if ((res[i] & res[i+1]) != a[i+1]){
            cout << "-1\n"; return;
        }
    }
    fr(0,n+1){
        cout << res[i] << ' ';
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