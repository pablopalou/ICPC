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
    int n,a,b; cin >> n>>a>>b;
    double e[n+1];
    e[0] = 0.0;
    int l = b-a+1;
    double prefix[n+1]; prefix[0] = 0;
    if (a >= n){
        cout << 1; return;
    }
    if (a != 0){
        fr(1,a+1){
            e[i] = 1.0;
            prefix[i] = e[i] + prefix[i-1];
        }
        fr(a+1,n+1){
            if (i-b-1 >= 0){
                e[i] = 1 + (1.0/l)*(prefix[i-a] - prefix[i-b-1]);
            } else {
                e[i] = 1 + (1.0/l)*(prefix[i-a]);
            }
            prefix[i] = e[i] + prefix[i-1];
        }
        cout << fixed << setprecision(10) << e[n] << endl;
        return;
    }
    // a es 0
    fr(1,n+1){
        if (i-b-1 >= 0){
            e[i] = l / (l-1.0) * (1 + (1.0)/l * (prefix[i-1] - prefix[i-b-1])); 
        } else {
            e[i] = l / (l-1.0) * (1 + (1.0)/l * (prefix[i-1])); 
        }
        prefix[i] = e[i] + prefix[i-1];
    }
    cout << fixed << setprecision(10) << e[n] << endl;
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