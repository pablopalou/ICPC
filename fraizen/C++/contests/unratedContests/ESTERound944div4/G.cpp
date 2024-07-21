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
    int n; cin >> n;
    int a[n];
    fr(0,n) cin >> a[i];
    map<ll,vector<int>> m;
    fr(0,n){
        m[a[i]/4].pb(i);
    }
    int res[n];
    fre(m){
        vector<int> values = e.second;
        vector<int> v;
        fr(0,values.size()){
            v.pb(a[values[i]]);
        }
        sort(v.begin(), v.end());
        // for(auto it = s.begin(); it!=s.end();it++){
        //     cout << *it << ' ';
        // }
        // cout << endl;
        fr(0,values.size()){
            res[values[i]] = v[i];
        }
    }
    fr(0,n){
        cout << res[i] << ' ';
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