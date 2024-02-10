#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
const int MAXN = 1005;
int par[MAXN];
vector<ll> hijos[MAXN];
ll dp[MAXN][2][2];

struct Circle{
    ll x,y,r;
};
Circle circles[MAXN];

bool circle_inside_circle(Circle c1, Circle c2){
    return sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y)) < c2.r;
}
// dp[i][j][k] = Si hago desde i hacia abajo en el arbol, con j y k como la paridad de los grupos de mis ancestros, cual es el maximo valor que puedo obtener;
void dfsdp(ll u){
    ll g[2][2] = {{0}}; // aca van los resultados de los hijos segun paridad del grupo 1 y del grupo 2
    for(auto nei: hijos[u]){
        dfsdp(nei);
        fr(0,2){
            rep(j,0,2){
                g[i][j] += dp[nei][i][j];
            }
        }
    }
    //ahora tengo que guardar mi resultado en la dp. Para esto, me fijo todas las combinaciones posibles de mis hijos y en cada una me quedo con el maximo entre ponerme en el grupo 1 o ponerme en el grupo 2.
    fr(0,2){
        rep(j,0,2){
            //veo si me conviene asignarla al primer grupo o al segundo...
            dp[u][i][j] = max(
                g[i^1][j] + circles[u].r * circles[u].r * (i == 0 ? 1 : -1), //me pongo en el grupo 1, entonces mis hijos tienen que tener la otra paridad en el grupo 1 (por eso el ^ 1). Eso daria lo que ya tengo como mucho si tengo tal paridad en el grupo 1 y tal paridad en el grupo 2. Luego, sumo o resto mi area dependiendo en la paridad de la i.
                g[i][j^1] + circles[u].r * circles[u].r * (j == 0 ? 1 : -1)
            );
        }
    }
}
// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;

    fr(0,n){
        Circle c;
        cin >> c.x >> c.y >> c.r;
        circles[i] = c;
    }

    fill(par, par + n, -1);
    fr(0,n){
        rep(j,0,n){
            if (i == j) continue;
            if (circles[i].r < circles[j].r && circle_inside_circle(circles[i], circles[j])){
                // cout << i+1 <<" adentro de " << j+1 << endl;
                if (par[i] == -1 || circles[par[i]].r > circles[j].r){
                    par[i] = j;
                }
            }
        }
        hijos[par[i]].push_back(i);
    }

    fr(0,n){
        rep(j,0,2){
            rep(k,0,2){
                dp[i][j][k] = 0;
            }
        }
    }

    ll ans = 0;
    fr(0,n){
        if (par[i] == -1){
            dfsdp(i);
            ans += dp[i][0][0];
        }
    }
    cout << fixed << setprecision(12) << ans * acos(-1) << "\n";
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