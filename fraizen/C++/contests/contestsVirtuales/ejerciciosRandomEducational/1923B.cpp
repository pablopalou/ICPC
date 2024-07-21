#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mp make_pair

// Copiar obligatoriamente 0
void solve() {
    int n,k; cin >> n>>k;
    int a[n];
    int x[n];
    vector<pair<int, int>> v;
    fr(0,n) cin >> a[i];
    fr(0,n) cin >> x[i];
    fr(0,n){
        v.pb(mp(abs(x[i]), a[i]));
    }
    sort(v.begin(), v.end());
    //ordeno por valor absoluto a ver si anda
    // fre(v){
    //     cout << e.first << ' ' <<e.second <<endl;
    // }
    ll suma = 0;
    fre(v){
        suma += e.second;
        // cout << "suma " << suma << endl;
        // cout << e.first << endl;
        // cout << ceil(suma/e.first) << endl;
        if (k < ceil(suma/double(e.first))){
            cout << "NO\n";return;
        }
    }
    cout << "yes\n";
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