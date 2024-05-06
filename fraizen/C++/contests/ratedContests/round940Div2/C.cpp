#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mod 1000000007

// Copiar obligatoriamente 0
void solve() {
    ll n,k; cin >> n >> k;
    fr(0,k){
        ll a,b; cin >> a >> b;
        if (a!=b){
            n-=2;
        } else {
            n--;
        }
    }
    ll dp[n+10];
    dp[0]=1;
    dp[1] = 1;
    fr(2,n+1){
        dp[i] = (dp[i-1] + 2*(i-1)*dp[i-2] % mod) % mod;
    }
    cout << dp[n] << "\n";
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