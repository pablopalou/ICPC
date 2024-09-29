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
	T operator^(pto b) { return x*b.y - y*b.x; }
};

struct poly{
	vector<pto> pt;
	poly(){}
	poly(vector<pto> pt_) : pt(pt_) {}
	bool inside(pto p) { // O(n)  
		bool c = false;
		forn(i, sz(pt)) {
			int j = (i+1)%sz(pt);
			if((pt[j].y>p.y) != (pt[i].y > p.y) && 
			(p.x < (pt[i].x-pt[j].x)*(p.y-pt[j].y)/(pt[i].y-pt[j].y)+pt[j].x))
				c = !c;
		}
		return c;
	}
};

void solve() {
    int n,m; cin >> n >> m; vector<pto> p(n);
    fr(0,n){
        cin >> p[i].x >> p[i].y;
    }
    poly poligono(p);
    fr(0,m){
        pto cur; cin >> cur.x >> cur.y;
        //chequeo manual si es boundary
        bool boundary = false;
        rep(j,0,n){
            int cruz = (p[(j+1)%n]-p[j])^(cur-p[j]);
            if (cruz == 0){
                if (cur.x <= max(p[(j+1)%n].x, p[j].x) && cur.x >= min(p[(j+1)%n].x, p[j].x) && cur.y <= max(p[(j+1)%n].y, p[j].y) && cur.y >= min(p[(j+1)%n].y, p[j].y)){
                    boundary = true;
                    cout << "BOUNDARY\n";
                    break;
                }
            }
        }
        if (boundary) continue;
        if (poligono.inside(cur)){
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
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