#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n"
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<int> res;
    for(int i = n/2; i>=1; i--){
        if (n % i == 0) {
            bool pongo = true;
            fre(res){
                if (e % i == 0){
                    pongo = false;
                }
            }
            if (pongo){
                res.pb(i);
            }
        }
    }
    cout << res.size() << '\n';
    fre(res){
        cout << 1 << " " << e << '\n';
    }
}

int main() {
    std:iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    //cin >> cases;
    while(cases--) {
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}