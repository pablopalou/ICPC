#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll res = 1;
    bool esta[1000002];
    memset(esta, false, sizeof(esta));
    fr(0,n){
        if (esta[a[i]]){
            res = max(res, a[i]);
        }
        esta[a[i]] = true;
    }
    for(ll i = 2; i <= 1000000; i++){
        ll cur = 0;
        for(ll j = i; j<= 1000000; j+= i){
            if (esta[j]){
                cur++;
                if (cur == 2){
                    res = max(res, i);
                    break;
                }
            }
        }
    }
    cout << res << '\n';
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