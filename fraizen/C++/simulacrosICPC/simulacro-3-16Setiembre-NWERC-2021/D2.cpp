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
#define inf 1e9

bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1);
}
void solve() {
    int n; cin >> n;
    int x[n],y[n];
    int maxi1 = -inf;
    int maxi2 = -inf;
    int maxi3 = -inf;
    int maxi4 = -inf;
    fr(0,n){
        cin >> x[i] >> y[i];
        maxi1 = max(maxi1, x[i]+y[i]);
        maxi2 = max(maxi2, x[i]-y[i]);
        maxi3 = max(maxi3, -x[i]+y[i]);
        maxi4 = max(maxi4, -x[i]-y[i]);
    }
    ll res = maxi1 + maxi2 + maxi3 + maxi4 + 4;
    if (n == 1){
        cout << 4; return;
    }
    bool all_diagonal_1 = true; // Checks if all x + y are the same
    bool all_diagonal_2 = true; // Checks if all x - y are the same

    int diagonal_sum = x[0] + y[0];
    int diagonal_diff = x[0] - y[0];

    for (int i = 1; i < n; i++) {
        if (x[i] + y[i] != diagonal_sum) {
            all_diagonal_1 = false;
        }
        if (x[i] - y[i] != diagonal_diff) {
            all_diagonal_2 = false;
        }
    }
    if (all_diagonal_1 || all_diagonal_2) {
        res += 1;
    }
    cout << res << '\n';
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