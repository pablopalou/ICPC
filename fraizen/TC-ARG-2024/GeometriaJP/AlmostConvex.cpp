//https://codeforces.com/gym/104901/problem/M

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mp make_pair
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

typedef ll T; // double could be faster but less precise
typedef long double ld;
const T EPS = 0; // if T is integer, set to 0
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b) { return x*b.y - y*b.x; }
	// vector projection of this above b
	pto proj(pto b) { return b*((*this)*b) / (b*b); }
	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T ang) {
		return pto(x*cosl(ang) - y*sinl(ang), x*sinl(ang) + y*cosl(ang));
	}
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};
ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}
ld angle(pto a, pto b) { // smallest angle bewteen a and b
	ld cost = (a*b) / a.norm() / b.norm();
	return acosl(max(ld(-1.), min(ld(1.), cost)));
}

// returns convex hull of p in CCW order
// left must return >=0 to delete collinear points
vector<pto> CH(vector<pto>& p) {
  if (sz(p) < 3) return p;  // edge case, keep line or point
  vector<pto> ch;
  sort(p.begin(), p.end());
  forn(i, sz(p)) {  // lower hull
    while (sz(ch) >= 2 && ch[sz(ch) - 1].left(ch[sz(ch) - 2], p[i]))
      ch.pop_back();
    ch.pb(p[i]);
  }
  ch.pop_back();
  int k = sz(ch);
  dforn(i, sz(p)) {  // upper hull
    while (sz(ch) >= k + 2 && ch[sz(ch) - 1].left(ch[sz(ch) - 2], p[i]))
      ch.pop_back();
    ch.pb(p[i]);
  }
  ch.pop_back();
  return ch;
}

// radial sort around point O in CCW direction starting from vector v
struct cmp {
  pto o, v;
  cmp(pto no, pto nv) : o(no), v(nv) {}
  bool half(pto p) {
    assert(!(p.x == 0 && p.y == 0));  // (0,0) isn't well defined @TODO: como lo handleo? al parecer hay que sacar el mismo punto
    //o sea, si estoy parado en 1,5 y mando todos los puntos de vuelta pa ordenar, se rompe, entonces no lo agrego ahi.
    return (v ^ p) < 0 || ((v ^ p) == 0 && (v * p) < 0);
  }
  bool operator()(pto& p1, pto& p2) {
    return mp(half(p1 - o), T(0)) < mp(half(p2 - o), ((p1 - o) ^ (p2 - o)));
  }
};

void solve() {
    int n; cin >> n;
    vector<pto> p(n);
    fr(0,n){
        int x, y; cin >> x >> y;
        p[i] = pto(x,y);
    }
    //aca tengo la convex hull. 
    map<pair<int,int>, int> m;
    vector<pto> hull = CH(p);
    fr(0,hull.size()){
        m[mp(hull[i].x, hull[i].y)] = 1;
    }
    // fre(m){
    //     cout << e.first.first << ", " << e.first.second << "=> " << e.second << endl;
    // }
    ll res = 1;
    //tengo que ver si agregando un punto, queda bien (no queda ninguno afuera).
    //ese punto podria ir consecutivo a cualquier 2 de la convex
    //tirar polar sort de cada punto interior y veo si en el orden, hay dos que pertenezcan a la convex hull
    fr(0,n){
        if (m[mp(p[i].x, p[i].y)] == 0){ //no esta en la convex, tengo que tirar polar sort
            // cout << "No estoy en la convex con " << p[i].x << ' ' << p[i].y << endl;
            //scar el punto del centro
            vector<pto> puntos(n-1);
            int fraizen = 0;
            rep(j,0,n){
                if (!(p[i] == p[j])){
                    puntos[fraizen] = p[j]; 
                    fraizen++;
                }
            }
            // fre(puntos){
            //     cout << e.x << ' ' << e.y << endl;
            // }
            sort(puntos.begin(), puntos.end(), cmp(p[i], pto(1,0)));
            
            // cout << "Puntos ordenados " << endl;
            // fre(puntos){
            //     cout << e.x << " " << e.y << "   mapa=>" << m[mp(e.x, e.y)]<<endl;
            // }
            //ahora ya tengo los puntos ordenados
            rep(j,0,n-1){
                if (m[mp(puntos[j].x, puntos[j].y)] == 1 && m[mp(puntos[(j+1)%(n-1)].x, puntos[(j+1)%(n-1)].y)] == 1){
                    res++;
                }
            }
            // cout << "res ahora = " << res << endl;
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
