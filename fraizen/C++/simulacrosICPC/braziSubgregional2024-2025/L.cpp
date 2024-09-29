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
    ll bits[32]; memset(bits, 0, sizeof(bits));
    fr(0,n){
        rep(j,0,31){
            if ((a[i] & (1<<j)) != 0){
                bits[j]++;
            }
        }
    }
    // fr(0,32){
    //     cout << bits[i] << " ";
    // }
    // cout << endl;
    fr(0,n){
        ll cur = 0;
        rep(j,0,31){
            if (bits[j] > 0){
                cur += (1<<j);
                bits[j]--;
            }
        }
        cout << cur << " ";
    }
    cout << "\n";
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