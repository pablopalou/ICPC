#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int unos, dos, tres, cuatros; cin >> unos >> dos >> tres >> cuatros;
    if (unos >= 2 || dos >= 2 || tres >=2 || cuatros >=2){
        int res = 0;
        if ((unos & 1) && (dos & 1) && (tres & 1)){
            res++;
        }
        cout << res + unos/2 + dos/2 + tres/2 + cuatros/2 << "\n";
    } else {
        if (unos && dos && tres){
            cout << "1\n";
        } else {
            cout  << "0\n";
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