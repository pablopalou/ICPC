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

void solve() {
    int n; cin >> n;
    int mat[n][n];
    int mini = 1e9;
    pair<int,int> posMini;
    fr(0,n){
        rep(j,0,n){
            cin >> mat[i][j];
            if (mat[i][j] < mini){
                mini = mat[i][j];
                posMini = {i,j};
            }
        }
    }
    if (posMini.first == 0 && posMini.second == 0){
        cout << 0 << "\n";
    } else if (posMini.first == 0 && posMini.second == n-1){
        cout << 1 << "\n";
    } else if (posMini.first == n-1 && posMini.second == n-1){
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }
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