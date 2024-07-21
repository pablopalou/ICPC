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

const int P = 1777771, MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};  // PI[i] = P^-1 % MOD[i]
struct Hash {
  vector<int> h[2], pi[2];
  vector<ll> vp[2];  // Only used if getChanged is used (delete it if not)
  Hash(vector<int>& s) {
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
    int n,m; cin >> n >>m;
    string s; cin >> s;
    //hago los 26 strings binarios y los hasheo
    // vector<vector<int>> sBinario(n,);
    // aaabbc
    // a => 111000
    // b => 000110
    // c => 000001
    vector<vector<int>> letra(26, vector<int>(n,0));
    fr(0,n){
        letra[s[i]-'a'][i] = 1;
    }
    vector<Hash> v;
    fr(0,26){
        // Hash h(letra[i]);
        v.pb(Hash(letra[i]));
    }
    // fre(letra){
    //     for(auto e2: e){
    //         cout << e2 << ' ';
    //     }
    //     cout << endl;
    // }
    fr(0,m){
        int x,y, largo; cin >> x >> y >> largo;x--;y--;
        //aca ya tengo los dos substrings, entonces tengo que agarrar los hashes y meterlos en un vector
        vector<ll> hashes1;
        vector<ll> hashes2;
        rep(j,0,26){
            hashes1.pb(v[j].get(x, x+largo));
            hashes2.pb(v[j].get(y, y+largo));
        }
        sort(hashes1.begin(), hashes1.end());
        sort(hashes2.begin(), hashes2.end());
        //los ordeno y comparo todos
        bool salir = false;
        rep(j,0,26){
            if (hashes1[j] != hashes2[j]){
                cout << "NO\n"; salir = true; break;
            }
        }
        if (salir){
            continue;
        }
        cout << "YES\n";
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