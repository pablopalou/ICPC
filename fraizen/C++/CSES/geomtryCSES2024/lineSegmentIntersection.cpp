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

typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-16; // if T is integer, set to 0
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

int sgn(T x) { return x < 0 ? -1 : !!x; }
struct line {
  T a, b, c;  // Ax+By=C
  line() {}
  line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
  // TO DO: check negative C (multiply everything by -1)
  line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a * u.x + b * u.y) {}
  int side(pto v) { return sgn(a * v.x + b * v.y - c); }
  bool inside(pto v) { return abs(a * v.x + b * v.y - c) <= EPS; }
  bool parallel(line v) { return abs(a * v.b - v.a * b) <= EPS; }
  pto inter(line v) {
    T det = a * v.b - v.a * b;
    if (abs(det) <= EPS) return pto(INF, INF);
    return pto(v.b * c - b * v.c, a * v.c - v.a * c) / det;
  }
};
struct segm {
  pto s, e;
  segm(pto s_, pto e_) : s(s_), e(e_) {}
  pto closest(pto b) {
    pto bs = b - s, es = e - s;
    ld l = es * es;
    if (abs(l) <= EPS) return s;
    ld t = (bs * es) / l;
    if (t < 0.) return s;       // comment for lines
    else if (t > 1.) return e;  // comment for lines
    return s + (es * t);
  }
  bool inside(pto b) { return abs(s.dist(b) + e.dist(b) - s.dist(e)) < EPS; }
  pto inter(segm b) {  // if a and b are collinear, returns one point
    if ((*this).inside(b.s)) return b.s;
    if ((*this).inside(b.e)) return b.e;
    pto in = line(s, e).inter(line(b.s, b.e));
    if ((*this).inside(in) && b.inside(in)) return in;
    return pto(INF, INF);
  }
};

void solve() {
    pto p[4];
    fr(0,4){
        cin >> p[i].x >> p[i].y;
        // cout << p[i].x << ' ' << p[i].y << endl;
    }
    pto interseccion = segm(p[0], p[1]).inter(segm(p[2],p[3]));
    // cout << interseccion.x << " " << interseccion.y << endl;
    if (interseccion.x == INF){
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}