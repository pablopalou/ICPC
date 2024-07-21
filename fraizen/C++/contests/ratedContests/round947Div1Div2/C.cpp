#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
map<ll, vector<ll>> m;
ll maxi = 0;

bool puedo(int mid){
    if (mid <= maxi) return true;
    // cout << "Mid " << mid << endl;
    vector<ll> v = m[mid];
    // fr(0,v.size()){
    //     cout << v[i] << ' ';
    // }
    // cout << endl;
    fr(0,v.size()-1){
        if (v[i+1] - v[i] == 1){
            return true;
        }
        if (i+2 < v.size()){
            if (v[i+2] - v[i] <= 4){
                return true;
            }
        }
    }
    return false;
}

void solve() {
    ll n; cin >> n; ll a[n]; 
    fr(0,n) {
        cin >> a[i];
        m[a[i]].pb(i);
    }
    ll b[n];
    fr(0,n){
        b[i] = a[i];
    }
    maxi = 0;
    fr(0,n-1){
        maxi = max(maxi, min(a[i], a[i+1]));
    }
    fr(1,n-1){
        vector<ll> v;
        v.pb(a[i-1]);
        v.pb(a[i]);
        v.pb(a[i+1]);
        sort(v.begin(), v.end());
        maxi = max(maxi, v[1]);
    }
    // sort(b, b+n);
    // ll l = 0;
    // ll r = n-1; 
    // while(l <= r){
    //     ll mid = l + (r-l) / 2;
    //     if (puedo(b[mid])){
    //         maxi = max(b[mid], maxi);
    //         l = mid+1;
    //     } else {
    //         r = mid-1;
    //     }
    // }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}