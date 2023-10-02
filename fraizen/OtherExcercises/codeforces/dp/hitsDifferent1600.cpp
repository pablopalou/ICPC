#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000025
tuple<ll,ll,ll> dp[MAXN];

void precalc() {
    // NUMERO, NIVEL, VALOR
    dp[0] = {0,0,0};
    dp[1] = {1,1,1};
    ll actual = 2;
    ll cur = 2;
    ll nivel = 2;
    while (true){
        dp[cur] = {cur, nivel,cur*cur};
        cur+=1;
        actual-=1;
        if (actual == 0){
            nivel++;
            actual = nivel;
        }
        if (cur > 1000020){
            break;
        }
    }
    // fr(0,100){
    //     ll a, b;
    //     ll c;
    //     tie(a,b,c) = dp[i];
    //     cout << a << ' ' << b << ' ' << c;
    //     cout(' ');
    // }
}

void armardp(){
    fr(2,1000018){
        ll a, nivel;
        ll valor;
        tie(a,nivel,valor) = dp[i];
        
        if (get<1>(dp[i-1]) == nivel-1){
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel+1]);
        } else if (get<1>(dp[i+1]) == nivel+1){
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel]);
        } else {
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel+1]) + get<2>(dp[i-nivel]) - get<2>(dp[i-(nivel-1)*2]);
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // o(n)
    // primero precalculo el array con (nro, nivel, valor), valor en principio es el numero al cuadrado.
    precalc();
    armardp();
    // luego ya si armo la dp. O(n)
    // Si el de la izquierda es un nivel menos, solo agarro el valor del que tengo nivel-1 a la izquierda. 
    // Si el de la derecha es un nivel mas, solo agarro el valor del nivel a la izquierda. 
    // Si estoy en el medio, no hay cambio de nivel a los costados, agarro el valor del n-1 a la izquierda y tambien el del n a la izquieda.  
    
    int cases;
    cin >> cases;
    while (cases--){
        // respondo las queries en O(1)
        ll n;
        cin >> n;
        ll a, b;
        ll c;
        tie(a,b,c) = dp[n];
        cout << c << "\n";
    }
}