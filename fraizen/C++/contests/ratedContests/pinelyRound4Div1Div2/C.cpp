#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; 
    // cout << "N = " << n << endl;
    ll a[n]; fr(0,n) cin >> a[i];
    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    ll res[41];
    ll cant = -1;
    fr(0,41){
        ll maxi = *max_element(a, a+n);
        ll mini = *min_element(a, a+n);
        // fr(0,n){
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        // cout << "Maxi = " << maxi << endl;
        // cout << "Mini = " << mini << endl;
        if (maxi == 0){
            cant = i;
            break;
        }
        if (mini == maxi){
            res[i] = mini;
            cant = i+1;
            break;
        }
        if (i == 40){
            break;
        }
        ll x = ((maxi - mini)/2 + mini);
        // cout << "x = " << x << endl;
        res[i] = x;
        rep(j,0,n){
            a[j] = abs(a[j] - x);
        }
    }
    if (cant == -1){
        cout << "-1\n"; return;
    }
    cout << cant << '\n';
    fr(0,cant){
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