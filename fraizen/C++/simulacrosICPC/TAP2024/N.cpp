#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n"

void solve() {
    ll n; cin >> n;
    vector<ll> ar(n);
    fr(0,n) cin >> ar[i];
    sort(ar.begin(), ar.end());
    ll res = 0;
    if (n == 1){
        cout << 0 << '\n';return;
    }
    fr(0,n){
        rep(j,0,n){
            ll a = ar[i];
            ll b = ar[j];
            ll c = ar[0];
            res = max(res, a*a + b*b + c*c - (a*b + b*c + c*a));
            c = ar[n-1];
            res = max(res, a*a + b*b + c*c - (a*b + b*c + c*a));
        }
    }
    cout << res << '\n';
}

int main() {
    std:iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    //cin >> cases;
    while(cases--) {
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}