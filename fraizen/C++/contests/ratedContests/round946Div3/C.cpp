#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    map<tuple<ll,ll,ll>, ll> triplas;
    map<pair<ll,ll>, ll> parejas1;
    map<pair<ll,ll>, ll> parejas2;
    map<pair<ll,ll>, ll> parejas3;
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll x = a[0];
    ll y = a[1];
    ll z = a[2];
    ll res = 0;
    fr(3,n+1){
        res += parejas1[{x,y}];
        res += parejas2[{x,z}];
        res += parejas3[{y,z}];
        // cout << "res = " <<res << endl;
        triplas[{x,y,z}]++;
        parejas1[{x,y}]++;
        parejas2[{x,z}]++;
        parejas3[{y,z}]++;
        if (i == n){
            break;
        }
        x = y;
        y = z;
        z = a[i];
    }
    fre(triplas){
        res -= (e.second * (e.second - 1) * 3 / 2);
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