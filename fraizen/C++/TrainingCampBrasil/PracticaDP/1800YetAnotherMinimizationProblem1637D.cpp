#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

//esta mal la solucion que queria hacer al parecer


ll sumaCuadrado(ll nro, vector<ll> arr){
    ll ans = 0;
    // cout << "size" << arr.size() << endl;
    // fr(0,arr.size()){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;
    fr(0,arr.size()){
        // cout << i << endl;
        // cout << nro << endl;
        // return 0;
        ans += (nro + arr[i]) * (nro + arr[i]);
    }
    return ans;
}
// Copiar obligatoriamente 0
void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    fr(0,n){
        cin >> a[i];
    }
    fr(0,n){
        cin >> b[i];
    }
    ll dp[n];
    dp[0] = 0;
    vector<ll> newA, newB;
    newA.pb(a[0]);
    newB.pb(b[0]);
    fr(1,n){
        ll fraizen = sumaCuadrado(a[i], newA) + sumaCuadrado(b[i], newB);
        ll fraizen2 = sumaCuadrado(b[i], newA) + sumaCuadrado(a[i], newB);
        if (fraizen < fraizen2){
            dp[i] = dp[i-1] + fraizen;
            newA.pb(a[i]);
            newB.pb(b[i]);
        } else {
            dp[i] = dp[i-1] + fraizen2;
            newA.pb(b[i]);
            newB.pb(a[i]);
        }
    }
    cout << newA.size() << endl;
    fr(0, newA.size()){
        cout << newA[i] << ' ';
    }
    cout(' ');
    fr(0, newB.size()){
        cout << newB[i] << ' ';
    }
    cout << dp[n-1] << "\n";
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