//https://codeforces.com/problemset/problem/1019/D

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
#define mp make_pair

typedef ll T; // double could be faster but less precise
const T EPS = 0; // if T is integer, set to 0
const T INF = 1e18;
ll id = 0;

ll n ;
struct pto{
	T x, y, id, u, v;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y){}
    void setId(ll idP){
        id = idP;
    }
	pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
	pto operator+(T k) { return pto(x+k, y+k); }
	pto operator*(T k) { return pto(x*k, y*k); }
	pto operator/(T k) { return pto(x/k, y/k); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b) { return x*b.y - y*b.x; }
	// true if this is at the left side of line ab
	bool left(pto a, pto b) { return ((a-*this) ^ (b-*this)) > 0; }
	bool operator<(const pto &b) const {
		return x < b.x-EPS || (abs(x - b.x) <= EPS && y < b.y-EPS);
	}
	bool operator==(pto b){ return abs(x-b.x)<=EPS && abs(y-b.y)<=EPS; }
};

struct cmp {
    pto o, v;
    cmp(pto no, pto nv) : o(no), v(nv) {}
    bool half(pto p) {
        assert(!(p.x == 0 && p.y == 0));  // (0,0) isn't well defined @TODO: como lo handleo? al parecer hay que sacar el mismo punto
        //o sea, si estoy parado en 1,5 y mando todos los puntos de vuelta pa ordenar, se rompe, entonces no lo agrego ahi.
        return (v ^ p) < 0 || ((v ^ p) == 0 && (v * p) < 0);
    }
    bool operator()(pto& p1, pto& p2) {
        return mp(half(p1 - o), T(0)) < mp(half(p2 - o), ((p1 - o) ^ (p2 - o)));
    }
};

// after each step() execution pt is sorted by dot product of the event
struct all_point_pairs {  // O(n*n*log(n*n)), must add id, u, v to pto
  vector<pto> pt, ev;
  vector<int> idx;
  int cur_step;
  all_point_pairs(vector<pto> pt_) : pt(pt_) {
    idx = vector<int>(sz(pt));
    forn(i, sz(pt)) forn(j, sz(pt)) if (i != j) {
      pto p = pt[j] - pt[i];
      p.u = pt[i].id, p.v = pt[j].id;
      ev.pb(p);
    }
    sort(ev.begin(), ev.end(), cmp(pto(0, 0), pto(1, 0)));
    pto start(ev[0].y, -ev[0].x);
    sort(pt.begin(), pt.end(),
         [&](pto& u, pto& v) { return u * start < v * start; });
    forn(i, sz(idx)) idx[pt[i].id] = i;
    cur_step = 0;
  }
  bool step() {
    if (cur_step >= sz(ev)) return false;
    int u = ev[cur_step].u, v = ev[cur_step].v;
    swap(pt[idx[u]], pt[idx[v]]);
    swap(idx[u], idx[v]);
    cur_step++;
    return true;
  }
};


void print_ans(pto a1, pto a2, pto a3) {
	cout << "Yes\n";
	cout << a1.x << " " << a1.y << "\n";
	cout << a2.x << " " << a2.y << "\n";
	cout << a3.x << " " << a3.y << "\n";
} 
 
bool solve_down (ll r, vector<pto> &pts, pto u, pto v, ll x, pto &ans) {
	ll l = 0;
    r = n*n-1; 
	while(l<r) {
		ll m = (l+r)/2;
		if(((v-u)^(pts[m]-u)) > 2LL*x) l = m+1;
		else r = m; 
	}
	
	if(abs((u-v)^(pts[l]-v)) == 2LL*x) {
		ans = pts[l];
		return true;
	}
	
	return false;
}

void solve() {
    ll s; cin >> n >> s;
    vector<pto> p(n);
    fr(0,n){
        int x,y; cin >> x >> y;
        p[i] = pto(x,y);
        p[i].setId(i);
    }
    //va bien
    // fre(p){
    //     cout << e.x << " " << e.y << " id => " << e.id << endl;
    // }

    //para cada uno de los puntos, hacer polar sort e ir en ese orden haciendo los cambios. 
    // vector<pto> vectores;
    // fr(0,n){
    //     rep(j,i,n){
    //         vectores.pb(p[j]-p[i]);
    //     }
    // }
    // tengo que hacer el radial sort, agarrar el primer vector y rotarlo 90 grados y ahi hacer el producto punto para hacer la binaria
    // sort(vectores.begin(), vectores.end(), cmp(pto(0,0), pto(1,0)));
    // pto p = vectores[0];

    // (el all_points_pair ya hace el tema de poner todos los vectores, hacer el radial sort, la rotacion y el ordenamiento)

    all_point_pairs app(p); pto ans;
	while(app.step()){
		int u = app.idx[app.ev[app.cur_step-1].u] , v = app.idx[app.ev[app.cur_step-1].v];
		if(solve_down(u, app.pt, app.pt[u], app.pt[v], s, ans)){
			print_ans(ans, app.pt[u], app.pt[v]);
			return;
		}
	} 
	
	cout << "No\n";

    return;
    // all_point_pairs app = all_point_pairs(p);

    // while(app.step()){
    //     //hago la binaria
    //     // cout << "Estoy parado en la iteracion i = " << i << endl;
    //     int l = 0;
    //     int r = n*n-1;
    //     //veo solo los positivos 
    //     //para saber el area hacemos: abs(producto cruz ab * producto cruz ac)/2;
    //     while(l < r){
    //         int mid = l + (r-l)/2;
    //         //saco el u y el v
    //         pto u = p[app.ev[app.cur_step].u];
    //         pto v = p[app.ev[app.cur_step].v];
    //         pto ptomid = app.pt[mid];
    //         ll area = (v-u)^(ptomid-u) / 2;
    //         // cout << "Area " << area << endl;
    //         if (area == s){
    //             cout << "Yes\n";
    //             cout << u.x << ' ' << u.y << '\n';
    //             cout << v.x << ' ' << v.y << '\n';
    //             cout << ptomid.x << ' ' << ptomid.y << '\n';
    //             return;
    //         } else if (area > s){
    //             r = mid-1;
    //         } else {
    //             l = mid+1;
    //         }
    //     }
    // }
    // cout << "No\n";
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