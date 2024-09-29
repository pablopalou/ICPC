#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

//ESTE DIO ACCEPTED
void solve() {
    ll a,l,s,r; cin >> a >> s >> l >> r;
    if (a == s) {cout << "1\n"; return;}
    ll res = 0;
    //itero cada d
    rep(d,1,r-l+1){
        // cout << "Pruebo d = " << d << endl;
        ll izq = a;
        ll der = a;
        while(izq - d >= l){
            izq-=d;
        }
        ll k = (der - izq)/d + 1;
        //hago two pointers
        ll kDer = (der - a)/d;
        assert(kDer == 0);
        ll kIzq = k - kDer -1;
        ll suma = a*k - d * (kIzq * (kIzq + 1))/2 + d * (kDer * (kDer + 1))/2;
        // cout << "izq = " << izq << endl;
        // cout << "der = " << der << endl;
        // cout << "Suma = " << suma << endl;
        while(der <=r && izq <= a){
            // cout << "izq = " << izq << endl;
            // cout << "der = " << der << endl;
            // cout << "Suma = " << suma << endl;
            if (suma > s){
                //muevo la izquierda
                izq += d;
                suma -= a - d * kIzq;
                kIzq--;
                k--;
            } else if (suma < s){
                der += d;
                kDer++;
                suma += a + d * kDer;
                k++;
            } else {
                // cout << "RES++" << endl;
                res++;
                izq += d;
                suma -= a - d * kIzq;
                kIzq--;
                k--;
                der += d;
                kDer++;
                suma += a + d * kDer;
                k++;
            }
        }
    }
    cout << res << '\n';
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