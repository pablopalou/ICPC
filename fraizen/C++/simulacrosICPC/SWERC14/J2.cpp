#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define rsz resize

// P should be a prime number, could be randomly generated,
// sometimes is good to make it close to alphabet size
// MOD[i] must be a prime of this order, could be randomly generated
const int P = 1777771, MOD[1] = {999727999};
const int PI[1] = {325255434};  // PI[i] = P^-1 % MOD[i]
struct Hash {
  vector<int> h[1], pi[1];
  vector<ll> vp[1];  // Only used if getChanged is used (delete it if not)
  Hash(string& s) {
    forn(k, 1) h[k].rsz(s.size() + 1), pi[k].rsz(s.size() + 1),
        vp[k].rsz(s.size() + 1);
    forn(k, 1) {
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
    ll H[1];
    forn(i, 1) {
      H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
      H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
    }
    return H[0];
  }
};

void solve() {
    int hp, wp, hm, wm; cin>>hp>>wp>>hm>>wm;
    string hash;
    fr(0, hp) {
        string s; cin>>s;
        // cout << s << endl;
        Hash h = Hash(s);
        hash.append(to_string(h.get(0, s.size())));
        // cout << "hash: " << to_string(h.get(0, s.size())) << endl;
    }
    ll hash_patron = Hash(hash).get(0, hash.size());
    // cout << hash_patron << endl;
    ll m[hm][wm];
    ll m2[hm][wm];
    fr(0, hm) {
        string s; cin>>s;
        // cout << s << endl;
        Hash h = Hash(s);
        rep(j, 0, wm-wp+1) {
            // if(i==0) cout << "f: " << h.get(j, j+wp) << endl;
            m[i][j] = h.get(j, j+wp);
        }
    }
    // cout << hash_patron << endl;
    rep(j, 0, wm-wp+1) {
        string s;
        ll largos[hm+1];
        largos[0] = 0;
        rep(i, 0, hm) {
            s.append(to_string(m[i][j]));
            largos[i+1] = s.size();
            // cout << "largo " << i+1 << ": " << largos[i+1] << endl;
        }
        // cout << "S = " << s << endl;
        Hash h = Hash(s);
        rep(i, 0, hm-hp+1) {
            // cout << "I = "<<i << endl;
            m2[i][j] = h.get(largos[i], largos[i+hp]);
        }
    }
    // cout << "aca " << m[0][6] << endl;
    int res = 0;
    fr(0, hm - hp + 1) {
        rep(j, 0, wm - wp + 1) {
            // cout << m2[i][j] << endl;
            if (m2[i][j] == hash_patron) res++;
        }
    }
    cout(res);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
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