#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    if (n == 2){
        cout << "Yes\n"; return;
    }
    //pruebo en cada pos
    ll ar[2*n];
    fr(0,n){
        ar[i] =a[i];
    }
    fr(0,n){
        ar[i+n] = a[i];
    }
    // fr(0,2*n){
    //     cout << ar[i] << ' ';
    // }
    bool esteNo = false;
    fr(0,n){
        esteNo = false;
        rep(j,i,i+n-1){
            if (ar[j] > ar[j+1]){
                esteNo = true;
            }
        }
        if (! esteNo){
            cout << "Yes\n"; return;
        }
    }
    cout << "No\n"; return;

    // ll pos = -1;
    // ll mini = 1e18;
    // fr(1,n){
    //     mini = min({a[i-1], mini});
    //     if (a[i] < a[i-1]){
    //         pos = i;
    //         break;
    //     }
    // }
    // // cout << "pos " << pos << endl;
    // // cout << "mini " << mini << endl;
    // if (pos == -1 || pos == n-1){
    //     cout << "Yes\n"; return;
    // }
    // fr(pos, n){
    //     if (i + 1 < n){
    //         if (a[i] > a[i+1]){
    //             cout << "No\n"; return;
    //         }
    //     }
    //     if (a[i] > mini){
    //         cout << "No\n"; return;
    //     }
    // }
    // cout << "Yes\n"; return;
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