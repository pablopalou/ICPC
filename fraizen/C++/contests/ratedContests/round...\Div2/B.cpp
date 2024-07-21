#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,m; cin >> n >> m;
    int a[n][m];
    int b[n][m];
    fr(0,n){
        string s; cin >> s;
        rep(j,0,m){
            a[i][j] = s[j] -'0';
        }
    }
    fr(0,n){
        string s; cin >> s;
        rep(j,0,m){
            b[i][j] = s[j]-'0';
        }
    }
    fr(0,n-1){
        rep(j,0,m-1){
            // cout << "i = " << i << " j = " << j << endl;
            if (a[i][j] == b[i][j]) {
                continue;
            }
            if (((a[i][j] + 1)%3) == b[i][j]){
                a[i][j] = (a[i][j] + 1) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + 1) % 3;
                a[i+1][j] = (a[i+1][j] + 2) % 3;
                a[i][j+1] = (a[i][j+1] + 2) % 3;
            } else {
                a[i][j] = (a[i][j] + 2) % 3;
                a[i+1][j+1] = (a[i+1][j+1] + 2) % 3;
                a[i+1][j] = (a[i+1][j] + 1) % 3;
                a[i][j+1] = (a[i][j+1] + 1) % 3;
            }
        }
    }
    fr(0,n){
        rep(j,0,m){
            if (a[i][j] != b[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    //leo las dos matrices
    //voy cambiando la primera para que sea igual a la segunda. 
    //asumo que solo sirve cambiar el 2x2 y chau.
    //me fijo que haya quedado bien 
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