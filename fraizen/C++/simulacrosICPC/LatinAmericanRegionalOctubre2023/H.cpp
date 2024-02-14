#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
int n;
// Redefine epsilon and infinity as necessary. Be mindful of precision errors.
const long double eps = 1e-9, INF = 1e9;
const int MAXN = 200002;
long double d;
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define pb push_back
// Basic point/vector struct.
// struct Point { 

//     long double x, y;
//     explicit Point(long double x = 0, long double y = 0) : x(x), y(y) {}

//     // Addition, substraction, multiply by constant, dot product, cross product.

//     friend Point operator + (const Point& p, const Point& q) {
//         return Point(p.x + q.x, p.y + q.y); 
//     }

//     friend Point operator - (const Point& p, const Point& q) { 
//         return Point(p.x - q.x, p.y - q.y); 
//     }

//     friend Point operator * (const Point& p, const long double& k) { 
//         return Point(p.x * k, p.y * k); 
//     } 

//     friend long double dot(const Point& p, const Point& q) {
//         return p.x * q.x + p.y * q.y;
//     }

//     friend long double cross(const Point& p, const Point& q) { 
//         return p.x * q.y - p.y * q.x; 
//     }
// };

// // Basic half-plane struct.
// struct Halfplane { 

//     // 'p' is a passing point of the line and 'pq' is the direction vector of the line.
//     Point p, pq; 
//     long double angle;

//     Halfplane() {}
//     Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
//         angle = atan2l(pq.y, pq.x);    
//     }

//     // Check if point 'r' is outside this half-plane. 
//     // Every half-plane allows the region to the LEFT of its line.
//     bool out(const Point& r) { 
//         return cross(pq, r - p) < -eps; 
//     }

//     // Comparator for sorting. 
//     bool operator < (const Halfplane& e) const { 
//         return angle < e.angle;
//     } 

//     // Intersection point of the lines of two half-planes. It is assumed they're never parallel.
//     friend Point inter(const Halfplane& s, const Halfplane& t) {
//         long double alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
//         return s.p + (s.pq * alpha);
//     }
// };



// // Actual algorithm
// vector<Point> hp_intersect(vector<Halfplane>& H) { 

//     Point box[4] = {  // Bounding box in CCW order
//         Point(inf, inf), 
//         Point(-inf, inf), 
//         Point(-inf, -inf), 
//         Point(inf, -inf) 
//     };

//     for(int i = 0; i<4; i++) { // Add bounding box half-planes.
//         Halfplane aux(box[i], box[(i+1) % 4]);
//         H.push_back(aux);
//     }

//     // Sort by angle and start algorithm
//     sort(H.begin(), H.end());
//     deque<Halfplane> dq;
//     int len = 0;
//     for(int i = 0; i < int(H.size()); i++) {

//         // Remove from the back of the deque while last half-plane is redundant
//         while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
//             dq.pop_back();
//             --len;
//         }

//         // Remove from the front of the deque while first half-plane is redundant
//         while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
//             dq.pop_front();
//             --len;
//         }

//         // Special case check: Parallel half-planes
//         if (len > 0 && fabsl(cross(H[i].pq, dq[len-1].pq)) < eps) {
//             // Opposite parallel half-planes that ended up checked against each other.
//             if (dot(H[i].pq, dq[len-1].pq) < 0.0)
//                 return vector<Point>();

//             // Same direction half-plane: keep only the leftmost half-plane.
//             if (H[i].out(dq[len-1].p)) {
//                 dq.pop_back();
//                 --len;
//             }
//             else continue;
//         }

//         // Add new half-plane
//         dq.push_back(H[i]);
//         ++len;
//     }

//     // Final cleanup: Check half-planes at the front against the back and vice-versa
//     while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
//         dq.pop_back();
//         --len;
//     }

//     while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
//         dq.pop_front();
//         --len;
//     }

//     // Report empty intersection if necessary
//     if (len < 3) return vector<Point>();

//     // Reconstruct the convex polygon from the remaining half-planes.
//     vector<Point> ret(len);
//     for(int i = 0; i+1 < len; i++) {
//         ret[i] = inter(dq[i], dq[i+1]);
//     }
//     ret.back() = inter(dq[len-1], dq[0]);
//     return ret;
// }

typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-9; // if T is integer, set to 0
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b){ return pto(x+b.x, y+b.y); }
	pto operator-(pto b) const{ return pto(x-b.x, y-b.y); }
	pto operator+(T k){ return pto(x+k, y+k); }
	pto operator*(T k){ return pto(x*k, y*k); }
	pto operator/(T k){ return pto(x/k, y/k); }
	// dot product
	T operator*(pto b){ return x*b.x+y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b){ return x*b.y-y*b.x; }
	// vector projection of this above b
	pto proj(pto b) { return b*((*this)*b)/(b*b); }
	T norm_sq(){ return x*x+y*y; }
	ld norm(){ return sqrtl(x*x+y*y); }
	ld dist(pto b){ return (b-(*this)).norm(); }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T theta) { 
		return pto(x*cosl(theta)-y*sinl(theta),x*sinl(theta)+y*cosl(theta));
	}
	// true if this is at the left side of line ab
	bool left(pto a, pto b){return ((a-*this)^(b-*this))>0;}
	bool operator<(const pto &b) const {
		return x<b.x-EPS || (abs(x-b.x)<=EPS && y<b.y-EPS);
	}
	bool operator==(pto b){return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS;}
};
ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}
ld angle(pto a, pto b) { // smallest angle bewteen a and b
	ld cost = (a*b) / a.norm() / b.norm();
	return acosl(max(ld(-1.), min(ld(1.), cost)));
}

struct halfplane { // left half plane
	pto u, uv;
	int id;
	ld angle;
	halfplane(){}
	halfplane(pto u_, pto v_): u(u_), uv(v_-u_), angle(atan2l(uv.y,uv.x)) {}
	bool operator<(halfplane h) const { return angle < h.angle; }
	bool out(pto p) {
		return (uv^(p-u)) < -EPS; 
	}
	pto inter(halfplane& h) {
        T alpha = ((h.u-u)^h.uv) / (uv^h.uv);
        return u + (uv * alpha);
    }
};
halfplane hp[MAXN];
vector<pto> intersect(vector<halfplane> h) {
	pto box[4] = {{INF,INF}, {-INF,INF}, {-INF,-INF}, {INF,-INF}};
	forn(i,4) h.pb(halfplane(box[i], box[(i+1)%4]));
	sort(h.begin(), h.end());
	deque<halfplane> dq;
	int len = 0;
	forn(i,sz(h)) {
		while(len>1&&h[i].out(dq[len-1].inter(dq[len-2]))){dq.pop_back();len--;}
		while(len>1 && h[i].out(dq[0].inter(dq[1]))) { dq.pop_front(); len--; }
		if(len>0 && abs(h[i].uv^dq[len-1].uv) <= EPS) {
			if(h[i].uv*dq[len-1].uv < 0.) {
				return vector<pto>();
			}
			if(h[i].out(dq[len-1].u)) { dq.pop_back(); len--; } 
            else continue;
		}
		dq.pb(h[i]);
		len++;
	}
	while(len>2 && dq[0].out(dq[len-1].inter(dq[len-2]))){dq.pop_back(); len--;}
	while(len>2 && dq[len-1].out(dq[0].inter(dq[1]))) { dq.pop_front(); len--; }
	if(len<3) return vector<pto>();
	vector<pto> inter;
	forn(i,len) inter.pb(dq[i].inter(dq[(i+1)%len]));
	return inter;
}

long double dist(long double x, long double y){
    return sqrt(x*x  + y * y);
}

halfplane ensureOriginOnGoodSide(const pto& A, const pto& B) {
    pto O(0, 0); // Origin
    // Vector AB
    pto AB = B - A;
    // Vector AO
    pto AO = O - A;
    // Check side using cross product
    if ((AB^AO)< 0) {
        // If cross product is negative, (0,0) is on the right side, reverse the half-plane
        return halfplane(B, A); // Swap A and B
    } else {
        // Otherwise, keep as is
        return halfplane(A, B);
    }
}

bool puedoEscapar(int mid){ //devuelvo true si puede escapar del circulo usando de 0 hasta mid planos (inclusive)...
    vector<halfplane> halfplane(mid+1);
    fr(0,mid+1){
        halfplane[i] = hp[i];
        // cout << halfplane[i].u.x << ' ' << halfplane[i].u.y << halfplane[i].uv.x << ' ' << halfplane[i].uv.y << endl;
    }
    vector<pto> points = intersect(halfplane);
    fre(points){
        if (dist(e.x, e.y) >= d - eps){
            return true;
        }
    }
    return false;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n; cin >> d;
    fr(0,n){
        pto p1,p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;
        hp[i] = ensureOriginOnGoodSide(p1,p2);
    }
    int l,r; l = 0; r = n-1;
    int ans = 1e9;
    while(l <= r){
        int mid = l + (r - l) / 2;
        // cout << "l  = " << l << "  r = " << r <<endl;
        // cout << "Pruebo mid = " << mid << endl;
        if (puedoEscapar(mid)){ //mid ta bien, significa que puedo salir del circulo, puedo agregar mas intersecciones
            l = mid + 1;
            // cout << "puedo escapar" << endl;
        } else {
            ans = mid;
            // cout << "ans = " << ans << endl;
            r = mid-1;
            // cout << "NO puedo escapar" << endl;
        }
    }
    if (ans == 1e9){
        cout << "*\n";return;
    }
    cout << ans+1 << "\n";
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