#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n,m,k,d; cin >> n>>m>>k>>d;
    ll cost[n];
    memset(cost, 0, sizeof(cost));
    ll dp[m];
    //falta leer toda la matriz
    ll a[n][m];
    fr(0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }   
    }
    fr(0,n){
        memset(dp, -1, sizeof(dp));
        dp[m-1] = 0;
        map<ll ,ll> mapa;
        for(ll j = m-2; j>=0; j--){
            if (j >= m-1-d-1){
                if (j==0){
                    dp[0] = 0;
                } else {
                    dp[j] = a[i][j] + 1;
                }
                mapa[dp[j]]++;
                continue;
            }
            if (j == 0){
                dp[j] = mapa.begin()->first;
            } else {
                dp[j] = a[i][j] + 1 + mapa.begin()->first;
            }
            if (mapa[dp[j+d+1]] > 1){
                mapa[dp[j+d+1]]--;
            } else if (mapa[dp[j+d+1]] == 1){
                mapa.erase(dp[j+d+1]);
            }
            mapa[dp[j]]++;
        }
        cost[i] = dp[0] + 2; //tengo que poner un uno al principio y otro al final
    }
    ll res = 0;
    fr(0,k){
        res+=cost[i];
    }
    ll cur = res;
    fr(k, n){
        cur = cur - cost[i-k] + cost[i];
        res= min(res, cur);
    }
    cout << res << "\n";
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