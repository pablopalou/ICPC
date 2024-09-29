#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007

ll expMod(ll b, ll e, ll m = mod) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    int a[n];
    fr(0,s.size()){
        if (s[i] == '0'){
            a[i] = -1;
        } else {
            a[i] = 1;
        }
    }
    int p[n+1];
    memset(p, 0, sizeof(p));
    fr(1,n+1){
        p[i] = p[i-1] + a[i-1];
    }
    // fr(0,n+1){
    //     cout << p[i] << ' ';
    // }
    map<ll, vector<int>> m;
    fr(0,n+1){
        m[p[i]].pb(i);
    }
    ll res = 0;
    fre(m){
        // fr(0,e.second.size()){
        //     cout << e.second[i] << ' ';
        // }
        // cout << endl;
        ll cant = e.second.size();
        if (cant > 1){
            ll suf[cant+1];
            suf[cant] = 0;
            suf[cant-1] = e.second[cant-1];
            // pref[i] = 0;
            for(ll i = cant-2; i>=0; i--){
                suf[i] = suf[i+1] + e.second[i];
            }
            // fr(0,cant+1){
            //     cout << suf[i] << ' ';
            // }
            // cout << endl;
            ll quedan = cant-1;
            fr(0,cant-1){
                // cout << "Miro " << e.second[i]+1 << endl;
                // cout << "Quedan = " << quedan << endl;
                // cout << "Sufijo = " << suf[i+1] << endl; 
                res = (res + (((e.second[i]+1) * ((((n+1)*quedan) % mod - (suf[i+1] % mod))))  % mod))  % mod;
                // cout << "res = " << res << endl;
                quedan--;
            }
            // fr(0, cant){
            //     rep(j,i+1, cant){
            //         res = (res + (e.second[i]+1) % mod * (n+1 - e.second[j]) % mod) % mod;
            //     }
            // }
        }
    }
    cout << res % mod << endl;
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