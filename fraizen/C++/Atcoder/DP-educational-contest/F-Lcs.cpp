#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

string s, t;
const int MAXN = 3005;
ll dp[MAXN][MAXN];

ll f(ll i, ll j){
    if (i == s.size() || j == t.size()){
        return 0;
    }
    ll &res = dp[i][j];
    if (res != -1) return res;
    res = max(f(i+1,j),f(i,j+1));
    if ( s[i] == t[j]){
        res = max(res, f(i+1,j+1) + 1);
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    //reconstruir respuesta.
    ll res = f(0,0);
    ll l = 0, r = 0;
    while(res){
        if (f(l,r+1) == res){
            r++;
        } else if (f(l+1, r) == res){
            l++;
        } else {
            cout << s[l]; l++; r++;
            res--;
        }
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