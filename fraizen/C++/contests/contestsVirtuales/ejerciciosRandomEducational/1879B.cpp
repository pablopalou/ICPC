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
    ll n; cin >> n;
    ll a[n]; ll b[n];
    fr(0,n) cin >> a[i];
    fr(0,n) cin >> b[i];
    ll miniA = a[0];
    ll miniB = b[0];
    ll sumaA = 0;
    ll sumaB = 0;
    fr(0,n){
        sumaA += a[i];
        sumaB += b[i];
        miniA = min(miniA, a[i]);
        miniB = min(miniB, b[i]);
    }
    cout << min(sumaB + miniA * n , sumaA + miniB * n) << "\n";
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