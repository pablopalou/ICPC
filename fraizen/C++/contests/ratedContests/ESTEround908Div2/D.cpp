//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)

//NO FUNCIONA 

// Copiar obligatoriamente 0
void solve() {
    ll n, m; cin >> n >> m;
    ll res[n+m];
    ll a[n];
    ll b[m];
    fr(0,n){
        cin >> a[i];
    }
    fr(0,m){
        cin >> b[i];
    }
    //falta el caso de los numeros que quedan entre a[0] y a[-1] y a[0] > a[-1];
    sort(b, b+m, greater<ll>());
    ll pos = 0;
    // breakeo = false;
    while (pos < m && b[pos] >= a[0]){
        res[pos] = b[pos];
        pos++;
    }
    ll ultPos = pos;
    if (a[0] > a[n-1]){
        if (pos < m && b[pos] < a[0] && b[pos] > a[n-1]){
            res[pos] = a[0];
            pos++;
            res[pos] = b[pos-1];
            pos++;
            while (pos-1 < m && b[pos-1] < a[0] && b[pos-1] > a[n-1]){
                res[pos] = b[pos-1];
                pos++;
            }
            ultPos = pos;
            while (pos < m){
                res[pos + n] = b[pos];
                pos++;
            }
            // desde ultPos en adelante  meto el arreglo a.
            fr(1,n){
                res[ultPos + i - 1] = a[i];
            }
            fr(0,n+m){
                cout << res[i] << ' ';
            }
            cout << "\n";
            return;
        } else {
            while (pos < m){
                res[pos + n] = b[pos];
                pos++;
            }
            // desde ultPos en adelante  meto el arreglo a.
            fr(0,n){
                res[ultPos + i] = a[i];
            }
            fr(0,n+m){
                cout << res[i] << ' ';
            }
            cout << "\n";
            return;
        }
    } else {
        while (pos < m){
            res[pos + n] = b[pos];
            pos++;
        }
        // desde ultPos en adelante  meto el arreglo a.
        fr(0,n){
            res[ultPos + i] = a[i];
        }
        fr(0,n+m){
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}