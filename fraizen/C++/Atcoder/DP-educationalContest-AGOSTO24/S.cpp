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
#define MAXN 10003
#define MAXD 105
ll dp[MAXN][MAXD][2];
#define mod 1000000007
string s; int d;

ll contar(int i, int modulo, bool menor, int cur){
    if (i == s.size()){
        if (modulo == 0){
            return 1;
        } else {
            return 0;
        }
    }
    ll &res = dp[i][modulo][menor];
    if (res!=-1) return res;
    
    int lo = 0;
    int maxi = s[i] - '0';
    if (menor){
        maxi = 9;
    }
    
    res = 0;
    rep(j,lo, maxi+1){
        res = (res + (contar(i+1, (modulo + j) % d, menor or (j < maxi),j)) % mod) % mod;
    }
    return dp[i][modulo][menor] = res;
}

void solve() {
    cin >> s; cin >> d;
    int digits = s.size();
    memset(dp, -1, sizeof(dp));
    cout << ((contar(0,0,false,-1) - 1) + mod) % mod;    
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