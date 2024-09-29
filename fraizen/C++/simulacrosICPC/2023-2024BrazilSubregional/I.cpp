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

ll gauss(ll n){
    return (n * (n+1) / 2);
}

void solve() {
    int n; cin >> n;
    int a[n]; fr(0,n) cin >> a[i];
    ll unos = 0;
    fr(0,n){
        if (a[i] == 1){
            unos++;
        }
    }
    int prefix[n];
    prefix[0] = a[0];
    fr(1,n){
        prefix[i] = prefix[i-1] + a[i];
    }
    ll cantPar = 0; ll cantImpar = 0;
    fr(0,n){
        if (prefix[i] % 2 == 0){
            cantPar++;
        } else {
            cantImpar++;
        }
    }
    cout << cantPar << endl;
    cout << cantImpar << endl;
    ll res = 0;
    res += gauss(cantPar);
    res+= gauss(cantImpar-1);
    res+= unos;
    cout <<res << '\n';
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