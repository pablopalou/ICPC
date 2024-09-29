#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long double T;
typedef long double ld;
const T EPS = 1e-8;
const T INF = 1e10;
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

pair<ld, ld> sq(ld a, ld b, ld c) {
    // roots sum = -b/a
    // roots product = c/a
    pair<ld, ld> p;
    p.first = (-b + sqrtl(b*b - 4*a*c)) / (2*a);
    p.second = (-b - sqrtl(b*b - 4*a*c)) / (2*a);
    return p;
}

ld midX = -1;
pto puntoo;

void solve() {
    ll n; cin >> n; ll m; cin >> m;
    vector<pto> p(n+2);
    fr(0,n){
        cin >> p[i].x;
    }
    fr(0,n){
        cin >> p[i].y;
    }
    ll minX = p[0].x;
    ll maxX = p[n-1].x;
    p[n] = pto(maxX,0);
    p[n+1] = pto(minX,0);
    //agrego los dos puntos al final y calculo el area
    poly pol = poly(p);
    ld area = pol.area();
    ld pedazo = area/m;
    #ifdef JP
		cerr << "Time elapsed after calculating total area: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    int nroPunto = 1;
    fr(0,m-1){
        ld falta = pedazo;
        while(nroPunto < n){
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
        //en vez de hacer la binaria, lo que vamos a hacer es calcular en O(1) a ver que cual es el x en el que vamos a cortar
        
        ld pendiente =(p[nroPunto].y - p[nroPunto-1].y) / (p[nroPunto].x - p[nroPunto-1].x);
        if (pendiente == 0){
            ld x1 = p[nroPunto-1].x;
            ld y4 = p[nroPunto-1].y;
            midX = (falta+x1*y4)/y4;
        } else if (pendiente > 0){
            ld x4 = p[nroPunto-1].x;
            ld x1 = x4;
            ld y1 = 0;
            ld y4 = p[nroPunto-1].y;
            ld x2 = p[nroPunto].x;
            ld x3 = x2;
            ld y2 = 0;
            ld y3 = p[nroPunto].y;
            ld tanTheta = (y3-y2)/(x2-x1);
            ld aa = tanTheta/2.0;
            ld bb = y1;
            ld cc = -falta;
            pair<ld,ld> res = sq(aa,bb,cc);
            res.first += x1;
            res.second += x1;
            if (res.first > x1){
                midX = res.first;
            } else {
                midX = res.second;
            }
        } else {
            ld x4 = p[nroPunto-1].x;
            ld x1 = x4;
            ld y1 = 0;
            ld y4 = p[nroPunto-1].y;
            ld x2 = p[nroPunto].x;
            ld x3 = x2;
            ld y2 = 0;
            ld y3 = p[nroPunto].y;
            ld tanTheta = (y4-y3)/(x2-x1);
            ld aa = -tanTheta/2.0;
            ld bb = y4;
            ld cc = -falta;
            pair<ld,ld> res = sq(aa,bb,cc);
            res.first += x1;
            res.second += x1;
            if (res.first > x1){
                midX = res.first;
            } else {
                midX = res.second;
            }
        }
        line l1 = line(p[nroPunto-1], p[nroPunto]);
        line l2 = line(pto(midX,0), pto(midX,1));
        puntoo = l1.inter(l2);
        //BINARIA
        // ld l = p[nroPunto-1].x;
        // ld r = p[nroPunto].x;
        // int iter = 0;
        // while(iter < 30 && r-l > EPS){
        //     iter++;
        //     midX = l + (r-l)/2;
        //     line l1 = line(p[nroPunto-1], p[nroPunto]);
        //     line l2 = line(pto(midX,0), pto(midX,1));
        //     puntoo = l1.inter(l2);
        //     vector<pto> polyChico(4);
        //     polyChico[0] = pto(p[nroPunto-1].x,0);
        //     polyChico[1] = pto(midX,0);
        //     polyChico[2] = puntoo; //este es la interseccion
        //     polyChico[3] = p[nroPunto-1];
        //     poly curPoly = poly(polyChico);
        //     ld areaChico = curPoly.area(); 
        //     if (areaChico < falta){
        //         l = midX;
        //     } else {
        //         r = midX;
        //     }
        // }
        p[nroPunto-1] = puntoo;
        cout << fixed << setprecision(8) << midX << ' ';
        // #ifdef JP
        //     cerr << "Time elapsed after i =  "<< i  << " => "<<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
        // #endif
    }
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("G.in", "r", stdin);
        // freopen("A.out", "w", stdout);
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