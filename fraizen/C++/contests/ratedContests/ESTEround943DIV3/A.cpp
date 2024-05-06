#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } 

// Copiar obligatoriamente 0
void solve() {
    int maxi = -1;
    int x; cin >> x;
    int res = -1;
    fr(1,x){
        // cout << i << endl;
        if (gcd(x,i) + i > maxi){
            maxi = gcd(x,i) + i;
            res = i;
            // cout << "res = " << res << endl;
        }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}