#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll gauss(ll n){
    return n*(n-1)/2;
}

void solve() {
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    ll p[n]; p[0] = 0;
    ll res = n;
    fr(1,n){
        p[i] = p[i-1];
        if (a[i] > a[i-1]){
            p[i]++;
        } else {
            p[i]--;
        }
    }
    map<ll,ll> m;
    fr(0,n){
        m[p[i]]++;
    }
    fre(m){
        res += gauss(e.second);
    }
    cout << res << '\n';
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}