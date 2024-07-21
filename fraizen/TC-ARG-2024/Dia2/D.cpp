#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define inf 1e9

void solve() {
    int n,d; cin >> n >>d;
    int a[n]; fr(0,n) cin >> a[i];

    double dp[n+1][10];
    bool mem[n+1][10];
    //dp[i][d] => log de la multiplicacion de los que agarre (me quedan i por poner)
    //mem[i][d] => cuando estaba en i,d, agarre o no agarre
    fr(0,n+1){
        rep(j,0,10){
            dp[i][j] = -inf;
        }
    }
    dp[0][d] = 0;
    fr(1,n+1){
        rep(j,0,10){
            //agarro
            dp[i][j] = max(dp[i][j], dp[i-1][(j*a[i-1]) % 10] + log(a[i-1]));
            mem[i][j] = true;
            //no lo agarro
            double res2 = dp[i-1][j];
            if (res2 > dp[i][j]){
                mem[i][j] = false;
                dp[i][j] = res2;
            }
        }
    }
    int d2 = 1;
    vector<int> res;
    for(int i = n; i>=1; i--){
        if (mem[i][d2]){
            res.pb(a[i-1]);
            d2 = (a[i-1] * d2) % 10;
        }
    }
    if (dp[n][1] < -1 || res.size()==0){
        cout << "-1";return;
    }
    cout << res.size() << "\n";
    fre(res){
        cout << e << ' ';
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}