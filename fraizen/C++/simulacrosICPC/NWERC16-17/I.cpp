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
const T EPS = 1e-9; // if T is integer, set to 0
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
	// T operator^(pto b) { return x*b.y - y*b.x; }
	// // vector projection of this above b
	// pto proj(pto b) { return b*((*this)*b) / (b*b); }
	// T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	// pto rotate(T ang) {
	// 	return pto(x*cosl(ang) - y*sinl(ang), x*sinl(ang) + y*cosl(ang));
	// }
	// true if this is at the left side of line ab
	// bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};

struct segm {
  pto s, e;
  segm() : s(pto()), e(pto()) {}
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
};

#define MAXN 200
ld res;
int n,m,k;
pto p[MAXN];
segm seg[MAXN];

void fraizen(int izq, int i){
    pto cerquita = seg[(izq)%n].closest(p[i%n]);
    res = min(res, cerquita.dist(p[i%n]));
}

void solve() {
    cin >> n >> m >>k; fr(0,n){ cin >> p[i].x >> p[i].y;}
    if ((m + k != n + 2 )and (m + k != n + 3 ) and (m + k != n + 4 )){cout << "-1\n"; return;}
    res = 10000;
    fr(0,n) seg[i] = segm(p[i], p[(i+1)%n]);
    pto cerca;
    if (m+k == n+2){ //caso vertice vertice
        fr(0,n){
            res = min(res, p[i].dist(p[(i+m-1)%n]));
            res = min(res, p[i].dist(p[(i+k-1)%n]));
        }
    } else if ( m+k == n+3){//caso vertice segmento
        fr(0,n){
            fraizen(i+m-2, i);
            fraizen(i+k-2,i);
        }
    } else { //caso segmento segmento
        fr(0,n){ //veo cada segmento
            fraizen(i+m-2, i);
            fraizen(i+m-2, i+1);
            fraizen(i, i+m-2);
            fraizen(i, i+m-1);
            fraizen(i+k-2,i);
            fraizen(i+k-2,i+1);
            fraizen(i, i+k-2);
            fraizen(i, i+k-1);
        }
    }
    cout << fixed << setprecision(10) << res << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // #ifdef JP
    //     freopen("A.in", "r", stdin);
    //     freopen("A.out", "w", stdout);
	// #endif
        freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

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