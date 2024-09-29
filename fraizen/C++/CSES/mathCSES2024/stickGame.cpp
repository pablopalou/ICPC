#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n, k; cin >> n >> k; int a[k]; fr(0,k) cin >> a[i];
    bool dp[n+1];
    dp[0] = false;
    fr(1,n+1){
        dp[i] = false;
        rep(j,0,k){
            if (i - a[j] >= 0 && !dp[i-a[j]]){
                dp[i] = true;
                break;
            }
        }
    }
    fr(1,n+1){
        if (dp[i]){
            cout << "W";
        } else {
            cout << "L";
        }
    }
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