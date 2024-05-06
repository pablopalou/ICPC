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
    int k,x,a; cin >> k>>x>>a;
    if (a == 1){
        cout << "NO\n"; return;
    }
    int falta = x;
    int lose = 1;
    while(falta+1){
        // cout << "Lose " << lose << endl;
        int apuesta = (lose + k -2) / (k-1); 
        a-=apuesta;
        if (a < 0){
            cout << "NO\n"; return;
        }
        lose += apuesta;
        falta--;
    }
    if (a < 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
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