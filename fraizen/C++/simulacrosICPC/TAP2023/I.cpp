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
#define inf 1e18
typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
#define MAXN 1000100

typedef pair<ld, int> ii;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	T norm_sq() { return x*x + y*y; }
	ld norm() { return sqrtl(x*x + y*y); }
	ld dist(pto b) { return (b - (*this)).norm(); }
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
};
struct Dijkstra {        // WARNING: ii usually needs to be pair<ll, int>
  vector<vector<ii>> G;  // ady. list with pairs (weight, dst)
  vector<ld> dist;
  // vector<int> vp; // for path reconstruction (parent of each node)
  int N;
  Dijkstra(int n) : G(n), N(n) {}
  void addEdge(int a, int b, ld w) { G[a].pb(make_pair(w, b)); }
  void run(int src) {  // O(|E| log |V|)
    dist = vector<ld>(N, INF);
    // vp = vector<int>(N, -1);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(make_pair(0, src)), dist[src] = 0;
    while (sz(Q)) {
      int node = Q.top().snd;
      ld d = Q.top().fst;
      Q.pop();
      if (d > dist[node]) continue;
      forall(it, G[node]) if (d + it->fst < dist[it->snd]) {
        dist[it->snd] = d + it->fst;
        // vp[it->snd] = node;
        Q.push(make_pair(dist[it->snd], it->snd));
      }
    }
  }
};


struct circle{
    pto p;
    ll r;
};

struct square{
    pto p[4];
};

struct triangle{
    pto p[3];
};

circle circles[MAXN];
square squares[MAXN];
triangle tria[MAXN];
ll c,q,t; 

ld dist_t_c(int i, int j){
    ld res = inf;
    rep(k,0,3){
        pto p = (segm(tria[i].p[k], tria[i].p[(k+1)%3])).closest(circles[j].p);
        res = min(res, p.dist(circles[j].p) - circles[j].r);
    }
    return res;
}

ld dist_c_q(int i, int j){
    ld res = inf;
    rep(k,0,4){
        pto p = (segm(squares[j].p[k], squares[j].p[(k+1)%4])).closest(circles[i].p);
        res = min(res, p.dist(circles[i].p) - circles[i].r);
    }
    return res;
}

ld dist_c_c(int i, int j){
    return circles[i].p.dist(circles[j].p) - circles[i].r - circles[j].r;
}

ld dist_pto_seg(pto p, segm s){
    pto p2 = s.closest(p);
    return p2.dist(p);
}

ld dist_segm_segm(segm s1, segm s2){
    ld res = inf;
    //para hacer distancia segmento a segmento hacemos 4 distancias punto a segmento.
    //primero hago vertices de s1 contra s2
    res = min(res, dist_pto_seg(s1.s, s2));
    res = min(res, dist_pto_seg(s1.e, s2));
    res = min(res, dist_pto_seg(s2.s, s1));
    res = min(res, dist_pto_seg(s2.e, s1));
    return res;
}

ld dist_t_q(int i, int j){
    ld res = inf;
    rep(k,0,3){
        rep(h,0,4){
            //tengo que hacer la mejor distancia segmento segmento
            res = min(res, dist_segm_segm(segm(tria[i].p[k], tria[i].p[(k+1)%3]), segm(squares[j].p[h], squares[j].p[(h+1)%4])));
        }
    }
    return res;
}

void solve() {
    cin >> c>>q >> t;
    fr(0,c){
        ll x,y,r; cin >> circles[i].p.x >> circles[i].p.y >> circles[i].r;
        // cout << "circle " << i << " = " << circles[i].p.x << " " << circles[i].p.y << " con radio = " << circles[i].r << endl;
    }
    fr(0,q){
        ll x1,y1,x2,y2,x3,y3,x4,y4; 
        cin >> x1 >> y1 >> x2 >> y2;
        ld xc = (x1 + x2) / 2.0 ;
        ld xd = (x1-x2)/2.0;
        ld yc = (y1+y2)/2.0;
        ld yd = (y1-y2)/2.0;

        // x3 = (x1 + x2) / 2.0 - (y2-y1)/2.0;
        // y3 = (y1 + y2) / 2.0 + (x2-x1)/2.0;
        // x4 = (x1 + x2) / 2.0 + (y2-y1)/2.0;
        // y4 = (y1 + y2) / 2.0 - (x2-x1)/2.0; 
        squares[i].p[0] = pto(x1,y1);
        squares[i].p[1] = pto(xc-yd, yc+xd);
        squares[i].p[2] = pto(x2,y2);
        squares[i].p[3] = pto(xc+yd, yc-xd);
    }
    fr(0,t){
        cin >> tria[i].p[0].x >> tria[i].p[0].y >> tria[i].p[1].x >> tria[i].p[1].y >> tria[i].p[2].x >> tria[i].p[2].y;
    }
    Dijkstra d = Dijkstra(2 + c + q + t);
    //hago las distancias triangulo circulo
    fr(0,t){
        rep(j,0,c){
            ld dist = dist_t_c(i,j);
            d.addEdge(i, t+j,dist);
        }
    }
    //hago las distancias triangulo cuadrado
    fr(0,t){
        rep(j,0,q){
            ld dist = dist_t_q(i,j);
            d.addEdge(i, t+c+j,dist);
        }
    }
    fr(0,c){
        rep(j,0,c){
            if (i!=j){
                ld dist = dist_c_c(i,j);
                d.addEdge(t+i, t+j,dist);
            }
        }
    }
    fr(0,c){
        rep(j,0,q){
            ld dist = dist_c_q(i,j);
            d.addEdge(t+i, t+c+j,dist);
        }
    }
    fr(0,t){
        d.addEdge(c+q+t, i, 0);
    }
    fr(0,q){
        d.addEdge(t+c+i, c+q+t+1, 0);
    }
    d.run(c+q+t);
    cout << fixed << setprecision(12) << d.dist[c+q+t+1] << '\n';
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