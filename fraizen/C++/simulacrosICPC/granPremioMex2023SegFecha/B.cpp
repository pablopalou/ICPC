#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define mp make_pair

const ll MOD = 1000000007;

ll expMod(ll b, ll e, ll m = MOD) {
    if (e < 0) return 0;
    ll ret = 1;
    while(e) {
        if (e & 1) ret = ret * b % m; // aca hay comentario con ret = mulMod(ret,b,m);
        b = b * b % m; // b = mulMod(b,b,m);
        e >>= 1;
    }
    return ret;
}

// ll eulerPhi(ll n) {
//     map<ll, ll> f;
//     fact(n, f);
//     ll ret = n;
//     forall(it, f) ret -= ret / it->first;
//     return ret;
// }

ll inverso(ll x) {
//   return expMod(x, eulerPhi(MOD) - 1); // si mod no es primo(sacar a mano)
  return expMod(x, MOD - 2); // si mod es primo
}

typedef pair<int, bool> tipo;
const tipo neutro=mp(int(2e9),true);
tipo oper(const tipo& a, const tipo& b) { return mp(max(a.first, b.first), a.second && b.second && a.first <= b.first); }
struct ST {
    int sz;
    vector<tipo> t;
    ST(int n) {
        sz = 1 << (32 - __builtin_clz(n));
        t = vector<tipo>(2*sz, neutro);
    }
    tipo& operator[](int p) {return t[sz+p];}
    void updall() { dforn(i, sz) t[i]=oper(t[2*i], t[2*i+1]);}
    tipo get(int i, int j) { return get(i,j,1,0,sz); }
    tipo get(int i, int j, int n, int a, int b) {
        if (j<=a||b<=i) return neutro;
        if (i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return oper(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
    }
    void set(int p, tipo val) {
        p+=sz;
        while(p>0&&t[p]!=val) {
            t[p] = val;
            p/=2;
            val = oper(t[p*2], t[p*2+1]);
        }
    }
};

#define MAXN 1000100
ll f[MAXN];

void armarFacts(){
    f[0] = 1;
    fr(1,MAXN-5){
        f[i] = (f[i-1] * i) % MOD;
    }
}

void solve() {  
    int n,k; cin >> n  >> k;
    int a[n]; fr(0,n) cin >> a[i];
    map<int,int> m; //cantidades
    fr(0,n){
        m[a[i]]++;
    }
    armarFacts();
    //habria que hacer los inversos de todos ya ? no creo
    ll numerador = 1;
    fre(m){
        if (e.second > 0){
            numerador = (numerador * f[e.second]) % MOD;
        }
    }
    ll denominador = inverso(f[n]);
    cout << (numerador * denominador) % MOD << '\n';
    ST st(n);
    fr(0,n){
        st[i] = mp(a[i],true);
    }
    st.updall();
    fr(0,k){
        int num, val; cin >> num >> val; num--;
        // cout << "numn " << num << endl;
        // cout << "val " << val << endl;
        //tengo numerador, actualizar
        // yo antes tenia * f[a[num]] que eso baja en 1...
        numerador = (numerador * inverso(m[a[num]])) % MOD; //seria mas facil dividir una vez por el ult valor y chau... 
        m[a[num]]--;
        // numerador = (numerador * f[a[num]]) % MOD;
        a[num] = val;
        // numerador = (numerador * inverso(f[a[num]])) % MOD; //en vez de hacer esto y lo otro, seria mas facil solo multiplicar por el nuevo valor... 
        m[a[num]]++;
        numerador = (numerador * m[a[num]]) % MOD;
        //updatear segment!
        st.set(num, mp(val, true));
        cout << (numerador * denominador) % MOD << '\n';
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases=1;
    // cin >> cases;
    while(cases--) {
        solve();
    }
}