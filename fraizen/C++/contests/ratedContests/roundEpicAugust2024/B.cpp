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
    int n; cin >> n; int a[n]; int b[n]; fr(0,n) cin >> a[i]; fr(0,n) cin >> b[i];
    bool gano = true;
    //o tood igual, o to al reves (ahi gana Bob)
    bool igual = true;
    fr(0,n){
        if (a[i] != b[i]){
            igual = false;
        }
    }
    bool reves = true;
    fr(0,n){
        if (a[i] != b[n-1-i]){
            reves = false;
        }
    }
    if (igual or reves){
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
    // fr(0,n){
    //     if ((a[i] == b[i] and a[n-1-i] == b[n-1-i]) or (a[i] == b[n-1-i] and a[n-1-i] == b[i])){
    //         //nada
    //     } else {
    //         gano = false;
    //     }
    // }
    // if (gano){
    //     cout << "Bob\n";
    // } else {
    //     cout << "Alice\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}