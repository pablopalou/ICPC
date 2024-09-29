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

ll dist(ll x1,ll x2,ll y1,ll y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1); 
}

void solve() {
    ll n; cin >> n;
    ll px[n]; ll py[n];
    fr(0,n){
        cin >> px[i] >> py[i];
    }
    ll iniciox, inicioy,finx,finy;
    cin >> iniciox >> inicioy >> finx >> finy;
    ll mini = 4e18;
    fr(0,n){
        mini = min(mini, dist(px[i], finx, py[i], finy));
    }
    if (dist(iniciox, finx, inicioy, finy) < mini){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}