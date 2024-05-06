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
    int h,w,xa,ya,xb,yb; cin >> h >> w >> xa >> ya >> xb >>yb;
    if (xa >= xb){
        cout << "Draw\n"; return;
    }
    int dist = xb - xa;
    int mov = dist / 2;
    if (dist & 1){
        //puede ganar alice, bob tiene que correr a una punta
        //alice tiene un movimiento mas...
        // cout << "Dist= "<< dist << endl;
        int izq = max(1, yb - mov);
        int der = min(w, yb + mov);
        int izqA = max(1, ya - (mov+1));
        int derA = min(w, ya + mov + 1);
        // cout << "izq " << izq << endl;
        // cout << "der " << der << endl;
        // cout << "izqA " << izqA << endl;
        // cout << "derA " << derA << endl;
        if (derA >= der && izqA <= izq){
            cout << "Alice\n";
        } else {
            cout << "Draw\n";
        }
    } else {
        //puede ganar bob, alice tiene que correr. Los dos tienen mov movimientos
        int izq = max(1, yb - mov);
        int der = min(w, yb + mov);
        int izqA = max(1, ya - mov);
        int derA = min(w, ya + mov);
        if (der >= derA && izq <= izqA){
            cout << "Bob\n";
        } else {
            cout << "Draw\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}