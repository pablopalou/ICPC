#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

struct Circle{
    ll x,y,r;
};

const int MAXN = 1005;
bool level[MAXN];
int par[MAXN];
vector<ll> hijos[MAXN];

bool circle_inside_circle(Circle c1, Circle c2){
    return sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y)) < c2.r;
}

void dfs (int v,bool color){
    level[v] = color;
    for(auto u : hijos[v]){
        dfs(u, color ^ 1);
    }
}
// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    Circle circles[n];

    fr(0,n){
        Circle c;
        cin >> c.x >> c.y >> c.r;
        circles[i] = c;
    }
    fill(par, par + n, -1);
    fill(level, level + n, false);
    fr(0,n){
        rep(j,0,n){
            if (i == j) continue;
            if (circles[i].r < circles[j].r && circle_inside_circle(circles[i], circles[j])){
                // cout << i+1 <<" adentro de " << j+1 << endl;
                if (par[i] == -1 || circles[par[i]].r > circles[j].r){
                    par[i] = j;
                }
            }
        }
        hijos[par[i]].push_back(i);
    }
    fr(0,n){
        if (par[i] == -1){
            dfs(i, false);
        }
    }
    ll ans = 0;
    fr(0,n){
        ans += circles[i].r * circles[i].r * ( (level[i] || par[i] == -1) ? 1 : -1);
    }
    cout << fixed << setprecision(12) << (ans * acos(-1)) << "\n";
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