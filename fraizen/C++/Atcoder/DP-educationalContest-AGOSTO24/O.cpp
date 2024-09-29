#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007
ll n;
ll a[22];
ll dp[22][(1<<21) +4];

ll f(ll i, ll mask){
    if (i == n){
        return dp[i][mask] = 1;
    } 
    ll &res = dp[i][mask];
    if (res!=-1) return res;
    //ahora tendria que ver con cual matcheo de ser posible
    res = 0;
    rep(j,0,n){
        //quiero matchear con j
        //el j-esimo bit tiene que estar libre
        if (((1 << j) & mask) == 0){
            //ademas, el j-esimo bit tiene que estar prendido en mi mascara
            if (((1<<j) & a[i]) != 0){
                // ahora si lo puedo juntar
                res = (res + f(i+1, mask | (1<<j))) % mod;
            }
        }
    }
    return dp[i][mask] = res;
}

void solve() {
    cin >> n;
    fr(0,n){
        ll cur = 0;
        rep(j,0,n){
            cur*=2;
            ll match; cin >> match;
            cur+= match;
        }
        a[i] = cur;
    }

    memset(dp, -1, sizeof(dp));
    cout << f(0, 0); // estoy arrancando con el hombre 0, y tengo todo libre
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