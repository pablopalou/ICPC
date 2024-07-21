#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int x,y; cin >> y >>x;
    int ans = 0;
    ans = (x+1)/2;
    int libres = 0;
    libres = ans * 7;
// cout << libres << '\n';
// cout << x << endl;
    if (x & 1){
        libres += 4;
    }
    // cout << "libres  " << libres << endl;
    if (y <= libres){
        cout << ans << '\n';
    } else {
        ans += ceil((y-libres) / 15.0);
        cout << ans << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}