#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const int MMAX = 35;
const int NMAX = 18;
int n,m,p; 

class Rat {
public :
    long long num, den;
    Rat(long long n=0, long long d=1) { set(n,d); }

    void set(long long n, long long d) {
        num = n;
        den = d;
        reduce();
    }

    void reduce() {
        if (num == 0) {
            den = 1;
            return;
        }
        long long factor = gcd(num, den);
        num = num / factor;
        den = den / factor;
        return;
    }

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    Rat& operator=(const Rat& other)
    {
        num = other.num;
        den = other.den;
        return *this;
    }
};

Rat dp[NMAX][MMAX]; // prob de tener tachados i cuadrados en j tiradas.

// Copiar obligatoriamente 0
void solve() {
    cin >> m >> n >> p;
    //prob 1 de tener 0 cuadrados tachados en 0 tiros
    dp[0][0] = Rat(1,1);
    //imposible tener cuadrados tachas si aun no tire
    fr(1,n+1){
        dp[i][0] = Rat(0,1);
    }
    dp[0][1] = Rat(m-2*n, m); //prob de tirar afuera
    fr(2,p+1){ //prob de seguir tirando para afuera (acordarse de sacar los que ya saque)
        dp[0][i] = Rat(dp[0][i-1].num * (m - 2*n - (i-1)), dp[0][i-1].den * (m - (i-1)));
    }
    //ahora llenar la tabla posta
    fr(1,n+1){
        rep(j, 1, p+1){
            //aca tenemos dos chances, o tachamos un nuevo cuadrado o no.
            // Rat probErrar = Rat(m - 2 * n - (j -1 - i),m - (j-1));
            Rat probErrar = Rat(m - (j-1) - (2*n - 2*i), m- (j-1));
            Rat probEmbocar = Rat(2 * n - (2 * (i-1)), m - (j-1));
            // Rat probEmbocar = Rat(m - 2 * (i-1) - (j-1 - (i-1)), m - (j-1));
            Rat errar = Rat(dp[i][j-1].num * probErrar.num, dp[i][j-1].den * probErrar.den);
            Rat embocar = Rat(dp[i-1][j-1].num * probEmbocar.num, dp[i-1][j-1].den * probEmbocar.den);
            dp[i][j] = Rat(errar.num * embocar.den + embocar.num * errar.den, errar.den * embocar.den);
        }
    }

    //conseguir respuesta:
    Rat ans;
    if (p == 0){
        ans = dp[n][p];
    } else {
        //tengo que agarrar exactamente en la tirada p.
        // para esto hago: dp[n][p] - dp[n][p-1].
        ans = Rat(dp[n][p].num * dp[n][p-1].den - dp[n][p].den * dp[n][p-1].num, dp[n][p].den * dp[n][p-1].den);
    }

    // fr(0,n+1){
    //     rep(j, 0, p+1){
    //         cout << dp[i][j].num << "/" << dp[i][j].den << ' ';
    //     }
    //     cout << endl;
    // }

    cout << ans.num << '/' << ans.den << "\n";
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