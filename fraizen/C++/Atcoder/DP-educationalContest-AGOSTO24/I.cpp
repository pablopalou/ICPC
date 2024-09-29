#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 3001
int n;
double p[MAXN];
double dp[MAXN][MAXN];

double f(int i, int j){ //prob de que faltando n, tenga x cara
    if (i == n && j == 0) return 1.0;
    if (i == n) return 0;
    double &res = dp[i][j];
    if (res != -1) return res;
    return res = f(i+1, j) * (1-p[i]) + f(i+1, j-1) * p[i];
}

void solve() {
    cin >> n;
    fr(0,n) cin >> p[i];
    fr(0,n){
        rep(j,0,n+1){
            dp[i][j] = -1;
        }
    }
    int mini = n/2 + 1;
    double res = 0.0;
    fr(mini, n+1){
        res += f(0,i);
    }
    cout << fixed << setprecision(10) << res << '\n';
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