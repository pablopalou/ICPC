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
#define inf 1e9
#define mp make_pair

//SEGMENT TREE LAZY
typedef pair<ll,ll> Elem;
typedef ll Alt; //en lo que altero siempre es un long long
const Elem neutro = mp(-inf, inf); //tambien guardo el indice como segundo parametro
const Alt neutro2 = 0;
Elem oper(const Elem& a, const Elem& b) { return max(a,b); }
struct ST2 {
  int sz;
  vector<Elem> t;
  vector<Alt> dirty;  // Alt and Elem could be different types
  ST2(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<Elem>(2 * sz, neutro);
    dirty = vector<Alt>(2 * sz, neutro2);
  }
  Elem& operator[](int p) { return t[sz + p]; }
  void updall() { dforn(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  void push(int n, int a, int b) {  // push dirt to n's child nodes
    if (dirty[n] != neutro2) {      // n = node of range [a,b)
      t[n].first += dirty[n];   // CHANGE for your problem
      if (n < sz) {
        dirty[2 * n] += dirty[n];      // CHANGE for your problem
        dirty[2 * n + 1] += dirty[n];  // CHANGE for your problem
      }
      dirty[n] = neutro2;
    }
  }
  Elem get(int i, int j, int n, int a, int b) {  // O(lgn)
    if (j <= a || b <= i) return neutro;
    push(n, a, b);                      // adjust value before using it
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  Elem get(int i, int j) { return get(i, j, 1, 0, sz); }
  // altera los valores en [i, j) con una alteracion de val
  void update(Alt val, int i, int j, int n, int a, int b) {  // O(lgn)
    push(n, a, b);
    if (j <= a || b <= i) return;
    if (i <= a && b <= j) {
      dirty[n] += val;  // CHANGE for your problem
      push(n, a, b);
      return;
    }
    int c = (a + b) / 2;
    update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
    t[n] = oper(t[2 * n], t[2 * n + 1]);
  }
  void update(Alt val, int i, int j) { update(val, i, j, 1, 0, sz); }
};  // Use: definir operacion, neutros, Alt, Elem, uso de dirty
// cin >> n; ST st(n); forn(i,n) cin >> st[i]; st.updall()

//SEGMENT TREE NORMAL
typedef pair<ll,ll> tipito;
const tipito realNeutro = mp(inf, inf);
tipito oper2(const tipito& a, const tipito& b) { return min(a,b); }
struct ST {
  int sz;
  vector<tipito> t;
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<tipito>(2 * sz, realNeutro);
  }
  tipito& operator[](int p) { return t[sz + p]; }
  void updall() { dforn(i, sz) t[i] = oper2(t[2 * i], t[2 * i + 1]); }
  tipito get(int i, int j) { return get(i, j, 1, 0, sz); }
  tipito get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
    if (j <= a || b <= i) return realNeutro;
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper2(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  void set(int p, tipito val) {  // O(log n)
    p += sz;
    while (p > 0 && t[p] != val) {
      t[p] = val;
      p /= 2;
      val = oper2(t[p * 2], t[p * 2 + 1]);
    }
  }
};  // Use: definir oper tipito neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

void solve() {
    ll n,k; cin >> n >> k;
    ll v[n], c[n], p[n];
    fr(0,n) cin >> v[i]; //Ganancia por Vender en el pais i
    fr(0,n) cin >> c[i]; //Maximo de globos sin impuestos
    fr(0,n) cin >> p[i]; //Impuesto por globo extra
    //llevo dos segment tree. El primero uno normal, de minimo. Este es para saber cuantos globos puedo llevar hasta i.
    //El otro segment es para mantener los precios, donde me interesa el maximo y decrementar desde el minimo hacia la derecha, en lo que vale el impuesto del minimo.
    //suponete que tengo el maximo en 4, que tiene precio 15 y a la izquierda en un momento el minimo es 2 globos sin impuestos. Entonces si o si me conviene
    //pasar 2 globos a ese maximo valor, y luego desde la posicion donde esta ese minimo hacia la derecha, si o si tengo que pagar el impuesto dle minimo, entonces
    //ese rango desde el minimo todo hacia la derecha, le decremento el precio en ese impuesto. 
    //st de minima cantidad de globos que puedo pasar (tmb me interesa saber el indice del minimo, entonces lo guardo)
    ST st1(n);
    fr(0,n){
        st1[i] = mp(c[i], i);
    }
    st1.updall();
    ST2 st2(n); //este es pa las ventas (maximos)
    fr(0,n){
        st2[i] = mp(v[i], -i);
    }
    st2.updall();
    ll ans = 0;
    int cantVendido = 0;
    while(k > 0 && st2.get(0,n).first > 0){
        pair<ll,ll> venta = st2.get(0,n);
        ll precioVenta = venta.first;
        ll index2 = -venta.second;
        pair<ll,ll> query1 = st1.get(0,index2+1); //vendo cantGlobos
        ll cantGlobos = min(k, query1.first-cantVendido);
        cantVendido += cantGlobos;
        ll index1 = query1.second;
        ans += cantGlobos * precioVenta;
        st1.set(index1, mp(inf,index1));
        st2.update(-p[index1], index1, n);
        k-=cantGlobos;
        // cout << endl;
    }
    cout << ans << '\n';
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