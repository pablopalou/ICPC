#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

// P should be a prime number, could be randomly generated,
// sometimes is good to make it close to alphabet size
// MOD[i] must be a prime of this order, could be randomly generated
const int P = 1777771, MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};  // PI[i] = P^-1 % MOD[i]
struct Hash {
  vector<int> h[2], pi[2];
  vector<ll> vp[2];  // Only used if getChanged is used (delete it if not)
  Hash(string& s) {
    forn(k, 2) h[k].rsz(s.size() + 1), pi[k].rsz(s.size() + 1),
        vp[k].rsz(s.size() + 1);
    forn(k, 2) {
      h[k][0] = 0;
      vp[k][0] = pi[k][0] = 1;
      ll p = 1;
      forr(i, 1, sz(s) + 1) {
        h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
        pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
        vp[k][i] = p = (p * P) % MOD[k];
      }
    }
  }
  ll get(int s, int e) {  // get hash value of the substring [s, e)
    ll H[2];
    forn(i, 2) {
      H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
      H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
    }
    return (H[0] << 32) | H[1];
  }
};

void solve() {
    ll n; cin >> n;
    ll res = n;
    ll a[n]; fr(0,n) cin >> a[i];
    string s;
    fr(0,n-1){
        if (a[i]<a[i+1]){
            s.pb('0');
        } else {
            s.pb('1');
        }
    }
    string t;
    fre(s){
        if (e == '1'){
            t.pb('0');
        } else {
            t.pb('1');
        }
    }
    Hash hs = Hash(s);
    reverse(t.begin(),t.end());
    Hash ht = Hash(t);
    // cout << "s = " << s << endl;
    // cout << "t = " << t << endl;
    n--;
    // cout << "n = " << n << endl;
    fr(0,n-1){
        if (s[i]==s[i+1]){
            continue;
        }
        // cout << "I = " << i << " y " << i+1 << endl;
        //se que matchea al menos 1
        //aca me fijo como que el largo de a parejas
        ll l = 1;
        ll r = min(i+1, n-i);
        int cur = 1;
        //tengo que ver hasta cuando puedo estirar el hash con busqueda binaria. 
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout << "pruebo mid = " << mid << endl; 
            // cout << "get en hs desde " << i-mid+1 << " hasta " << i+1+mid;
            // cout << "get en ht desde " << n-i-1-mid+1 << " hasta " << n-i+mid;
            if (hs.get(i-mid+1, i+1+mid) == ht.get(n-i-1-mid, n-i-1+mid)){
                // cout << "iguales\n";
                cur = mid;
                l = mid+1;
            } else {
                // cout << "distintos\n";
                r = mid-1;
            }
        }
        // cout <<"sumo cur =" << cur << endl;
        // cout << "cur = " << cur << endl;
        res+=cur;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}