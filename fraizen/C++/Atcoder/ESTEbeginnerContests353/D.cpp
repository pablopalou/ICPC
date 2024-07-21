#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mod 998244353

ll power(ll x, ll y)
{
    ll res = 1; 	// Initialize result
    x = x % 998244353; // Update x if it is more than or
                // equal to p
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % 998244353;
        y = y>>1; // y = y/2
        x = (x*x) % 998244353;
    }
    return res;
}

ll digits(ll num){
    ll res = 0;
    while(num){
        num/=10;
        res++;
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll res = 0;
    map<ll,ll> m;
    for (ll i = n-1; i >= 0; i--){
        //tiene que aportar i veces el minimo valor
        res = (res % mod + ( a[i] % mod * i % mod )% mod) % mod; 
        //tinee que aportar n-1-i veces el valor pro digamos
        fre(m){
            res = (res % mod + ((a[i] % mod * power(10,e.first) % mod) % mod * e.second % mod) % mod) % mod; 
        }
        m[digits(a[i])]++;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}