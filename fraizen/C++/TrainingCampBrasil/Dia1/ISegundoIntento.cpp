#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mod 998244353
const int MAXN = 1e5+2;
ll dp[MAXN][2];
int a[MAXN];
int n;

int solveDP(int i, int j, int val, int anterior){
    //tengo que ver bien que onda con la j si es resuelto de ahora o desde el anterior...
    // cout << "i = " << i << ", j = " << j << ", val = " << val << ", ant = " << anterior << endl;
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    if (i == 0 && j == 0){ //esto es que no se resolvio el anterior igual...
        if (a[0] == -1){
            dp[i][j] = val; // esto es xq tengo que meter el mismo valor que antes, no queda otra.
        } else {
            if (a[i] < anterior || a[i] > anterior){
                dp[i][j] = 0; //se caga el primero o el anterior xq no esta resuelto
            } else {
                dp[i][j] = val; //dejo el que estaba y no se rompe nada
            }
        }
        return dp[i][j];
    }
    if (i == 0 && j == 1){ // caso base
        if (a[0] == -1){
            dp[i][j] = ((val % mod) * (anterior % mod)) % mod; //tengo anterior opciones ademas de las val que ya tenia
        } else {
            if (a[0] > anterior){
                dp[i][j] = 0;
            } else if (a[0] <= anterior){
                dp[i][j] = val;
            }
        }
        return dp[i][j];
    }
    //caso general
    if (j == 1){ //si ya estamos resueltos entonces vemos el de ahora
        if (a[i] != -1){ //no podemos elegir
            if (a[i] > anterior){
                dp[i][j] = solveDP(i-1, 0, val, a[i]);
                return dp[i][j]; //aun no estamos resueltos
            } else {
                dp[i][j] = solveDP(i-1, 1, val, a[i]);
                return dp[i][j]; //ya estamos resueltos
            }
        } else { // tenemos que tocar a[i] xq es -1
            int newVal = val;
            rep(j,anterior+1, 201){
                newVal = ((newVal % mod +  (solveDP(i-1, 0, val, j)%mod ))% mod); //sumamos todos los valores mas grandes y ponemos no resuelto
            }
            rep(j,1,anterior+1){
                newVal = ((newVal % mod )+ (solveDP(i-1,1,val,j) % mod)) % mod; //sumamos todos los mas chicos o iguales y pasamos que estamos resueltos
            }
            dp[i][j] = newVal;
            return dp[i][j];
        }
    } else if (j == 0) { // si no estamos resueltos hay que resolver si o si al anterior. Hay que poner uno mas grande o igual
        if (a[i] != -1){
            if (a[i] < anterior){
                dp[i][j] = 0;
                return 0;
            } else {
                dp[i][j] = val;
                if (a[i]==anterior){
                    //estoy resuelto
                    dp[i][j] = solveDP(i-1, 1, val, anterior);
                } else { //no me resuelvo xq pongo algo mas grande
                    dp[i][j] = solveDP(i-1, 0, val, a[i]);
                }
                return dp[i][j];
            }
        } else {// podemos elegir uno mas grande o igual
            int newVal = val ==1 ? 0 : val;
            if (anterior == 0){ //estamos en el utlimo entonces para ningun valor vamos a quedar resueltos
                rep(j,1, 201){
                    int fraizen = solveDP(i-1, 0, val, j) % mod;
                    if (fraizen > 0){
                    // cout << "1Agrego " << fraizen << " con valor de j = " << j << endl;
                }
                    newVal = ((newVal % mod + fraizen)% mod); //sumamos todos los valores mas grandes y ponemos no resuelto
                }
            } else {
                int fraizen = solveDP(i-1, 1, val, anterior);
                if (fraizen > 0){
                    // cout << "2Agrego " << fraizen << " con valor de j = " << anterior << endl;
                }
                newVal = (newVal % mod + fraizen % mod) % mod; //pongo mismo valor
                rep(j,anterior+1, 201){
                    fraizen = (solveDP(i-1, 0, val, j)%mod);
                    if (fraizen > 0){
                    // cout << "3Agrego " << fraizen << " con valor de j = " << j << endl;
                }
                    newVal = ((newVal % mod +  fraizen ))% mod; //sumamos todos los valores mas grandes y ponemos no resuelto
                }
            }
            dp[i][j] = newVal;
            return dp[i][j];
        }
    }
    return 0;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    bool cortar = true;
    fr(0,n){
        cin >> a[i];
        // if (a[i] == -1){
        //     cortar = false; //podria handlear el caso por fuera pero la recursion deberia funcionar
        // }
    }
    memset(dp, -1, sizeof(dp));
    // dp[i][j] = cantidad de posibles combinaciones hasta la posicion i. Segundo parametro para ver si el anterior ya esta resuelto (true) o no (false)
    cout << solveDP(n-1, 0, 1, 0) << '\n';
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