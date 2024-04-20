#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    ll n, x, y; cin >> n >> x >> y;
    // cout << "CASO "  << endl;
    ll pos[x];
    fr(0,x){
        cin >> pos[i];
    }
    sort(pos, pos+x);
    // if ( x >= n-1){
    //     cout << n-2 << "\n"; return;
    // }
    // fr(0,x){
    //     cout << pos[i] << " ";
    // }
    // cout << "\n";
    //veo parejas consecutivas y voy sacando dos de la respuesta
    ll res = n-2;
    fr(1,x){
        if (pos[i] - pos[i-1] - 1 > 1){
            res -= pos[i] - pos[i-1] - 1;
        }
    }
    //falta restar solo el ultimo con el 0.
    if ((n - pos[x-1]) + pos[0] - 1 > 1){
        res -= (n - pos[x-1]) + pos[0] - 1;
    }
    cout << res << "\n";
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