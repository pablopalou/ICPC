#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100005
#define mod 1000000007
ll dp[MAXN];

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    fr(1,n+1){
        vector<ll> divs;
        //tengo el a[i-1], entonces necesito encontrar los divisores y actualizar solo esos.
        for(ll j = 1; j*j <= a[i-1]; j++){
            if (a[i-1] % j == 0){
                if (j < MAXN){
                    divs.pb(j);
                    ll cur = a[i-1]/j;
                    if (j != (cur)){
                        if (cur < MAXN){
                            divs.pb(cur);
                        }
                    }
                }
            }
        }
        sort(divs.begin(), divs.end(), greater<ll>());
        fre(divs){
            dp[e]+=dp[e-1];
            dp[e]%=mod;
        }
    }
    ll res = 0;
    fr(1,n+1){
        res = (res + ( dp[i] %mod)) % mod;
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