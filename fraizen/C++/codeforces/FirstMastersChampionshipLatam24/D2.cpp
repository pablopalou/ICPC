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
    int h; int m; cin >> h>>m;
    int mins = 60*h + m;
    int n;cin >> n;
    int a[n], b[n];
    fr(0,n){
        cin >> a[i] >>b[i];
    }
    int i = 0;
    ll res = 0;
    while(mins > 0){
        // cout << i << endl;
        if (i < n){
            int cobrar = min(a[i], mins);
            // cout << cobrar << endl;
            mins -= cobrar;
            res += cobrar * b[i];
        } else {
            cout << res << "\n";
            return;
        }
        i++;
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