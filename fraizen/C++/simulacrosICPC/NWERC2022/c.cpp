#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
ll n;
#define eps 1e-12
typedef long double ld;

ld dist(ll x, ll y){
    return sqrt(x*x + y*y);
}

ll contar(ld radio){
    //hago pitagoras para contar por columna
    // ll res = 0;
    // ll piso = int(radio);
    // ll y = piso;
    // ll x = 1;
    // ll maxX = piso;
    // while(x <= maxX){
    //     res += int(sqrt(radio*radio - x*x));
    //     x+=1;
    // }
    // // cout << "res = " << res << " con radio " << radio << endl;
    // return res * 4;

    //no anda
    //primer cuadrante
    ll res = 0;
    ll piso = floor(radio);
    ll maxX = piso;
    ll y = piso;
    ll x = 1;
    // arranco en (0,piso) y voy pa la derecha y abajo
    ll dif = 1;
    while(x <= maxX && y >= 0){
        if (dist(x,y) <= radio + eps){ //este punto entra
            res += dif; 
            x += 1;
            dif++;
        } else {
            y -=1;
            dif-=1;
        }
    }
    //ACRODARSE DE GAUSS!
    res += (piso * (piso-1) / 2);
    // multiplico los cuadrantes
    // cout << "res = " << res << " con radio " << radio << endl;
    return res * 4;
}

bool puedo(ld radio){
    ll cantidad = contar(radio);
    return cantidad > n;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    ld l = sqrt(2);
    ld r = 1e5;
    ll iter = 0;
    ld ans = 100000;
    while(l+eps<=r && iter <= 100){
        iter++;
        ld mid = l + (r-l) / 2;
        // cout << "Pruebo mid = " << fixed << setprecision(10) << mid << endl;
        if (puedo(mid)){
            // cout << "Pude" << endl;
            ans = r;
            r = mid - eps;
        } else {
            // cout << "No pude" << endl;
            l = mid + eps;
        }
    }
    cout << fixed << setprecision(12) << ans << "\n"; 
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("c.out", "w", stdout);
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