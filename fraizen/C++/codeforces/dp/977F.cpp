#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    set<int> s;
    map<int, vector<int>> m;
    fr(0,n){
        s.insert(a[i]);
        m[a[i]].pb(i);
    }
    vector<int> v;
    fre(s){
        v.pb(e);
    }
    //arranco en v[0] y voy subiendo de a uno
    int maxi = 0;
    vector<int> ans;
    vector<int> cur;
    int i = 0;
    while (i < v.size()) {
        cur.pb(m[v[i]][0]);
        int j = 1;
        while (true) {
            if (i + j >= v.size() || v[i + j] != v[i] + j) {
                break;
            }
            auto it = lower_bound(m[v[i + j]].begin(), m[v[i + j]].end(), cur.back());
            if (it == m[v[i + j]].end()) {
                break;
            }
            cur.pb(*it);
            j++;
        }
        if (cur.size() > maxi) {
            maxi = cur.size();
            ans = cur;
        }
        cur.clear();
        i += j;
    }
    // while(i < v.size()){
    //     cur.pb(m[v[i]][0]);
    //     while(true){
    //         auto it = lower_bound(m[v[i]+1].begin(), m[v[i]+1].end(), cur.back());
    //         if (m[v[i]+1].size() == 0 || it == m[v[i]+1].end()){
    //             cur.clear();
    //             i++;
    //             break;
    //         } else {
    //             cur.pb(*it);
    //             if (cur.size() > maxi){
    //                 maxi = cur.size();
    //                 ans = cur;
    //             }
    //             i++;
    //             if (i == v.size()){
    //                 break;
    //             }
    //         }
    //     }
    // }

    if (maxi == 0){
        cout << 1 << "\n" << 1 << '\n'; return;
    }
    cout << maxi << '\n';
    fre(ans){
        cout << e+1 << ' ';
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}