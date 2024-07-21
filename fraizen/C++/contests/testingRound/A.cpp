#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n ; cin >> n;
    if (n == 3){
        cout << 100 << '\n';
        cout << 101 << '\n';
        cout << 110 << '\n';
        return;
    }
    fr(0,n-1){
        rep(j,0,n){
            if (j == 0){
                cout << 1;
            } else if (j == n-1-i){
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
    }
    cout << 111;
    fr(0,n-3){
        cout << 0;
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