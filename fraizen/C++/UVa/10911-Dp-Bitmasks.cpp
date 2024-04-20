#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define int long long int

struct pto{
    int x,y;
};

double dp[1 << 16 + 5];
double dist[17][17];

#define LSOne(S) ((S) & -(S))

double f(int mask){
    //0 si ya esta matcheado, 1 si falta matchear.
    double &r = dp[mask];
    if (r != -1.0) return dp[mask];
    if (mask == 0) return 0;
    r = 1e9;
    //ahora tengo que juntar el primer bit con todos los demas y ver cual es el mejor digamos...
    int maskOne = LSOne(mask);
    int p1 = __builtin_ctz(maskOne); //cuento leading zeros a la derecha...
    int m = mask - maskOne; //ese 1 lo apago en la mascara porque es el que voy a juntar con otro
    while (m){
        //agarro el primer uno disponible
        int maskTwo = LSOne(m);
        int p2 = __builtin_ctz(maskTwo);
        //ahora ya tengo los puntos p1 y p2... (en realidad los indices), hago la cuenta
        r = min(r, dist[p1][p2] + f(mask - maskOne - maskTwo)); // a la mascara le tengo que poner en 0 el indice p1 y p2 xq los estoy matcheando
        m -= maskTwo; // le saco la mascara para borrarle ese bit digamos
    }
    return r;
}

void solve2(int n){
    pto p[n];
    fr(0,n){
        string s;
        cin >> s >> p[i].x >> p[i].y;
    }
    fr(0,n){
        rep(j, i+1, n){
            dist[i][j] = dist[j][i] = hypot(p[i].x - p[j].x, p[i].y - p[j].y);
        }
    }
    fr(0,1<<n){
        dp[i] = -1.0;
    }
    cout << fixed << setprecision(2) << f((1<<n) - 1) << "\n";
}

// Copiar obligatoriamente 0
void solve() {
    int n;
    int i = 1;
    while(cin >> n){
        if (n == 0){
            break;
        }
        cout << "Case "<< i <<": ";
        solve2(n*2);
        i++;
    }
}

// ACORDATE DE USAR LONG LONG
int32_t main() {
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