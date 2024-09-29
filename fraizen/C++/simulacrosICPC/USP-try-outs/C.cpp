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
#define mp make_pair

//copiado y pegado
// typedef pair<ll,ll> tipo;
// const tipo neutro = mp(0,0);
// tipo oper(const tipo& a, const tipo& b) { return mp(a.first + b.first, min(a.second, b.second + a.first));}
// struct ST {
//   int sz;
//   vector<tipo> t;
//   ST(int n) {
//     sz = 1 << (32 - __builtin_clz(n));
//     t = vector<tipo>(2 * sz, neutro);
//   }
//   tipo& operator[](int p) { return t[sz + p]; }
//   void updall() { dforn(i, sz) t[i] = oper(t[2 * i], t[2 * i + 1]); }
//   tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
//   tipo get(int i, int j, int n, int a, int b) {  // O(log n), [i, j)
//     if (j <= a || b <= i) return neutro;
//     if (i <= a && b <= j) return t[n];  // n = node of range [a,b)
//     int c = (a + b) / 2;
//     return oper(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
//   }
//   void set(int p, tipo val) {  // O(log n)
//     p += sz;
//     while (p > 0 && t[p] != val) {
//       t[p] = val;
//       p /= 2;
//       val = oper(t[p * 2], t[p * 2 + 1]);
//     }
//   }
// };  // Use: definir oper tipo neutro,
// // cin >> n; ST st(n); forn(i, n) cin >> st[i]; st.updall();

typedef pair<ll,ll> tipo;
const tipo neutro = mp(0,0);
tipo oper(const tipo& a, const tipo& b){return mp(a.first + b.first, min(a.second, b.second + a.first));}
struct ST {
    int sz;
    vector<tipo> t;
    ST(int n){
        sz = 1 << (32-__builtin_clz(n));
        t = vector<tipo>(2*sz, neutro);
    }
    tipo& operator[](int p){return t[sz+p];}
    void updall() {dforn(i,sz) t[i] = oper(t[2*i],t[2*i+1]);}
    tipo get(int i, int j) {return get(i,j,1,0,sz);}
    tipo get(int i, int j, int n, int a, int b){
        if (j<=a || b<=i) return neutro;
        if (i<=a && b<=j) return t[n];
        int c = (a+b)/2;
        return oper(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
    }
    void set(int p, tipo val){
        p+=sz;
        while(p>0 && t[p]!=val){
            t[p] = val;
            p/=2;
            val = oper(t[p*2],t[p*2+1]);
        }
    }
};

void solve() {
    ll n,q; cin >> n >> q;
    ll b[n];
    ll c[n];
    fr(0,n) cin >> b[i]; fr(0,n) cin >> c[i];
    ll d[n]; fr(0,n) d[i] = b[i]-c[i];
    ST st = ST(2*n+6);
    fr(0,n){
        st[i] = mp(d[i],d[i]);
        st[i+n] = mp(d[i],d[i]);
    }
    st.updall();
    fr(0,q){
        ll type; cin >> type;
        if (type == 1){
            ll num; cin >> num; num--;
            //hacer binaria pa responder
            ll l = 1;
            ll r = n+4;
            ll res = 0;
            if (d[num] < 0){
                cout << num+1 << '\n';
                continue;
            }
            while(l <= r){
                ll mid = l + (r-l)/2;
                // cout << "pregunto por mid = " << mid << endl;
                if (st.get(num, num + mid).second >= 0){
                    res = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            // cout << "num = " << num << endl;
            // cout << "res = " << res << endl;
            // cout << "L = " << l << endl;
            if (l >= n+1){
                cout << "-1\n";
            } else {
                cout << (num + res) % n + 1 << '\n';
            }
        } else if (type == 2){
            //leer dos y actualizar
            ll num,val; cin >> num >> val; num--;
            b[num] = val;
            d[num] = b[num]-c[num];
            st.set(num, mp(d[num], d[num]));
            st.set(num+n, mp(d[num], d[num]));
        } else {
            //leer dos y actualizar
            ll num,val; cin >> num >> val; num--;
            c[num] = val;
            d[num] = b[num]-c[num];
            st.set(num, mp(d[num], d[num]));
            st.set(num+n, mp(d[num], d[num]));
        }
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
