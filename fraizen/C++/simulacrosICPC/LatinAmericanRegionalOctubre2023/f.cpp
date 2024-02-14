#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

vector<ll> convertir(ll n, ll b){ //convierte n en base 10 a base b
    vector<ll> res;
    while(n){
        res.pb(n%b);
        n/=b;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool esPalindrome(vector<ll> nros){
    int size = nros.size();
    fr(0,nros.size()/2){
        if (nros[i] != nros[size-1-i]){
            return false;
        }
    }
    return true;
}

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    if (n == 2){
        cout << "*\n"; return;
    }
    vector<ll> res;
    res.pb(n-1);
    //ahora me fijo casos de palindromes de largo 3 o mas.
    ll maximo = ll(ceil(sqrt(n-1)));
    fr(2,maximo+1){ //itero sobre las bases hasta la raiz de n basicamente
        // con este if demora 218 ms, si lo saco demora 202 ms ???
        // if (n % i == 0){ // n es multiplo de la base, y por ende termina en 0 y no es palindrome, entonces paso a la siguiente base
        //     continue;
        // }
        vector<ll> nros = convertir(n,i);
        if (esPalindrome(nros)){
            res.pb(i); //imprimo la base si el nro en esa base es palindrome
        }
    }
    //me fijo palindromes de largo 2. (dd)
    ll inicio = -1 + ll(floor(sqrt(1+n)));
    for(ll d = inicio; d>=2; d--){ //pruebo el dd. Basicamente me tengo que fijar si N es multiplo.
        // cout << "Pruebo d = " <<d << endl;
        if (n%d == 0){
            ll base = n/d - 1;
            res.pb(base);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    fr(0, res.size()){
        cout << res[i] << " ";
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

    ll cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}