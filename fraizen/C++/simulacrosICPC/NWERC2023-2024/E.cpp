#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,m; cin >> n >> m;
    ll cant[n];
    fr(0,n){
        cant[i] = 1;
    }
    fr(0,m){
        char c1; ll l,r; cin >> c1 >> l >> r; l--; r--;
        if (c1 == '!'){
            cant[l] += cant[r];
        } else {
            if (cant[l] < cant[r]){
                cout << "<\n";
            } else if (cant[l] == cant[r]){
                cout << "=\n";
            } else {
                cout << ">\n";
            }
        }
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}