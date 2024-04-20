#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const int MAXN = 1000100;
int min_div[MAXN];
// Copiar obligatoriamente 0
void solve() {
    int n,m; cin >> n >> m;
    if (n == 1){
        cout << "YES\n"; return;
    }
    min_div[n] > m ? cout << "YES\n": cout << "NO\n";
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

    //aca precomputo

    for(int d = 2; d * d < MAXN; d++){
        for(int i = d*d; i<MAXN; i+=d){
            if (min_div[i] == 0){
                min_div[i] = d;
            }
        }
    }
    fr(1,MAXN){
        if (min_div[i] == 0){
            min_div[i] = i;
        }
    }
    // fr(1,20){
    //     cout << min_div[i] << " ";
    // }

    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}