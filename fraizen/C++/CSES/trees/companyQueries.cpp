#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const int maxH = 22;
const int maxN = 200005;
int far[maxH][maxN];
int n,q;

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> q;
    memset(far, 0, sizeof(far)); //inicializo padres con 0
    fr(2,n+1){
        cin >> far[0][i]; //ponemos a los padres de i
        // cout << far[0][i] << ' ';
    }
    // cout << endl;
    //armamos la tabla siguiendo la recurrencia: 𝑓𝑎𝑟(ℎ,𝑖)=𝑓𝑎𝑟(ℎ−1,𝑓𝑎𝑟(ℎ−1,𝑖))
    rep(h, 1, maxH){
        rep(i, 1, n+1){
            far[h][i] = far[h-1][far[h-1][i]];
            // cout << far[h][i] << ' ';
        }
        // cout << endl;
    }

    //ahora contestamso las queries. 
    fr(0,q){
        int x, k; cin >> x >> k;
        //tengo que ir por cada bit prendido digamos.
        rep(j, 0, maxH){
            if (((1 << j) & k )== (1 << j)){
                x = far[j][x];
            }
        }
        if ( x!= 0){
            cout << x << endl;
        } else {
            cout << -1 << endl;
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