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
    ll a,b,c; cin >> a>>b>>c;
    if(c == 1) {
        cout << "0\n"; return;
    }
    ll res = 0;
    ll aptos = 1;
    ll plata = 0;
    while(true){
        // cout << plata << ' ' << aptos << endl;
        plata += aptos * b;
        res++;
        if (plata >= a){
            // cout << plata << endl;
            // cout << plata/a << endl;
            aptos += (plata/a);
            // cout << "compro " << aptos << endl;
            if (aptos >= c){
                cout << res << "\n"; return;
            }
            plata -= ((plata/a )* a);
            // cout << "plata = " <<plata << endl;
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