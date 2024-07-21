#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n,q; cin >> n >> q;
    ll a[n+1]; fr(1,n+1) cin >>a[i];
    ll p[n+1];
    ll unos[n+1];
    p[0] = 0;
    fr(1,n+1){
        p[i] = p[i-1] + a[i];
    }
    unos[0] = 0;
    fr(1,n+1){
        unos[i] = unos[i-1];
        if (a[i] == 1){
            unos[i]++;
        }
    }
    fr(0,q){
        ll l,r; cin >> l >> r;
        if (l == r){
            cout << "NO\n"; continue;
        }
        ll suma = p[r] - p[l-1];
        if ((unos[r] - unos[l-1] )* 2 + (r-l+1-(unos[r]-unos[l-1])) > suma){
            cout << "NO\n"; continue;
        }
        cout << "YES\n";
    }
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