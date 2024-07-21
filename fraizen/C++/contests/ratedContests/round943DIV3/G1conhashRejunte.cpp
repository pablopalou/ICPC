#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
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
  // get hash value of [s, e) if origVal in pos is changed to val
  // Assumes s <= pos < e. If multiple changes are needed,
  // do what is done in the for loop for every change
  ll getChanged(int s, int e, int pos, int val, int origVal) {
    ll hv = get(s, e), hh[2];
    hh[1] = hv & ((1LL << 32) - 1);
    hh[0] = hv >> 32;
    forn(i, 2) hh[i] = (hh[i] + vp[i][pos] * (val - origVal + MOD[i])) % MOD[i];
    return (hh[0] << 32) | hh[1];
  }
};

// Copiar obligatoriamente 0
void solve() {
    int n,k,k2; cin >> n >> k>>k2;
    int l = 0; int r = n/k;
    string s; cin >> s;
    Hash hs(s);
    int res = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        int i = 0;
        int cant = 0;
        while(i < n){
            if (i + mid > n) break;
            if (hs.get(i, i+mid) == hs.get(0,mid)){
                cant++;
                i+=mid;
                if (mid == 0){
                    i++;
                }
            } else {
                i++;
            }
        }
        if (cant >= k){
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << res << "\n";
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
