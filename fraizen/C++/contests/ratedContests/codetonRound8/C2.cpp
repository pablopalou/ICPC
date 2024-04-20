#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

struct customSort{
    bool operator()(int a, int b) const{
        if (a==b){
            return false;
        }
        if (a % 2 != b % 2){
            if (a%2 == 1){
                return true;
            } else {
                return false;
            }
        }
        return a < b;
    }
};

// Copiar obligatoriamente 0
void solve() {
    ll n, x, y; cin >> n >> x >> y;
    ll pos[x];
    fr(0,x){
        cin >> pos[i];
    }
    sort(pos, pos+x);
    ll res = n-2;
    map<ll,ll,customSort> m;
    fr(1,x){
        if (pos[i] - pos[i-1] - 1 > 1){
            res -= pos[i] - pos[i-1] - 1;
            m[pos[i] - pos[i-1] - 1]++;
        }
    }
    if ((n - pos[x-1]) + pos[0] - 1 > 1){
        res -= (n - pos[x-1]) + pos[0] - 1;
        m[(n - pos[x-1]) + pos[0] - 1]++;
    }
    // cout << res << "\n";
    //hasta aca es el otro. Tengo res minimo... ahora faltaria agregar hasta y cosas. 
    //mochila digamos. pero de 10 ^9, no entra...

    //capaz lo mejor es hacer un mapa y contar la cantidad de cada cosa.
    //hacer un custom comparator de tal forma que quede 3,5,7,9,11,..., 2, 4, 6 ,8 ,10. 
    // ahi el mapa no deberia quedar enorme supongo (10^5 max).
    // hago un for y pongo lo maximo que pueda en cada cosa hasta quedarme sin y, voy sumando a res.
    //el tema es que si corto me quedan mas para abajo no? no creo que haya drama
    fre(m){
        int cortes = e.first / 2 * e.second;
        if (y >= cortes){
            y-=cortes;
            res += (e.first * e.second);
        } else { //aca hay que hacer el handle del caso de 3 al final...
            cortes = e.first / 2;
            while (y >= cortes){ 
                y-=cortes;
                res+=e.first;
            }
            //ahora si voy de a un corte
            while(y > 0){
                y--;
                res+=2;
            }
        }
        if (cortes == 0){
            break;
        }
        // cout << e.first << " " << e.second << endl;
    }
    cout << res << "\n";
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