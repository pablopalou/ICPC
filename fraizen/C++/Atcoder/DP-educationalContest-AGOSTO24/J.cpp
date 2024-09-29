#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

double dp[301][301][301];
ll n;

double f(int c1, int c2, int c3){
    if (c1 < 0 or c2 < 0 or c3 < 0) return 0.0;
    double &res = dp[c1][c2][c3];
    if (res != -1) return res;
    return res = (1 + (c1/double(n))*f(c1-1, c2, c3) + (c2/double(n))*f(c1+1, c2-1, c3) + (c3/double(n)) * f(c1, c2+1, c3-1)) / (1 - (n-c1-c2-c3)/(double(n)));
}

void solve() {
    cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    int cant1, cant2, cant3;
    cant1 = cant2= cant3 = 0;
    fr(0,n){
        if (a[i] == 1) cant1++;
        if (a[i] == 2) cant2++;
        if (a[i] == 3) cant3++;
    }
    fr(0,301){
        rep(j,0,301){
            rep(k,0,301){
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0.0;
    cout << fixed << setprecision(14) << f(cant1, cant2, cant3) << "\n";
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