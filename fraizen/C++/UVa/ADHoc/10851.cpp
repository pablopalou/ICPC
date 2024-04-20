#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    string s;
    string a[10];
    int i = 0;
    fr(0,10) {
        cin >> a[i];
    }
    //ya tenemos las lineas es solo pasar a ascii e imprimir.
    rep(j,1,a[0].size()-1){
        int ascii = 0;
        fr(1,9){
            if (a[i][j] == '\\'){
                ascii += (1<<(i-1));
            }
        }
        cout << char(ascii);
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
    cin.ignore();
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}