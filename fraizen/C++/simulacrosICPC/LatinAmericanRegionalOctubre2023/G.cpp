#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

struct Point{
    int x, y;
    Point(int _x, int _y): x(_x), y(_y) {}
    bool operator<(const Point &b) const {
		return x<b.x || (x == b.x && y<b.y);
	}
    bool operator==(const Point &b) const {
        return x == b.x && y == b.y;
    }
};
struct Segment{
    Point p1, p2;
    Segment(Point _p1, Point _p2): p1(_p1), p2(_p2){}
    bool operator<(const Segment& rhs) {
        if (p1 < rhs.p1) return true;
        if (rhs.p1 < p1) return false;
        return p2 < rhs.p2;
    }
};
struct Square{
    vector<Segment> segmentos;
    Square(){}
    Square(int x, int y, int d){
        int newX = x-y;
        int newY = x+y;
        Point p0 = Point(newX - d, newY -d);
        Point p1 = Point(newX + d, newY -d);
        Point p2 = Point(newX + d, newY +d);
        Point p3 = Point(newX - d, newY +d);
        segmentos.pb(Segment(p0, p1));
        segmentos.pb(Segment(p1, p2));
        segmentos.pb(Segment(p2, p3));
        segmentos.pb(Segment(p3, p0));
    }
};

void intersectSegment(Segment s1, Segment s2, vector<Segment> &ans) {
    // Check for parallel and overlapping segments (vertical)
    if (s1.p1.x == s1.p2.x && s2.p1.x == s2.p2.x && s1.p1.x == s2.p1.x) {
        int start = max(min(s1.p1.y, s1.p2.y), min(s2.p1.y, s2.p2.y));
        int end = min(max(s1.p1.y, s1.p2.y), max(s2.p1.y, s2.p2.y));
        if (start <= end) { // Overlapping
            ans.push_back(Segment(Point(s1.p1.x, start), Point(s1.p1.x, end)));
        }
    } 
    // Check for parallel and overlapping segments (horizontal)
    else if (s1.p1.y == s1.p2.y && s2.p1.y == s2.p2.y && s1.p1.y == s2.p1.y) {
        int start = max(min(s1.p1.x, s1.p2.x), min(s2.p1.x, s2.p2.x));
        int end = min(max(s1.p1.x, s1.p2.x), max(s2.p1.x, s2.p2.x));
        if (start <= end) { // Overlapping
            ans.push_back(Segment(Point(start, s1.p1.y), Point(end, s1.p1.y)));
        }
    } 
    // Handle perpendicular intersecting segments
    else {
        // Determine which segment is vertical and which is horizontal
        bool s1IsVertical = s1.p1.x == s1.p2.x;
        Segment verticalSegment = s1IsVertical ? s1 : s2;
        Segment horizontalSegment = s1IsVertical ? s2 : s1;

        // Check if the horizontal segment's y is within the vertical segment's y range
        // and if the vertical segment's x is within the horizontal segment's x range
        if (horizontalSegment.p1.y >= min(verticalSegment.p1.y, verticalSegment.p2.y) &&
            horizontalSegment.p1.y <= max(verticalSegment.p1.y, verticalSegment.p2.y) &&
            verticalSegment.p1.x >= min(horizontalSegment.p1.x, horizontalSegment.p2.x) &&
            verticalSegment.p1.x <= max(horizontalSegment.p1.x, horizontalSegment.p2.x)) {
            // The segments intersect at this point
            Point intersectionPoint = Point(verticalSegment.p1.x, horizontalSegment.p1.y);
            // Add this point as a degenerate segment
            ans.push_back(Segment(intersectionPoint, intersectionPoint));
        }
    }
}


vector<Segment> intersectSegments(vector<Segment> s1,vector<Segment> s2){
    //for each of the pairs of segments, grab the new segments...
    vector<Segment> ans;
    fr(0,s1.size()){
        rep(j,0,s2.size()){
            intersectSegment(s1[i],s2[j], ans);
        }
    }
    vector<Segment> newAns;
    std::set<std::pair<Point, Point>> seen;
    for(const auto& seg : ans) {
        auto p1 = seg.p1 < seg.p2 ? std::make_pair(seg.p1, seg.p2) : std::make_pair(seg.p2, seg.p1);
        if (seen.insert(p1).second) {
            newAns.push_back(seg);
        }
    }
    return newAns;
}

bool puedoConvertirX(int x, int y){
    return ((x+y)%2 == 0);
}

bool puedoConvertirY(int x, int y){
    return ((y-x)%2 == 0);
}

int convertX(int x, int y){
    return (x+y)/2;
}
int convertY(int x, int y){
    return (y-x)/2;
}

// void imprimirSegmento(Segment s){
//     int newX1 = convertX(s.p1.x, s.p1.y);
//     int newY1 = convertY(s.p1.x, s.p1.y);
//     int newX2 = convertX(s.p2.x, s.p2.y);
//     int newY2 = convertY(s.p2.x, s.p2.y);
//     cout << "(" << newX1 << ", " << newY1 << ") , (" << newX2<< ',' << newY2<< ")" <<endl;
// }

void addSegment(Segment s, vector<Point> &res){
    if (s.p1.x == s.p2.x) { // The segment is vertical
        for (int y = min(s.p1.y, s.p2.y); y <= max(s.p1.y, s.p2.y); ++y) {
            if (puedoConvertirX(s.p1.x, y) && puedoConvertirY(s.p1.x, y)){
                int originalX = convertX(s.p1.x, y);
                int originalY = convertY(s.p1.x, y);
                res.pb(Point(originalX, originalY));
            }
        }
    } else { // The segment is horizontal
        for (int x = min(s.p1.x, s.p2.x); x <= max(s.p1.x, s.p2.x); ++x) {
            if (puedoConvertirX(x, s.p1.y) && puedoConvertirY(x, s.p1.y)){
                int originalX = convertX(x, s.p1.y);
                int originalY = convertY(x, s.p1.y);
                res.pb(Point(originalX, originalY));
            }
        }
    }
}

void fillRes(vector<Segment> cur, vector<Point> &res){
    fr(0, cur.size()){
        addSegment(cur[i], res);
    }
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    Square squares[n];
    fr(0,n){
        int x, y, d; cin >> x >> y >> d;
        squares[i] = Square(x, y, d);
    }
    vector<Segment> cur;
    if (n>=2){
        cur = intersectSegments(squares[0].segmentos, squares[1].segmentos);
        fr(2,n){
            cur = intersectSegments(cur, squares[i].segmentos);
        }
    } else {
        cur = squares[0].segmentos;
    }

    vector<Point> res;
    //en cur tenemos los segmentos, es simplemente iterar y para convertir el punto y eso lo vamos guardando en un vector
    //llamar a una funcion que haga eso y que tenga res como referencia
    fillRes(cur, res);
    //hacer sort de res asi ya podemos imprimir todo.
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    fr(0,res.size()){
        cout << res[i].x << ' ' << res[i].y << "\n";
    }
}

//hay  que hacer una que sea intersectSegments mas facil y chau. 
// una vez que tenemos los segmentos los convertimos pa atras y ponemos los puntos y chau

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