#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    if (n == 1){
        cout << "1\n"; return;
    }
    sort(a, a+n);
    ll g = 0;
    fr(0,n-1){
        g = gcd(g, abs(a[i]-a[i+1]));
    }
    ll cur = a[n-1];
    ll res = 0;
    while(true){
        cur -= g;
        auto it = lower_bound(a, a+n, cur);
        if (*it != cur){
            res += (a[n-1] - cur)/g;
            break;
        }
    }
    fr(0,n-1){
        res += (a[n-1] - a[i])/g;
    }
    cout << res << '\n';
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