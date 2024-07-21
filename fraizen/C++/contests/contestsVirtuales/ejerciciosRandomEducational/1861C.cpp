#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    int ord = 0;
    int cant = 0;
    int des = 0;
    fr(0,s.size()){
        if (s[i] == '+'){
            cant++;
            if (cant == 1){
                ord = 1;
            }
        } else if (s[i] == '-'){
            cant--;
            if (des > cant){
                des = 0;
            }
            if (cant <= 1){
                ord = cant;
            } else {
                ord = min(ord, cant);
            }
        } else if (s[i] == '1'){
            if (des){
                cout << "NO\n"; return;
            }
            ord = cant;
        } else {
            if (cant <= 1){
                cout << "NO\n"; return;
            }
            if (ord == cant){
                cout << "NO\n"; return;
            }
            if (des == 0){
                des = cant;
            }
        }
    }
    cout << "YES\n";
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