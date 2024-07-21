#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n; cin >> n;
    int a[n];
    fr(0,n) cin >> a[i];
    sort(a, a+n);
    int mex = 1;
    int maxi = a[n-1];
    fr(0,n){
        if (a[i] == mex){
            mex++;
        }
    }
    if (mex > maxi){
        if (n%2 == 0){
            cout << "Alicius\n";
        } else {
            cout << "Bobius\n";
        }
    } else {
        //maxi es mas grande, entonces lo que importa es la paridad del mex ? 
        if (mex % 2 == 1){
            cout << "Alicius\n";
        } else {
            cout << "Bobius\n";
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