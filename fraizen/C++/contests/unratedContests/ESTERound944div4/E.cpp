#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define ld long double

// Copiar obligatoriamente 0
void solve() {
    ll n,k,q; cin >> n >>k >>q;
    ll a[k+1];a[0] = 0;
    fr(1,k+1){
        cin >> a[i]; //aca van los kilometros
    }
    // fr(0,k+1){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    ll b[k+1]; b[0] = 0;
    fr(1,k+1){
        cin >> b[i]; //aca los minutos
    }
    fr(0,q){
        ll d; cin >> d;
        // cout << "Query " << d << endl;
        ll pos = lower_bound(a, a+k+1, d) - a;
        if (a[pos] == d){
            cout << b[pos] << " "; continue;
        }
        //tenemos al siguiente digamos
        ll res = b[pos-1];
        ll dist = a[pos] - a[pos-1];
        ll tiempo = b[pos] - b[pos-1];
        ll faltaDistancia = d - a[pos-1];
        cout << res + (tiempo*faltaDistancia/dist) << ' ';
        // long double velocidad = ((ld)(dist))/tiempo;
        // ll tiempoRestante = faltaDistancia/velocidad;
        // cout << tiempoRestante + res << ' ';
        //primero hallo el lower_bound digamos y luego hago el calculo con el siguiente.
        // ll pos = lower_bound(a, a+k+1, d) - a;
        // // cout << "POS " << pos << endl;
        // if (a[pos] > d && pos > 0){
        //     pos--;
        // } else {
        //     cout << b[pos] << " "; continue;
        // }

        // ll res = b[pos];
        // if (pos == k){
        //     cout << res << " "; continue;
        // } 

        // // cout << "POS es " << pos <<"  y HERE con res " << res  << endl;
        // ll dist = a[pos+1] - a[pos];
        // ll min = b[pos+1] - b[pos];
        // double vel = dist/(double)min;
        // ll falta = d-a[pos];
        // double sumar = falta/vel;
        // //ahora tengo que ir de pos al siguiente.
        // ll FRAIZENFRAIZEN = res + ll(floor(sumar));
        // cout << FRAIZENFRAIZEN << " ";
        // cout << endl;
    }
    cout << "\n";
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