#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=0; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1, i>=0; i--)
#define sz(c) ((int)c.size())
#define forall(it, v) for(auto it=v.begin(); it != v.end(); it++)
#define sqr(a) ((a) * (a))


typedef long double T;
typedef long double ld;
const T EPS = 1e-9;
const T INF = 1e18;
struct pto{
    T x,y;
    pto() : x(0),  y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator-(pto b ){ return pto(x-b.x, y-b.y);}
    pto operator+(pto b ){ return pto(x+b.x, y+b.y);}
    pto operator*(T k) { return pto(x*k,y*k);}
    pto operator/(T k) { return pto(x/k,y/k);}
    T operator*(pto(b)) { return x*b.x + y*b.y;}
    ld norm() { return sqrtl(x*x + y*y);}
    ld dist(pto b) { return (b - (*this)).norm();}
    T norm_sq(){return x*x + y * y;}
};




int sgn( T x){ return x < 0 ? -1: !!x;}
struct line{
    T a,b,c;
    line() {}
    line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
    line(pto u, pto v) : a(v.y - u.y), b(u.x - v.x), c(a*u.x + b*u.y){}
    int side(pto v) { return sgn(a*v.x + b*v.y -c);}
    bool inside(pto v) {return abs(a*v.x + b*v.y -c) <= EPS;}
    bool parallel(line v) { return abs(a*v.b-v.a*b) <= EPS;}
    pto inter(line v){
        T det = a*v.b - v.a*b;
        if(abs(det) <= EPS) return pto(INF, INF);
        return pto(v.b*c - b*v.c, a*v.c - v.a*c) / det;
    }
};
pto perp(pto a){return pto(-a.y, a.x);}
line bisector(pto a, pto b){
    line l = line(a,b); pto m = (a+b)/2;
    return line(-l.b, l.a, -l.b*m.x + l.a*m.y);
}

line bisector(const line& l1, const line& l2, bool interior) {
    // Ensure the lines are not parallel
    assert(l1.a * l2.b != l2.a * l1.b);
    
    double sign = interior ? 1 : -1;
    // Calculate the lengths of the direction vectors
    double len1 = sqrt(l1.a * l1.a + l1.b * l1.b);
    double len2 = sqrt(l2.a * l2.a + l2.b * l2.b);
    
    // Compute the weighted direction and offset for the bisector
    double a = l2.a / len2 + sign * l1.a / len1;
    double b = l2.b / len2 + sign * l1.b / len1;
    double c = l2.c / len2 + sign * l1.c / len1;
    
    // Normalize the direction of the bisector
    double len = sqrt(a * a + b * b);
    a /= len;
    b /= len;
    c /= len;
    
    return line(a,b,c);
}

struct circle{
    pto o; T r;
    circle(){}
    circle(pto a, pto b, pto c){
        o = bisector(a,b).inter(bisector(b,c));
        r = o.dist(a);
    }
    vector<pto> inter(line l){
        ld a= l.a, b = l.b, c = l.c - l.a * o.x - l.b*o.y;
        pto xy0 = pto(a*c/ (a*a + b*b), b*c/(a*a + b*b));
                    vector<pto> vp;
        if (c*c > r*r*(a*a + b*b) + EPS){
            return vp;
        } else if (abs(c*c - r*r*(a * a + b*b)) < EPS){
            vp.push_back(xy0 + o);
            return vp;
        } else {
            ld m = sqrtl((r*r - c*c/ (a*a + b*b))/(a*a + b*b));
            pto p1 = xy0 + (pto(-b,a) * m );
            pto p2 = xy0 + (pto(b, -a) * m);
            vp.push_back(p1 + o);
            vp.push_back(p2 + o);
            return vp;
            // return { , p2 + o};
        }
    }
    circle* circle2PtoR(pto a, pto b, T r_){
        ld d2 = (a-b).norm_sq(), det = r_*r_/d2 - ld(0.25);
        if (det < 0) return nullptr;
        circle *ret = new circle();
        ret->o = (a+b)/ld(2) + perp(b-a)*sqrt(det);
        ret->r = r_;
        return ret;
    }
};


void solve(){
    int xa,ya,xb,yb,xc,yc,r;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> r;
    pto a = pto(xa,ya);
    pto b = pto(xb,yb);
    pto centro = pto(xc, yc);
    circle* c = new circle();
    pto circ1 = pto(centro.x + r, centro.y);
    pto circ2 = pto(centro.x - r, centro.y);
    circle* c2 = c->circle2PtoR(circ1, circ2 , r);
    line linea = line(a, b);
    if (c2->inter(linea).size() >= 1){
        cout << fixed << setprecision(10) << a.dist(b) << "\n"; 
        return;
    }
    pto medioAB = (a + b )/ 2;
    line bis = line(centro , medioAB);
    vector<pto> puntos = c2->inter(bis);
    ld res = puntos[0].dist(a) +  puntos[0].dist(b);
    if (puntos.size() > 1){
        res = min(res, puntos[1].dist(a) + puntos[1].dist(b));
    }
    //intersecto a con el centro y b con el centro
    line lineaA = line(centro, a);
    line lineaB = line(centro, b);
    vector<pto> ptosA = c2->inter(lineaA);
    vector<pto> ptosB = c2->inter(lineaB);
    fr(0,ptosA.size()){
        rep(j, 0, ptosB.size()){
            pto puntoMedio = (ptosA[i] + ptosB[i]) / 2;
            line lineaF = line(centro, puntoMedio);
            vector<pto> punts = c2->inter(lineaF);
            res = min(res, punts[0].dist(a) +  punts[0].dist(b));
            if (punts.size() > 1){
                res = min(res, punts[1].dist(a) + punts[1].dist(b));
            }
        }
    }
    line bisectriz = bisector(lineaA, lineaB, 1);
    vector<pto> puntosFraizen = c2->inter(bisectriz);
    res = min(res, puntosFraizen[0].dist(a) +  puntosFraizen[0].dist(b));
    if (puntosFraizen.size() > 1){
        res = min(res, puntosFraizen[1].dist(a) + puntosFraizen[1].dist(b));
    }
    cout << fixed << setprecision(10) << res << "\n"; 

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("G.in", "r", stdin);
    #endif

    int cases =1;
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
        cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}

