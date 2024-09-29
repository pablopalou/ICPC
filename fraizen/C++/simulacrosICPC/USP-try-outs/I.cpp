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
    ll n; cin >> n; ll h[n];fr(0,n) cin >> h[i];
    vector<int> a;
    fr(0,n){
        if (h[i]!=0){
            a.pb(h[i]);
        }
    }
    if (a.size() == 0){
        cout << 0 <<'\n'; return;
    }
    int res = 0;
    fr(0,a.size()){
        if (a[i] > 1){
            res++;
            break;
        }
    }
    if (res == 1){
        fr(0,a.size()){
            a[i]%=2;
        }
    }
    fr(0,a.size()){
        if (a[i] == 1){
            cout << res+1 << "\n"; return;
        }
    }
    cout << res << "\n";
    // bool todoCero = true;
    // bool todoUno = true;
    // bool todoPar = true;
    // fr(0,n){
    //     if (a[i]!=0){
    //         todoCero = false;
    //     }
    //     if (a[i]%2 == 1){
    //         todoPar = false;
    //     }
    //     if (a[i]!=1){
    //         todoUno = false;
    //     }
    // }
    // if (todoCero){
    //     cout << 0 <<'\n';
    // } else if (todoUno or todoPar){
    //     cout << 1 << '\n';
    // } else {
    //     cout << 2 << "\n";
    // }
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