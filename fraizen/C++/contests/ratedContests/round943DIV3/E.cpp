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
    if (n==2){
        cout << "1 1\n";
        cout << "1 2\n";
    } else if (n == 3){
        cout << "2 1\n";
        cout << "2 3\n";
        cout << "3 1\n";
    } else if (n == 4){
        cout << "1 1\n";
        cout << "1 3\n";
        cout << "4 3\n";
        cout << "4 4\n";
    } else {
        cout << "1 1\n";
        cout << n << " " << n << "\n";
        cout << n-1 << " " << n << '\n';
        fr(3,n){
            cout << 1 << " " << i << "\n";
        } 
    }
    cout << "\n";
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