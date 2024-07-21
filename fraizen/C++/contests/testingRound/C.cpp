#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll suma = 0;
    fr(0,n){
        suma += a[i];
    }
    //pruebo todas las positivizaciones posible y chau. (o sea supongo que solo 1 vas hay que hacer abs, sino ni idea)
    ll ans = suma;
    ll curSum = 0;
    ll c = 0;
    fr(0,n){
        curSum += a[i];
        c = curSum;
        if (c < 0){
            ans = max(ans, abs(curSum) + (suma - curSum));
        }
    }
    cout << ans << "\n"; return;

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