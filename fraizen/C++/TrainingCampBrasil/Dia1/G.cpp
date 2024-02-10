#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
//funciona goddd

// Para cada numero, tengo de quien es submascara.
// la dp es basicamente dame un numero que este en la lista, que sea submascara mia.
//entonces me fijo dp[complemento] ya que solo quiero uno de la lista que sea submascara del complemento
// no puedo tener uno que no sea submascara xq ahi el and daria 1.
vector<ll> dp(ll(4200000), -1);

void fillDP(ll number, ll pos, ll padre){
    if (number >= 4200000){
        return;
    }
    if (dp[number]!=-1){
        return;
    }
    if (pos == -1){ // caso base
        dp[number] = padre;
        return;
    }
    if (1 << pos & number){ //el bit esta en 1, solo pasamos al siguiente
        fillDP(number, pos-1, padre);
    } else { //el bit esta en 0.
        fillDP(number, pos-1, padre);
        fillDP(number | (1<<pos), pos-1, padre);
    }
}

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    unordered_map<ll,ll> m;
    ll a[n];
    fr(0,n){
        cin >> a[i];
        m[a[i]]++;
    }
    fr(0,n){
        fillDP(a[i], 22, a[i]);
    }
    fr(0,n){
        //me fijo si tengo una submascara del complemento
        ll comp = a[i] ^ ((1<<22) -1);
        // cout << "Complemento: " << comp << '\n';
        cout << dp[a[i] ^ ((1<<22) -1)] << " ";
    }
    cout(' ');
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