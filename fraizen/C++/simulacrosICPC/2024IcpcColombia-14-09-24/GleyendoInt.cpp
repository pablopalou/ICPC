#include <bits/stdc++.h>
using namespace std;
typedef int32_t ll;
typedef long double T;
typedef double ld;
const T EPS = 1e-9;
const T INF = 1e18;
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define sqr(a) ((a)*(a))


struct pto{
    T x,y;
    pto() : x(0), y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    T operator^(pto b) { return x*b.y - y*b.x; }
    pto operator/(T k) { return pto(x/k, y/k); }
    pto operator+(pto b) { return pto(x+b.x, y+b.y); }
    pto operator*(T k) { return pto(x*k, y*k); }
};
struct line {
    T a, b, c;
    line() {}
    line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a * u.x + b * u.y) {}
    pto inter(line v) {
        T det = a * v.b - v.a * b;
        if (abs(det) <= EPS) return pto(INF, INF);
        return pto(v.b * c - b * v.c, a * v.c - v.a * c) / det;
    }
};

struct circle{
    pto o; T r;
    circle(){}
    vector<pto> inter(line l) {
        ld a = l.a, b = l.b, c = l.c - l.a*o.x - l.b*o.y;
        pto xy0 = pto(a*c/(a*a+b*b), b*c/(a*a+b*b));
        if (c*c>r*r*(a*a+b*b)+EPS) {
            return {};
        } else if (abs(c*c-r*r*(a*a+b*b)) < EPS) {
            return {xy0+o};
        } else {
            ld m = sqrtl((r*r-c*c/(a*a+b*b))/(a*a + b*b));
            pto p1 = xy0 + (pto(-b,a)*m);
            pto p2 = xy0 + (pto(b,-a)*m);
            return {p1+o, p2+o};
        }
    }
};
struct poly {
    vector<pto> pt;
    poly(){}
    poly(vector<pto> pt_) : pt(pt_) {}
    ld area() {
        ld area = 0;
        forn(i, sz(pt)) area += pt[i]^pt[(i+1)%sz(pt)];
        return abs(area)/ld(2);
    }
};
ld midX = -1;
pto puntoo;

void solve() {
    ll n; cin >> n; ll m; cin >> m;
    int px[n];
    int py[n];
    fr(0,n){
        cin >> px[i];
    }
    fr(0,n){
        cin >> py[i];
    }
    vector<pto> p(n+2);
    fr(0,n){
        p[i] = pto(px[i],py[i]);
    }
    ll minX = p[0].x;
    ll maxX = p[n-1].x;
    p[n] = pto(maxX,0);
    p[n+1] = pto(minX,0);
    //agrego los dos puntos al final y calculo el area
    poly pol = poly(p);
    ld area = pol.area();
    ld pedazo = area/m;

    int nroPunto = 1;
    fr(0,m-1){
        ld falta = pedazo;
        //me fijo el area al proximo punto. 
        while(true){
            vector<pto> polyChico(4);
            polyChico[0] = pto(p[nroPunto-1].x,0);
            polyChico[1] = pto(p[nroPunto].x,0);
            polyChico[2] = p[nroPunto];
            polyChico[3] = p[nroPunto-1];
            poly curPoly = poly(polyChico);
            ld areaChico = curPoly.area(); 
            if (falta > areaChico){
                falta -= areaChico;
                nroPunto++;
            } else {
                break;
            }
        }
        //ahora se supone que ya estoy pa hacer la ternaria. En nroPunto tengo la derecha y en nroPunto-1 la izquierda.
        ld l = p[nroPunto-1].x;
        ld r = p[nroPunto].x;
        //es binaria no ternaria pajero
        //inter de rectas capaz anda ? en vez de meter al circulo...
        int iter = 0;
        while(iter < 30){
            iter++;
            //hago linea recta (necesito inciializarla 2 puntos)
            midX = l + (r-l)/2;
            line l1 = line(p[nroPunto-1], p[nroPunto]);
            line l2 = line(pto(midX,0), pto(midX,1));
            puntoo = l1.inter(l2);
            //chequeo el area: 
            vector<pto> polyChico(4);
            polyChico[0] = pto(p[nroPunto-1].x,0);
            polyChico[1] = pto(midX,0);
            polyChico[2] = puntoo; //este es la interseccion
            polyChico[3] = p[nroPunto-1];
            poly curPoly = poly(polyChico);
            ld areaChico = curPoly.area(); 
            if (areaChico < falta){
                l = midX;
            } else {
                r = midX;
            }
        }
        p[nroPunto-1] = puntoo;
        //AHORA TENGO QUE EMPEZAR EN MIDX OJO
        cout << fixed << setprecision(12) << midX << ' ';
    }
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}