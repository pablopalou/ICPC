#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
const int MAXN = 21;
ll n,m, k;
map<ll, ll> mapa[MAXN][MAXN]; //tengo un mapa por cada posicion. En el mapa guardo: clave = valor del xor, valor = cantidad que tienen ese valor del xor
ll a[MAXN][MAXN];
ll ans;

void solve1(ll pasos, ll posX, ll posY, ll curXor){
    curXor ^= a[posX][posY];
    if (posX > n-1 || posY > m-1) return;
    if (pasos == 0){
        mapa[posX][posY][curXor]++;
        return;
    }
    //llamo a la derecha y llamo a abajo
    solve1(pasos-1, posX, posY+1, curXor);
    solve1(pasos-1, posX+1, posY, curXor);
}

void solve2(ll pasos, ll posX, ll posY, ll curXor){
    if (posX < 0 || posY < 0) return;
    if (pasos == 0){
        ans += mapa[posX][posY][curXor^k];
        return;
    }
    //llamo a la izquierda y llamo a arriba
    curXor^=a[posX][posY];
    solve2(pasos-1, posX, posY-1, curXor);
    solve2(pasos-1, posX-1, posY, curXor);
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> m >> k;
    fr(0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }

    int pasos = n+m-2;
    int primero = pasos/2;
    if (pasos&1){
        primero++;
    }
    int segundo = pasos/2;

    ans = 0;
    solve1(primero, 0, 0, 0);
    solve2(segundo, n-1,m-1, 0);
    cout << ans << '\n';
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