#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n,k; cin >> n >> k; int a[n]; fr(0,n) cin >> a[i];
    int ans = -1;
    sort(a, a+n);
    int maxi = a[n-1];
    rep(j,0,k+2) {
        bool prendido = true;
        fr(0,n) {
            if (((maxi + j - a[i]) % (2 * k)) >= k) {
                prendido = false;
                break;
            }
        }
        if (prendido) {
            ans = maxi + j;
            break;
        }
    }
    cout << ans << '\n';
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