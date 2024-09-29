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
#define fst first
#define snd second

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
	pto operator*(T k) { return pto(x*k, y*k); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};
struct line {
  T a, b, c;  // Ax+By=C
  line() {}
  line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a * u.x + b * u.y) {}
};

struct circle{
	pto o; T r;
	circle(){}
	bool inside(pto p) { return (o-p).norm_sq() <= r*r+EPS; }
	vector<pto> inter(line l) {
		ld a = l.a, b = l.b, c = l.c - l.a*o.x - l.b*o.y;
		pto xy0 = pto(a*c/(a*a + b*b), b*c/(a*a + b*b));
		if(c*c > r*r*(a*a + b*b) + EPS) {
			return {};
		}else if(abs(c*c - r*r*(a*a + b*b)) < EPS) {
			return { xy0 + o };
		}else{
			ld m = sqrtl((r*r - c*c/(a*a + b*b))/(a*a + b*b));
			pto p1 = xy0 + (pto(-b,a)*m);
			pto p2 = xy0 + (pto(b,-a)*m);
			return { p1 + o, p2 + o };
		}
	}
};

struct segm {
  pto s, e;
  segm(pto s_, pto e_) : s(s_), e(e_) {}
};

void solve() {
    ld xa,ya,xb,yb,xc,yc,radio; cin >> xa >> ya >> xb >> yb >> xc >> yc >> radio;
    pto a = pto(xa,ya);pto b = pto(xb,yb);
    pto c = pto(xc,yc);
    segm seg = segm(a, b);
    line linee = line(a,b);
    circle cir = circle(); cir.o = c; cir.r = radio;
    ld res = 1e9;
    //si a == b, lo hago aparte
    if (a == b){
        if (cir.inside(a)){
            cout << fixed << setprecision(16) << a.dist(b) << "\n";
        } else {
            //hago la linea desde a hasta el centro e intersecto con el circulo
            line l1 = line(a, c);
            vector<pto> posibles = cir.inter(l1);
            res = posibles[0].dist(a) + posibles[0].dist(b);
            res = min(res, posibles[1].dist(a) + posibles[1].dist(b)); 
            cout << fixed << setprecision(16) << res << "\n";
        }
        return;
    }
    //primero veo si hay puedo ir de A hasta B derecho. Para esto, el segmento debe intersecar con el circulo 
    vector<pto> puntos = cir.inter(linee);
    if (puntos.size() == 2){
        //me fijo si hay al menos 1 adentro del circulo. 
        if (cir.inside(a)){
            cout << fixed << setprecision(16) << a.dist(b) << "\n";
            return;
        }
        if (cir.inside(b)){
            cout << fixed << setprecision(16) << a.dist(b) << "\n";
            return;
        }
        //me tengo que fijar si estan de un mismo lado o no. para esto hago las distancias desde A a ambos puntos y desde B a ambos puntos.
        ld d1 = puntos[0].dist(a); ld d2 = puntos[0].dist(b);
        ld d3 = puntos[1].dist(a); ld d4 = puntos[1].dist(b);
        if ((d1 < d3 && d4 < d2) or (d1 > d3 && d4 > d2)){
            //devuelvo la distancia entre ellos nomas
            cout << fixed << setprecision(16) << a.dist(b) << "\n";
            return;
        }
    }
    //tengo que hacer el segmento a, b y hacer la ternaria ahi
    ld l = 0;
    ld r = a.dist(b);
    int iter = 0;
    while(iter < 100){
        iter++;
        ld mid1 = l + (r-l)/3;
        ld mid2 = l + (r-l)*2.0/3;
        //para encontrar el punto, puedo hacer un circulo con ese radio e intersectar con la linea
        circle cmid1 = circle();
        cmid1.o = a;
        cmid1.r = mid1;
        circle cmid2 = circle();
        cmid2.o = a;
        cmid2.r = mid2;

        //hago el primer punto
        vector<pto> v1 = cmid1.inter(linee);
        pto p1 = v1[0]; //DEBERIA TENER UN SOLO PUNTO SI O SI
        vector<pto> v2 = cmid2.inter(linee);
        pto p2 = v2[0]; 

        //ya tengo los dos puntos. Es cuestion de probar cual esta mejor y actualizar l y r
        ld res1, res2;
        //hago la linea de p1 con el centro del circulo, intersecto con el circulo y veo distancia
        line l1 = line(p1, c);
        vector<pto> posibles = cir.inter(l1);
        res1 = posibles[0].dist(a) + posibles[0].dist(b);
        res1 = min(res1, posibles[1].dist(a) + posibles[1].dist(b)); 

        //lo mismo con p2
        line l2 = line(p2, c);
        posibles = cir.inter(l2);
        res2 = posibles[0].dist(a) + posibles[0].dist(b);
        res2 = min(res2, posibles[1].dist(a) + posibles[1].dist(b)); 

        //falta actualizar l y r

        if (res1 < res2){
            r = mid2;
        } else {
            l = mid1;
        }

        res = min({res, res1, res2});
    }
    cout << fixed << setprecision(16) << res << '\n';
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