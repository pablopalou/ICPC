#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define sz(c) ((int)c.size())
#define rsz resize


struct PrefixSum{
	vector<ll>ps;
	PrefixSum(vector<ll> & v){
		ps.resize(sz(v));
		ps[0] = v[0];
		for(int i = 1; i<sz(v); i++) ps[i] = ps[i-1] + v[i];
	}
	ll get(int l, int r){
		ll ret = ps[r];
		if(l > 0) ret-=ps[l-1];
		return ret;
	}
};

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n; vector<ll> a(n);
    fr(0,n) cin >> a[i];
    PrefixSum ps(a);
    vector<ll> nxt(n,n);
    for(ll i = n-2; i>=0; i--){
        if (a[i] == a[i+1]){
            nxt[i] = nxt[i+1];
        } else {
            nxt[i] = i+1;
        }
    }
    fr(0,n){
        if ((i > 0 && a[i-1] > a[i]) || (i < n-1 && a[i+1] > a[i])){
            cout << "1 "; continue;
        }
        ll ans1 = 2e18;
        if (i < n-1){ // me fijo si me puede eliminar alguien de la derecha.
            ll l = i+1; ll r = n-1;
            while(l<=r){
                ll m = l + (r-l)/2;
                bool sumaMayor = ps.get(i+1,m) > a[i];
                if (sumaMayor && nxt[i+1] <= m){
                    ans1 = m - i;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }

        ll ans2 = 2e18;
        if (i > 0){
            ll l = 0; ll r = i-1;
            while(l<=r){
                ll m = l +(r-l)/2;
                bool sumaMayor = ps.get(m,i-1) > a[i];
                if (sumaMayor && nxt[m] <= i-1){
                    ans2 = i - m;
                    l = m + 1;
                } else {
                    r = m-1;
                }
            }
        }
        if (min(ans1,ans2) == 2e18){
            cout << "-1 ";
        } else {
            cout << min(ans1,ans2) << ' ';
        }
    }
    cout << '\n';
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
