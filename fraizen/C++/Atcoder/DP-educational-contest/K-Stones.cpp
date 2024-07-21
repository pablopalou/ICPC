#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll n,k;
ll dp[100005];
ll a[102];

ll f(ll k){
    ll &r = dp[k];
    if (r != -1){
        return r;
    }
    if (k == 0){
        return 0;
    }
    r = 0;
    fr(0,n){
        if (k-a[i]>=0 && f(k-a[i]) == 0){
            r=1;
            return 1;
        }
    }
    return 0;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> k;
    fr(0,n){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    if (f(k) == 1){
        cout << "First" << "\n";
    } else {
        cout << "Second\n";
    };
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