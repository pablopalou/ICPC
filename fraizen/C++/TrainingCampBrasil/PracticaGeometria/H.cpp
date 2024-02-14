#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
// #define cout(x) cout << x << "\n";
#define mod ll(1e9+7)
const ll MAXN = 202;
ll dp[MAXN][MAXN];
ll n;

struct Point {
    ll x,y;
    Point() : x(0), y(0) {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    ll cross(const Point &b) const{
        return x * b.y - y * b.x;
    }
    Point operator-( const Point b) const{ return Point(x-b.x, y-b.y); }
    ll cross2(const Point &b,const  Point &c) const{
        return ((b - *this).cross(c - *this));
    }
};

ll sgn(ll x){
    if (x > 0){
        return 1;
    } else if (x<0){
        return -1;
    }
    return 0;
}

bool areCollinear(Point a, Point b, Point c){
    ll x1 = a.x;
    ll x2 = b.x;
    ll x3 = c.x;
    ll y1 = a.y;
    ll y2 = b.y;
    ll y3 = c.y;
    ll h = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (h == 0){
        return true;
    }
    return false;
}

Point points[MAXN];
bool outsidePoly[MAXN][MAXN];
bool intersectsPoly[MAXN][MAXN];

bool interCollinear(ll a, ll b, ll c, ll d){
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return min(b, d) >= max(a,c);
}

bool intersect(Point a, Point b, Point c, Point d){
    //si estan en la misma linea, me tengo que fijar maximos y minimos
    if (areCollinear(a,b,c) && areCollinear(a,b,d)){
        return interCollinear(a.x, b.x, c.x, d.x) && interCollinear(a.y, b.y, c.y, d.y);
    }
    // if (a.x == 2 && a.y == 0 && b.x == 0 && b.y == 2 && c.x ==0&& c.y==1){
    //     bool h = sgn(a.cross2(b, c)) != sgn(a.cross2(b, d));
    //     bool j = sgn(c.cross2(d, a)) != sgn(c.cross2(d, b));
    //     // cout << "1 => " << h << endl;
    //     // cout << "2 => " << j << endl;
    //     // cout << "total => " << sgn(a.cross2(b, c)) != sgn(a.cross2(b, d)) && sgn(c.cross2(d, a)) != sgn(c.cross2(d, b)) << endl;
    // }
    // caso normal (me fijo si estan cruzados digamos)
    return sgn(a.cross2(b, c)) != sgn(a.cross2(b, d)) && sgn(c.cross2(d, a)) != sgn(c.cross2(d, b));
}

bool polygonIntersect(ll i, ll j){
    if (i == j) return false;
    rep(k,0,n){
        if (k == i || k == j || (k+1)%n == j || (k+1)%n == i) continue;
        //ahora ya tengo los 4 puntos que serian i, j , k y k+1.
        if (intersect(points[i], points[j], points[k], points[(k+1)%n])) return true;
    }
    return false;
}

bool isInsidePolygon(const Point &p) {
    // if (p.x == 0 && p.y == 1){
        // cout << "toy" << endl;
    // }
  const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
  Point ray = {p.x + MOD1, p.y + MOD2};
  bool inside = false;
  fr(0, n) {
    // if (p.x == 0 && p.y == 1 && intersect(points[i], points[(i + 1) % n], p, ray)){
        // cout << "intersecto con el segmento " << i << ' ' << i+1 << endl;
    // }
    inside ^= intersect(points[i], points[(i + 1) % n], p, ray); 
    }
    // if (p.x == 0 && p.y == 1){
        // cout << "inside = " << inside << endl;
    // }
  return inside;
}

bool afuera(ll i, ll j){
    // if (i == 4 && j == 0){
    //     cout << "primer caso" << endl;
    // } else if (j == 4 && i == 0){
    //     cout << "segundo caso" << endl;
    // }
    if (i == j || i + 1 == j || (i + n - 1) % n == j || (j+n-1 % n )== i ) return false;
    // if (i == 4 && j == 0){
    //     cout << "primer caso paso" << endl;
    // } else if (j == 4 && i == 0){
    //     cout << "segundo caso paso" << endl;
    // }
    ll x = (points[i].x + points[j].x) / 2;
    ll y = (points[i].y + points[j].y) / 2;
    // cout << x << ", "<< y <<  endl;
    // if (i == 4 && j == 0){
    //     cout << "primer caso da afuera = "  << !isInsidePolygon({x, y}) << endl;
    // } else if (j == 4 && i == 0){
    //     cout << "segundo caso da afuera = " << !isInsidePolygon({x, y})  << endl;
    // }
    return !isInsidePolygon({x, y});
}

// Copiar obligatoriamente 0
void solve() {
    fr(0,n-1){
        dp[i][i+1] = 1;
    }
    // cout << dp[0][1] << endl;
    // cout << dp[1][2] << endl;
    for(int len = 2; len <= n; len++){
        // for(int i = 0; i<=n-len; i++){
        //     for(int j = i+1; j)
        // }
        rep(i, 0, n-len){
            rep(j, i+1, i+len){ //voy de i a j y de j a i+len.
                // cout << "( " << i << ',' << i+len << " )"<<endl;
                //primero tengo que chequear si es valido
                // if (i == 0 && i+len == 3){
                    // cout << "Probando j =" << j << endl;
                // }
                //si alguno de los dos segmentos nuevos corta al poligono, no se puede y hago continue.
                if (intersectsPoly[i][j] || intersectsPoly[j][i+len]) continue;
                // if (i == 0 && i+len == 3){
                    // cout << "Sigo j =" << j << endl;
                // }
                //si son colineares, no podemos formar el triangulo => continue
                if (areCollinear(points[i], points[j], points[i+len])) {
                    continue;
                }
                // if (i == 0 && i+len == 3){
                    // cout << "Sigox2 j =" << j << endl;
                // }
                // si el punto del medio de la interseccion esta afuera, significa que el segmento esta afuera y continuo
                // if (i == 1 && i+len == 4){
                //     cout << outsidePoly[i][j] << endl;
                // }
                if (outsidePoly[i][j] || outsidePoly[j][i+len]) continue;
                // if (i == 0 && i+len == 3){
                //     // cout << "sigox3 j =" << j << endl;
                //     // cout << "i = " << i << endl;
                //     // cout << "i+len = " << i+len << endl;
                //     // cout << dp[i][j] << endl;
                //     // cout << dp[j][i+len] << endl;
                // }
                dp[i][i+len] = ((dp[i][i+len] % ll(mod) )+  (dp[i][j] % ll(mod) * dp[j][i+len] % ll(mod)) % ll(mod)) % ll(mod);
            }
        }
    }
    // fr(0,n){
    //     rep(j,0,n){
    //         cout << intersectsPoly[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    // dps: 
    // 0 1 0 0 1 2 2 3 3 13 
    // 0 0 1 1 1 1 1 4 0 3 
    // 0 0 0 1 0 0 0 1 0 0 
    // 0 0 0 0 1 0 0 1 1 0 
    // 0 0 0 0 0 1 0 1 1 2 
    // 0 0 0 0 0 0 1 1 1 1 
    // 0 0 0 0 0 0 0 1 1 1 
    // 0 0 0 0 0 0 0 0 1 1 
    // 0 0 0 0 0 0 0 0 0 1 
    // 0 0 0 0 0 0 0 0 0 0 
    // 13
    // dp oficial: 
    // 0 1 1 1 1 2 2 7 27 74 
    // 0 0 1 1 1 1 1 4 13 27 
    // 0 0 0 1 1 0 0 1 5 1 
    // 0 0 0 0 1 1 0 1 4 12 
    // 0 0 0 0 0 1 1 1 3 7 
    // 0 0 0 0 0 0 1 1 2 3 
    // 0 0 0 0 0 0 0 1 1 2 
    // 0 0 0 0 0 0 0 0 1 1 
    // 0 0 0 0 0 0 0 0 0 1 
    // 0 0 0 0 0 0 0 0 0 0 

    // segmentOutsidePoly (solo cambia el de abajo a la izquierda)
    // 0 0 1 1 0 0 0 0 0 0 
    // 0 0 0 0 0 0 0 0 0 0 
    // 1 0 0 0 1 1 1 0 1 1 
    // 1 0 0 0 0 1 1 0 0 1 
    // 0 0 1 0 0 0 1 0 0 0 
    // 0 0 1 1 0 0 0 0 0 0 
    // 0 0 1 1 1 0 0 0 0 0 
    // 0 0 0 0 0 0 0 0 0 0 
    // 0 0 1 0 0 0 0 0 0 0 
    // 0 0 1 1 0 0 0 0 0 0 

    // 0 0 1 1 0 0 0 0 0 0 
    // 0 0 0 0 0 0 0 0 0 0 
    // 1 0 0 0 1 1 1 0 1 1 
    // 1 0 0 0 0 1 1 0 0 1 
    // 0 0 1 0 0 0 1 0 0 0 
    // 0 0 1 1 0 0 0 0 0 0 
    // 0 0 1 1 1 0 0 0 0 0 
    // 0 0 0 0 0 0 0 0 0 0 
    // 0 0 1 0 0 0 0 0 0 0 
    // 1 0 1 1 0 0 0 0 0 0 
    

//      intersects poly
    // 0 0 0 1 0 0 1 0 0 0 
    // 0 0 0 0 0 0 1 1 1 0 
    // 0 0 0 0 0 0 0 0 1 1 
    // 1 0 0 0 0 0 0 0 1 1 
    // 0 0 0 0 0 0 0 0 1 0 
    // 0 0 0 0 0 0 0 0 1 0 
    // 1 1 0 0 0 0 0 0 1 1 
    // 0 1 0 0 0 0 0 0 0 0 
    // 0 1 1 1 1 1 1 0 0 0 
    // 0 0 1 1 0 0 1 0 0 0

//     0 0 0 1 0 0 1 0 0 0 
//     0 0 0 0 0 0 1 0 0 0 
//     0 0 0 0 0 0 0 0 1 1 
//     1 0 0 0 0 0 0 0 0 1 
//     0 0 0 0 0 0 0 0 0 0 
//     0 0 0 0 0 0 0 0 0 0 
//     1 1 0 0 0 0 0 0 0 1 
//     0 0 0 0 0 0 0 0 0 0 
//     0 0 1 0 0 0 0 0 0 0 
//     0 0 1 1 0 0 1 0 0 0
    // cout << dp[1][3] << endl;


    cout << dp[0][n-1] % (ll)mod << "\n";
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

    // int cases = 1;
    // // cin >> cases;
    // while(cases--){
    //     solve();
    // }
    cin >> n;
    fr(0,n){
        Point p; cin >> p.x >> p.y;
        p.x *= 2;
        p.y *= 2; //cosa de que cuando agarre el punto medio, sea siempre par y siga en enteros
        points[i]=p;
    }
    // fr(0,n){
    //     cout << points[i].x << ' ' << points[i].y << endl;
    // }
    //inicializo todas las matrices
    fr(0,n){
        rep(j,0,n){
            outsidePoly[i][j] = false;
        }
    }
    // memset(outsidePoly, false, sizeof(outsidePoly));
    fr(0,n){
        rep(j,0ll,n){
            intersectsPoly[i][j] = polygonIntersect(i,j);
            outsidePoly[i][j] = afuera(i,j);
            // cout << "Seteo outsidePoly de " << i << "," << j << " a = " << outsidePoly[i][j] << endl;
        }
    }
    // cout << "Intersects poly matrix" << endl;
    // fr(0,n){
    //     rep(j,0,n){
    //         cout << intersectsPoly[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "Outside Poly matrix" << endl;
    // fr(0,n){
    //     rep(j,0,n){
    //         cout << outsidePoly[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    //     cout << "yese " << outsidePoly[1][4] << endl;
    memset(dp, 0, sizeof(dp));
    solve();
    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    // cout << "afuera(0,2)" << outsidePoly[0][2] << endl;

    return 0;
}