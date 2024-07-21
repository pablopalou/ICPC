#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[4200000];

void fillFraizen(ll num, ll padre, ll pos){
    if (num >= 4200000 or dp[num] != -1){
        return;
    }
    if (pos == -1){
        dp[num] = padre;
        return; 
    }
    if (1 << pos & num){ //si tengo 1, llamo con uno nomas
        fillFraizen(num, padre, pos-1);
    } else { //el bit esta en 0
        fillFraizen(num, padre, pos-1);
        fillFraizen(num | (1<<pos), padre, pos-1); //pongo 1
    }
}

void solve() {
    ll n; cin >> n ; ll a[n]; fr(0,n) cin >> a[i];
    memset(dp,-1, sizeof(dp));
    fr(0,n){
        fillFraizen(a[i],a[i], 22);
    }
    fr(0,n){
        cout << dp[a[i] ^ ((1<<22) - 1)] << ' ';
    }
    cout << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("G.in", "r", stdin);
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