#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mod 998244353
int dp[2][202][2]; //solo guardo now y sig

struct PrefixSum{
    vector<int> ps;
    void reset(vector<int> & v){
        ps.resize(v.size());
        ps[0] = v[0];
        fr(1,201){
            ps[i] = ((v[i] % mod) + (ps[i-1] % mod))% mod;
        }
    }
    int get(int l, int r){
        if (r < l) return 0;
        int res = ps[r];
        if (l > 0){
            res -= ps[l-1];
        }
        if (res < 0){
            res += mod;
        }
        return res;
    }
};

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;int a[n];
    fr(0,n){cin >> a[i];}
    memset(dp, 0, sizeof(dp));
    if (a[0] == -1){
        fr(1,201){
            dp[0][i][0] = 1;
        }
    } else {
        dp[0][a[0]][0] = 1;
    }
    //voy bien
    PrefixSum ps0;
    PrefixSum ps1;
    vector<int> v0(201,0);
    auto v1 = v0;
    fr(1,201){
        v0[i] = dp[0][i][0];
        v1[i] = dp[0][i][1];
    }
    ps0.reset(v0);
    ps1.reset(v1);
    // cout << ps0.get(0,200) << endl;
    // cout << ps1.get(0,200) << endl;
    fr(1,n){
        // cout << a[i] << endl;
        if (a[i] == -1){
            rep(j,1,201){
                rep(k,0,2){
                    ll ans = 0;
                    if (k == 1){
                        ans = (ans + (ps0.get(1, j-1) % mod) + ( ps1.get(1, j-1) % mod));
                    } else {
                        ans = (ans % mod + (ps0.get(j,j) % mod) + (ps1.get(j, 200) % mod)) % mod;
                    }
                    cout << ans << endl;
                    dp[1][j][k] = ans;
                }
            }
        } else {
            rep(k,0,2){
                ll ans = 0;
                int j = a[i];
                if (k == 1){
                    ans = (ans + (ps0.get(1, j-1) % mod) + ( ps1.get(1, j-1) % mod));
                } else {
                    ans = (ans % mod + (ps0.get(j,j) % mod) + (ps1.get(j, 200) % mod)) % mod;
                }
                cout << ans << endl;
                dp[1][j][k] = ans;
            }
        }
        swap(dp[0], dp[1]);
        fr(1,201){
            v0[i] = dp[0][i][0];
            v1[i] = dp[0][i][1];
        }
        ps0.reset(v0);
        ps1.reset(v1);
    }
    ll res = 0;
    if (a[n-1] == -1){
        fr(1,201){
            res = (res % mod + dp[0][i][0] % mod) % mod;
        }
    } else {
        res = dp[0][a[n-1]][0] % mod;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}