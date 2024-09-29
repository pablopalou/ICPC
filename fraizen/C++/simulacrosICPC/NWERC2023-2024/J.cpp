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
int n; 
# define PI           3.14159265358979323846 
#define inf 1e18

typedef long double T; // double could be faster but less precise
typedef long double ld;
const T EPS = 1e-9; // if T is integer, set to 0
const T INF = 1e18;
struct pto{
	T x, y;
	pto() : x(0), y(0) {}
	pto(T _x, T _y) : x(_x), y(_y) {}
	pto operator-(pto b) { return pto(x-b.x, y-b.y); }
    pto operator+(pto b) { return pto(x+b.x, y+b.y); }
	// dot product
	T operator*(pto b) { return x*b.x + y*b.y; }
	// module of cross product, a^b>0 if angle_cw(u,v)<180
	T operator^(pto b) { return x*b.y - y*b.x; }
	//rotate by theta rads CCW w.r.t. origin (0,0)
	pto rotate(T ang) {
		return pto(x*cosl(ang) - y*sinl(ang), x*sinl(ang) + y*cosl(ang));
	}
};

ld angle(pto a, pto o, pto b) {
	pto oa = a-o, ob = b-o;
	return atan2l(oa^ob, oa*ob);
}
ld dist[12][12];

ld fraizen(){
    ld res = inf;
    //hago dp
    // dp[mask][last] => camino mas corto posible pasando por mask, terminando en last.
    ld dp[1<<n][n];
    fr(0, (1<<n)){
        rep(j,0,n){
            dp[i][j] = inf;
        }
    }
    fr(0,n){
        dp[1<<i][i] = 0;
    }
    for(int mask = 0; mask < (1<<n); mask++){
        for(int last = 0; last < n; last++){
            if ((1 << last) & mask){
                for(int nuevo = 0; nuevo < n; nuevo++){
                    if (((1 << nuevo) & mask) == 0){
                        dp[mask | (1<<nuevo)][nuevo] = min(dp[mask | (1<<nuevo)][nuevo], dp[mask][last] + dist[last][nuevo]);
                    }
                }
            }
        }
    }
    fr(0,n){
        res = min(res, dp[(1<<n)-1][i]);
    }
    return res;
}

vector<pto> p;
void solve() {
    cin >> n;
    p.resize(n);
    fr(0,n){
        cin >> p[i].x >> p[i].y;
    }
    ld res = inf;
    fr(0,n){
        rep(j,0,n){
            if (i == j) continue;
            ld cur = inf;
            //para cada par de puntos, hallamos el angulo y rotamos todos los puntos. Hallamos todas las distancias y hacemos la dp
            ld ang = angle(p[j], p[i], p[i] + pto(1,0));
            // cout << "Angulo = " << fixed << setprecision(6) << ang << endl;
            vector<pto> pCur(n);
            rep(k,0,n){
                pCur[k] = p[k].rotate(ang);
            } 
            rep(a,0,n){
                rep(b,0,n){
                    dist[a][b] = abs(pCur[a].x - pCur[b].x) + abs(pCur[a].y - pCur[b].y);  
                }
            }
            // rep(a,0,n){
            //     rep(b,0,n){
            //         cout << dist[a][b] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            cur = fraizen();
            res = min(res, cur);
        }
    }
    cout << fixed << setprecision(12) << res << '\n';
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

// Angulo = 0.674741
// 0.000000 7.652514 5.778429 2.967301 
// 7.652514 0.000000 4.060518 7.808688 
// 5.778429 4.060518 0.000000 4.685213 
// 2.967301 7.808688 4.685213 0.000000 

// Angulo = 0.244979
// 0.000000 8.973818 5.578319 3.152963 
// 8.973818 0.000000 3.395499 9.216354 
// 5.578319 3.395499 0.000000 5.820855 
// 3.152963 9.216354 5.820855 0.000000 

// Angulo = -1.107149
// 0.000000 8.497058 5.813777 3.130495 
// 8.497058 0.000000 3.577709 8.049845 
// 5.813777 3.577709 0.000000 5.366563 
// 3.130495 8.049845 5.366563 0.000000 

// Angulo = -1.892547
// 0.000000 8.221922 4.427189 2.529822 
// 8.221922 0.000000 4.427189 10.119289 
// 4.427189 4.427189 0.000000 5.692100 
// 2.529822 10.119289 5.692100 0.000000 

// Angulo = -2.158799
// 0.000000 6.933752 5.269652 2.496151 
// 6.933752 0.000000 4.437602 9.429903 
// 5.269652 4.437602 0.000000 4.992302 
// 2.496151 9.429903 4.992302 0.000000 

// Angulo = -2.356194
// 0.000000 7.071068 5.656854 2.828427 
// 7.071068 0.000000 4.242641 8.485281 
// 5.656854 4.242641 0.000000 4.242641 
// 2.828427 8.485281 4.242641 0.000000 

// 11.313708498985
