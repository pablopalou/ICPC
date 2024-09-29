#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e: s)

#ifdef ANARAP
// local
#else
// judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

typedef long long T;
const T EPS = 0;
const T INF = 1e18;

struct pto{
    T x,y;
    pto() : x(0), y(0) {}
    pto(T _x, T _y) : x(_x), y(_y) {}
    pto operator-(pto b) {return pto(x-b.x, y-b.y);}
    T operator^(pto b) {return x*b.y-y*b.x;}
    bool operator<(const pto&b) const {
        return x < b.x or (abs(x-b.x) <= EPS && y < b.y-EPS);
    }
    bool left(pto a, pto b) {return ((a-*this) ^ (b-*this)) > 0;}
};

vector<pto> CH(vector<pto>& p){
    if(sz(p) < 3) return p;
    vector<pto> ch;
    sort(p.begin(), p.end());
    forn(i, sz(p)){
        while(sz(ch) >= 2 && ch[sz(ch) -1].left(ch[sz(ch) -2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    int k = sz(ch);
    dforn(i, sz(p)){
        while(sz(ch) >= k + 2 && ch[sz(ch) -1].left(ch[sz(ch) -2], p[i]))
            ch.pop_back();
        ch.pb(p[i]);
    }
    ch.pop_back();
    return ch;
}

void solve(){
    int n; cin >> n;
    vector<pto> p;
    map<pair<ll,ll>, int> m;
    fr(0,n){
        pto punto; cin >> punto.x >> punto.y;
        p.pb(punto);
        m[mp(punto.x, punto.y)] = i;
    }
    vector<pto> ch = CH(p);
    // fre(ch){
    //     cout << e.x << " " << e.y << endl;
    // }
    vector<int> res;
    fre(ch){
        res.pb(m[mp(e.x, e.y)]);
    }
    sort(res.begin(), res.end());
    set<int> s;
    fre(res){
        s.insert(e+1) ;
    }
    fre(s){
        cout << e << " ";
    }
    
}

int main() {
// agregar g++ -DANARAP en compilacion
#ifdef ANARAP
  freopen("input.in", "r", stdin);
  // freopen("output.out","w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    solve();
  return 0;
}