#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll a[3]={0,0,0};
double dp[303][303][303]; //valor esperado teniendo i platos con cantidad 1, j platos con cantidad 2 y k platos con cantidad 3
ll n;

double f(ll i, ll j, ll k){
    if (i < 0 || (j < 0) || k < 0) return 0;
    double &res = dp[i][j][k];
    if (res != -1) return res;
    if (i == 0 && j == 0 && k == 0) return 0; //ya termine
    //ahora hago las transiciones.
    //podria sacar uno del contador 3.
    //podria sacar uno del contador 2.
    //uno del contador 1.
    //algo del contador 0.
    double num = 1 + f(i-1,j,k) * (i / (double)n) + f(i+1, j-1, k) * (j / double(n)) + f(i,j+1,k-1) * (k / double(n));
    double den = double(1.0 - double((n - (i+j+k))/double(n)));
    res = num / den;
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,303){
        rep(j,0,303){
            rep(k,0,303){
                dp[i][j][k] = -1;
            }
        }
    }
    fr(0,n){
        int c; cin >> c; c--;
        a[c]++;
    }
    cout << fixed << setprecision(12) << f(a[0],a[1],a[2]) << "\n";
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