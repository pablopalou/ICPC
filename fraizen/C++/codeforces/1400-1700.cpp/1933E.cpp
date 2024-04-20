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
    int n; cin >> n; int a[n+1]; 
    fr(1,n+1) cin >> a[i];
    int q; cin >> q;
    a[0] = 0;
    fr(1,n+1){
        a[i] += a[i-1];
    }
    fr(0,q){
        int l, u; cin >> l >> u;
        int buscar = u + a[l-1];
        int pos = lower_bound(a, a+n+1, buscar) - a;
        if (pos == 0 || pos == 1){
            cout << "1 "; continue;
        }
        if (pos == l){
            cout << l << " "; continue;
        }
        if (pos > n){
            cout << pos-1 << ' '; continue;
        }
        if (a[pos] == buscar){
            cout << pos << ' ';
        } else if (abs(a[pos] -buscar) <= abs(a[pos-1]-buscar)){
            cout << pos << ' ';
        } else {
            cout << pos-1 << ' ';
        }
    }
    cout << "\n";
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