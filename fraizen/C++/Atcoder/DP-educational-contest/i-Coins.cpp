#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll n;
double dp[3005][3005];
double prob[3005];

double f(ll x, ll y){
    double &r = dp[x][y];
    if(r>=0)return r;
    if(x+y==n){
		r=(x>y); return r;
	}
    r = prob[x+y] * f(x+1,y) + (1-prob[x+y])*(f(x,y+1));
    return r;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    fr(0,n){
        cin >> prob[i];
    }
    cout << fixed << setprecision(12) << f(0,0) << "\n";
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