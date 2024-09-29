#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll f(ll n, ll k){
    if (n == 1) return 1;
    if (k*2 <= n+1){
        if (k*2 > n) return (k*2)%n;
        else  return 2*k;
    }
    int ans = f(n/2, k-(n+1)/2);
    if (n&1) return 2*ans+1;
    return 2*ans-1;
}

void solve() {
    int n,k; cin >> n>> k;
    cout << f(n,k) << "\n";
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