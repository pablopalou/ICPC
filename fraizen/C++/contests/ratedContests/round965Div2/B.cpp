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
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    priority_queue<ll> pqPar, pqImpar;
    fr(0,n){
        // cout << a[i] << " ";
        if (a[i] % 2 == 1){
            // cout << "es impar " << endl;
            pqImpar.push(a[i]);
        } else {
            // cout << "meto el  " << -a[i] << "en par " << endl;
            pqPar.push(-a[i]);
        }
    }
    ll res = 0;
    while((!pqPar.empty()) && (!pqImpar.empty())){
        res = res + 1;
        ll par = pqPar.top();
        par = par*(-1);
        ll impar = pqImpar.top();
        // cout << "par " << par << endl;
        // cout << "impar " << par << endl;
        if (par > impar){
            //aca puedo sumar el size me parece:
            cout << res + pqPar.size() << '\n'; return;
            // pqImpar.pop();
            // pqImpar.push(par+impar);
        } else {
            pqPar.pop();
            pqImpar.push(par+impar);
        }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}