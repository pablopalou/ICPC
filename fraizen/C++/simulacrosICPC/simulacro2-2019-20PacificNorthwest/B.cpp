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

//WA
void solve() {
    int n,k; cin >> n>>k;
    int a[n]; 
    int cant[k+1]; fr(0,k+1) cant[i] = 0;
    fr(0,n) {
        cin >> a[i];
        cant[a[i]]++;
    }
    set<int> s;
    fr(1,k+1){
        s.insert(i);
    }
    vector<int> res;
    fr(0,n){
        cant[a[i]]--;
        if (cant[a[i]] == 0){
            res.pb(a[i]);
            s.erase(a[i]);
        } else if (*s.begin() == a[i]){
            res.pb(a[i]);
            s.erase(a[i]);
            cant[a[i]] = 0;
        }
    }
    fre(res){
        cout << e << ' ';
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