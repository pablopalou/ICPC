#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
ll a,b,c;
ll probar(int primero, int segundo, int tercero){
    return ((a/primero) * (b/segundo) * (c/tercero));
}

void solve() {
    cin >> a >> b >> c;
    ll uno,dos,tres; cin >> uno >> dos >> tres;
    ll maxi = 0;
    maxi = max(maxi, probar(uno, dos, tres));
    maxi = max(maxi, probar(uno, tres, dos));
    maxi = max(maxi, probar(dos, uno, tres));
    maxi = max(maxi, probar(dos, tres, uno));
    maxi = max(maxi, probar(tres, uno, dos));
    maxi = max(maxi, probar(tres, dos, uno));

    cout << maxi << '\n';
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