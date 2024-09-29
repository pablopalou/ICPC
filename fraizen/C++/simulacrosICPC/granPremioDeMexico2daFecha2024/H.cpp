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

typedef ll tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return a + b; }
struct ST {
  int sz;
  vector<tipo> t;
  ST(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    t = vector<tipo>(2 * sz, neutro);
  }
  tipo& operator[](int p) { return t[sz + p]; }
  void updall() { dforn(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
  tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
  tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
    if (j <= a || b <= i) return neutro;
    if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
    int c = (a + b) / 2;
    return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  void set(int p, tipo val) {  // O(log n)
    p += sz;
    while (p > 0 && t[p] != val) {
      t[p] = val;
      p /= 2;
      val = oper(t[p * 2], t[p * 2 + 1]);
    }
  }
};  // Use: definir oper tipo neutro,
// cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();
#define MAXN 10004
ST st(2*MAXN);
bool usados[MAXN]; 
int n; 

int binaria(int inicio, int mov, bool sumo){
    int tengo, quiero, l, r, ans; ans = -1;
    // cout << st.get(0,MAXN-1) << endl;
    if (sumo){
        tengo = st.get(0,inicio+1);
        quiero = tengo + mov;
        // cout << "tengo = " << tengo << endl;
        // cout << "quero = " << quiero << endl;
        l = 0;
        r = 2*n;
        while(l<r){
            int mid = l + (r-l)/2;
            // cout << "Pruebo mid = " << mid << endl;
            int resQuery = st.get(0,mid);
            // cout << "query = " << resQuery << endl;
            if (resQuery > quiero){
                r = mid;
            } else if (resQuery == quiero){ //me muevo mas a la IZQ
                ans = mid-1;
                r = mid;
            } else {
                l = mid+1;
            }
        }
    } else {
        tengo = st.get(0,inicio+n+1);
        quiero = tengo - mov;
        // cout << "tengo = " << tengo << endl;
        // cout << "quero = " << quiero << endl;
        l = 0;
        r = 2*n;
        while(l<r){
            int mid = l + (r-l)/2;
            //  cout << "Pruebo mid = " << mid << endl;
            int resQuery = st.get(0,mid);
            // cout << "query = " << resQuery << endl;
            if (resQuery > quiero){
                r = mid;
            } else if (resQuery == quiero){ //me muevo mas a la derecha
                ans = mid-1;
                r = mid;
            } else {
                l = mid+1;
            }
        }
    }

    // if (ans == -1){
    //     cout << "PROBLEMON\n";
    // } 
    if (ans >= n){
        ans-=n;
    }
    // cout << "respondo ans " << ans << endl << endl;
    return ans; 
}

void solve() {
    int r, c; cin >> n >> r >> c; r--; c--;
    fr(0,2*n){
        st[i] = 1;
    }
    fr(2*n, MAXN-1){
        st[i] = 0;
    }
    st.updall();
    vector<int> res;
    int s1 = 0;
    int s2 = n-1;
    fr(0,MAXN-1) usados[i] = false;
    
    int cantTotal = st.get(0,2*n);
    // cout << "cant total " << cantTotal << endl;

    while(cantTotal > 4){
        // cout << "CANT TOTAL = " << cantTotal << endl;
        int cant = cantTotal/2;
        int ter1, ter2;
        // cout << "quiero moverme r " << r << endl;
        int rFraizen = r;
        rFraizen %= cant;
        // cout << "R = " << rFraizen << endl;
        if (rFraizen == 0){
            ter1 = s1;
        } else {
            ter1 = binaria(s1, rFraizen, true);
        }
        //muevo el s2 c veces (arrancarlo en +n OJO) //OJO  => RESTARLE N 
        int cFraizen = c;
        cFraizen%=cant;
        if (cFraizen == 0){
            ter2 = s2;
        } else {
            ter2 = binaria(s2, cFraizen, false);
        }

        if (ter1 == ter2){
            //pongo en 0 el segment tree ter1 y ter1+n
            // cout << "Terminaron los dos supervisores en " << ter1+1 << endl;
            st.set(ter1, 0); st.set(ter1+n, 0);
            usados[ter1] = true;
            res.pb(ter1);
        } else {
            // cout << "Supervisor 1 termino en " << ter1+1 << endl;
            // cout << "Supervisor 2 termino en " << ter2+1 << endl;
            usados[ter1] = true;
            usados[ter2] = true;
            st.set(ter1, 0); st.set(ter1+n, 0);
            st.set(ter2, 0); st.set(ter2+n, 0);
        }

        s1 = ter1;
        s2 = ter2;
        s1 = binaria(s1, 1, true);
        s2 = binaria(s2, 0, false);
        cantTotal = st.get(0,2*n);
        // cout << "s1 = " << s1+1 << endl;
        // cout << "s2 = " << s2+1 << endl;
    }
    //esto debe estar bien
    //si me quedan solo 2 o menos, simplemente los agrego a la respuesta
    fr(0,n){
        if (!usados[i]){
            res.pb(i);
        }
    }
    sort(res.begin(), res.end());
    fre(res){
        cout << e+1 << ' ';
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