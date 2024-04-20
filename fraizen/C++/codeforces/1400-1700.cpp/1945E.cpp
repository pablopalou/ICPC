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
    int n,x; cin >> n >>x;
    int a[n];
    int posX = -1;
    fr(0,n){
        cin >> a[i];
        if (a[i] == x){
            posX = i+1;
        }
    }
    int l = 0; int r = n;
    while (r-l > 1){
        int mid = (l+r)/ 2;
        if (x >= a[mid]){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout <<"1\n"; cout << posX << ' ' << l+1 << '\n';

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