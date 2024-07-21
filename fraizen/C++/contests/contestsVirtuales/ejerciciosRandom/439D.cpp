#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

#define MAXN 100100
ll a[MAXN], b[MAXN];
ll n,m;

ll check(ll mid){
    ll res = 0;
    //el array a tiene que tener minimo mid en todo
    fr(0,n){
        if (a[i] < mid){
            res += mid-a[i];
        }
    }
    //el array b tiene que tener como mucho mid en todo
    fr(0,m){
        if (b[i] > mid){
            res += b[i] - mid;
        }
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >>n >>m;
    fr(0,n){
        cin >> a[i];
    }
    fr(0,m){
        cin >> b[i];
    }
    ll l = 0;
    ll r = 1e9;
    while(r - l >= 3){
        ll mid1 = l + (r-l)/3;
        ll mid2 = r - (r-l)/3;
        if (check(mid1) >= check(mid2)){
            l = mid1;
        } else {
            r = mid2;
        }
    }
    ll res = check(l);
    fr(l, l+4){
        res = min(res, check(i));
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}