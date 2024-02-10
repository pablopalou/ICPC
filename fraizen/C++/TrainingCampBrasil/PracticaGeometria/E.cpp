#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define pb push_back

// Given two sets of points, check whether their convex hulls are isomorphic.

// The standard solution is: get the convex hulls, make it into a string of traversal: "edge-angle-edge-angle-edge-...". Then double the first string and KMP them.

// There can be other ways to solve this problem, because there is a useful condition: all coordinates are integers.

typedef ll T; // double could be faster but less precise
typedef double ld;
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator+(pto b){ return pto(x+b.x, y+b.y); }
	pto operator-(pto b){ return pto(x-b.x, y-b.y); }
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
	ll norm(){ return sqrtl(x*x+y*y); }
	ld dist(pto b){ return (b-(*this)).norm(); }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T theta) {
		return pto(x*cosl(theta)-y*sinl(theta),x*sinl(theta)+y*cosl(theta));
	}
	// true if this is at the left side of line ab
	bool left(pto a, pto b){return ((a-*this)^(b-*this))>=0;}
	bool operator<(const pto &b) const {
		return x<b.x-EPS || (llabs(x-b.x)<=EPS && y<b.y-EPS);
	}
	bool operator==(pto b){return llabs(x-b.x)<=EPS && llabs(y-b.y)<=EPS;}
};
ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}
ld angle(pto a, pto b) { // smallest angle bewteen a and b
	ld cost = (a*b) / a.norm() / b.norm();
	return acosl(max(ld(-1.), min(ld(1.), cost)));
}

vector<pto> CH(vector<pto>& p) {
	vector<pto> ch;
	sort(p.begin(), p.end());
	forn(i, sz(p)) { // lower hull
		while(sz(ch)>=2 && ch[sz(ch)-1].left(ch[sz(ch)-2], p[i])) ch.pop_back();
		ch.pb(p[i]);
	}
	ch.pop_back();
	int k = sz(ch);
	dforn(i, sz(p)) { // upper hull
		while(sz(ch)>=k+2 && ch[sz(ch)-1].left(ch[sz(ch)-2],p[i]))ch.pop_back();
		ch.pb(p[i]);
	}
	ch.pop_back();
	return ch;
}

vector<pair<ll,ll>> hullToPairs(vector<pto>& hull){
    vector<pair<ll,ll>> res(hull.size());
    fr(0,hull.size()){
        int next = (i+1) % hull.size();
        ll dx = hull[next].x - hull[i].x;
        ll dy = hull[next].y - hull[i].y;
        ll edgeLengthSquared = dx*dx + dy*dy;

        pto a, b; auto c = a-b;
        if ( next+1 != hull.size() || (next ==hull.size() -1 && hull.size() > 2)){
            int nextNext = (next+1) % hull.size();
            pto vec1 = hull[next] - hull[i];
            pto vec2 = hull[nextNext] - hull[next];
            // ll cross = vec1 ^ vec2;
            ll dot = vec1 * vec2;
            // ss << dot << cross << "-";
            res[i] = (make_pair(edgeLengthSquared, dot));
        }
    }
    return res;
}

    vector<int> kmppre(string& P) {
        vector<int> b(sz(P)+1); b[0] = -1;
        int j = -1;
        forn(i, sz(P)) {
            while(j >= 0 && P[i] != P[j]) j = b[j];
            b[i+1] = ++j;
        }
        return b;
    }
    bool kmp(string& T, string& P) { //Text, Pattern -- O(|T|+|P|)
        int j = 0;
        vector<int> b = kmppre(P);
        forn(i, sz(T)) {
            while(j >= 0 && T[i] != P[j]) j = b[j];
            if(++j == sz(P)) {
                return true;
                j = b[j];
            }
        }
        return false;
    }

string hullToPairsToString(vector<std::pair<ll, ll>> hullPairs) {
    std::stringstream ss;
    for (const auto& p : hullPairs) {
        ss << p.first << "-" << p.second << ";"; // Use ";" to separate pairs for clarity
    }
    return ss.str();
}

// Copiar obligatoriamente 0
void solve() {
    int n, m; cin >> n >> m;
    vector<pto> puntos1(n), puntos2(m);
    fr(0,n){
        pto p;
        cin >> p.x >> p.y;
        puntos1[i] = p;
    }
    cout << " "<< endl;
    fr(0,m){
        pto p;
        cin >> p.x >> p.y;
        puntos2[i] = p;
    }
    vector<pto> ch1 = CH(puntos1);
    vector<pto> ch2 = CH(puntos2);
    if (ch1.size() != ch2.size()){
        cout << "NO" << '\n';
        return;
    }
    if (ch1.size() == 1) {
        cout << "YES\n"; return;
    }
    //creo que falta el caso de ch1.size = = 2
    vector<pair<ll,ll>> s1 = hullToPairs(ch1);
    vector<pair<ll,ll>> s2 = hullToPairs(ch2);
    // cout << s3.size() << endl;
    string s1A = hullToPairsToString(s1);
    s1A += s1A;
    string s2A = hullToPairsToString(s2);
    if (kmp(s1A, s2A)){
        cout << "YES\n"; return;
    } else {
        cout << "NO\n"; return;
    };
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << "fdsafdsa" << endl;
    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cout << cases << endl;
    // cin >> cases;
    while(cases--){
        // cout << "fdsaf" << "\n";
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}