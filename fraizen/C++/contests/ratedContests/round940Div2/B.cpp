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
    int n,k; cin >> n>>k;
    if (n == 1){
        cout << k << "\n"; return;
    }
    fr(0,30){
        if ((1 << i) - 1 == k){
            cout << k << ' ';
            fr(0,n-1){
                cout << 0 << ' '; 
            }
            cout << "\n";
            return;
        }
    }
    ll pot = 1;
    while(pot * 2 <= k){
        pot *= 2;
    }
    cout << pot-1 << ' ';
    cout << k-(pot-1) << ' ';
    fr(0,n-2){
        cout << 0 << ' ';
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