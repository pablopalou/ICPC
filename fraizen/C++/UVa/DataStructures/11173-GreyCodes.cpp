#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

int res= 0;

void solve2(int n, int k){
    if (n == 0){
        cout << res << "\n"; return;
    }
    if (k > (1 << (n-1))){
        res = (res * 2) + 1;
        solve2(n-1, (1<<n) - k + 1);
    } else {
        res = res*2;
        solve2(n-1, k);
    }
}

// Copiar obligatoriamente 0
void solve() {
    int h; cin >> h;
    fr(0,h){
        int n,k; cin >> n >> k;
        res = 0;
        solve2(n,k+1); 
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