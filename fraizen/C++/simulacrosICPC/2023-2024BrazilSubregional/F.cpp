#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

void solve() {
    ll suma, n1, n2; cin >> suma >> n1 >> n2;
    ll a[n1]; 
    ll b[n2];
    ll res = 0;
    int l=0; int r = 0;
    fr(0,n1){
        cin >> a[i];
    }
    // fr(0,n1){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    fr(0,n2){
        cin >> b[i];
    }
    // fr(0,n2){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // cout << a[0] << endl;
    while(l < n1 || r < n2){
        // cout << "l = " << l << endl;
        // cout << "r = " << r << endl;
        // cout << "suma = " << suma << endl;
        if (l < n1){
            if (suma >= a[l]){
                suma -= a[l];
                l++;
            } else if (r < n2) {
                suma+=b[r];
                r++;
            } else {
                break;
            }
        } else { //r < n2 pero l ya fue
            suma+=b[r];
            r++;
        }
        res++;
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