#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
ll a[200200];
ll n;
ll puedo(ll mid, ll k){
    fr(0,n){
        if (mid > a[i]){
            k -= (mid-a[i]);
            if (k < 0){
                return -1;
            }
        }
    }
    return k;
}

ll contar(ll mid, ll fraizen){
    if (fraizen > n){
        return 0;
    }
    ll sumar = 0;
    fr(0,n){
        if (a[i] <= mid && fraizen > 0){
            fraizen-=1;
            sumar++;
        } else if (a[i] > mid){
            sumar++;
        }
    }
    // ll maximo = max(0LL,min(fraizen-1, n-1));
    ll res = mid + (mid-1) * (n-1); //falta sumar si hay mas numeros...
    return res+sumar;
}

// Copiar obligatoriamente 0
void solve() {
    ll k;
    cin >> n >>k;
    fr(0,n){
        cin >> a[i];
    }
    ll l=0;
    ll r=2e18;
    ll res = 0;
    while(l<=r){
        ll mid = l + (r-l)/2;
        // cout << "pruebo mid " << mid << endl;
        ll fraizen = puedo(mid,k);
        if (fraizen != -1){
            // cout << "cuento " << endl;
            // cout << "fraizen es " << fraizen << endl;
            res = max(res, contar(mid, fraizen));
            l = mid + 1;
        } else {
            r = mid-1;
        }
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