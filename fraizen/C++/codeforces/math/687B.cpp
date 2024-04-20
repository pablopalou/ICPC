#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

ll __gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); } 

ll lcm(ll a, ll b) {return a * b / gcd(a,b);}

//lo que seguro funciona es cada numero descomponerlo en primos y fijarme si k esta incluido en todos o no.
// Copiar obligatoriamente 0
void solve() {
    ll n,k; cin >>n>>k;
    ll a[n]; fr(0,n) cin >> a[i];
    //yo necesito ver si k esta en la multiplicacion de los otros digamos, entonces puedo recorrer todos e ir haciendo el gcd
    //en el segundo parametro como que dejo el lcm global que tambien tiene a k
    //si yo tengo todo lo de k, entonces me voy a quedar con (gcd (k,k) que es k, y devuelvo yes)
    ll cur = 1;
    // cout << "K " << k << endl;
    fr(0,n){
        // cout << cur << endl;
        // cout << "Hago lcm entre " << cur << " y " << a[i] << endl;
        ll mcm = lcm(cur, a[i]);
        // cout << "lcm " << mcm << endl;
        // cout << "Hago gcd entre " <<k << " y " << mcm << endl;
        cur = __gcd(k, mcm);
        // cout << "Cur = " << cur << endl;
    }
    // cout << __gcd(5LL,5LL) << endl;
    // cout << cur << endl;
    if (cur == k){
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }
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

