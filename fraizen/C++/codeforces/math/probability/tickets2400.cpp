#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
const int MAXN = 2e5 + 10;
double fac[MAXN];
// Copiar obligatoriamente 0
void solve() {
    int n,m,k; cin >> n>> m >> k;
    fac[0] = 0.0; //guardamos el logaritmo en base 10 del verdadero factorial
    fr(1,200002){
        fac[i] = fac[i-1] + ((log10(double(i)))); //aca va la suma xq la suma en logaritmos es la multiplicacion
    }
    if (n + k < m){
        cout << "0\n";
        return;
    }
    if (m <= k){
        cout << "1\n";
        return;
    }
    double res = fac[m] - fac[m-k-1] - (fac[n+k+1] - fac[n]);
    // cout << fixed << setprecision(10) << res << "\n";
    if (res < -10){
        cout << "1.0\n";
        return;
    }
    res =  1.0 - pow(10.0 , res);
    cout << fixed << setprecision(10) << res << "\n";
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