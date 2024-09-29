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
#define MAXN 404
#define inf 4e18
ll dp[2][MAXN][MAXN];
bool seen[2][MAXN][MAXN];
vector<int> v;
vector<char> s;
int n;

ll f(int l, int r, bool maximizar){
    if (l == r){
        return v[l];
    }
    if (seen[maximizar][l][r]) return dp[maximizar][l][r];
    seen[maximizar][l][r] = true;
    ll &res = dp[maximizar][l][r];
    if (maximizar){
        res = -inf;
        fr(l,r){
            if (s[i] == '-'){
                ll resta = f(l,i,1) - f(i+1,r,0);
                res = max(res, resta);
                continue;
            } 
            if (s[i] == '+') {
                ll suma = f(l,i,1) + f(i+1,r,1);
                res = max(res, suma);
                continue;    
            }
            if (s[i] == '*') {
                ll multi = max({f(l,i,1) * f(i+1,r,1), f(l,i,1) * f(i+1,r,0), f(l,i,0) * f(i+1,r,1), f(l,i,0) * f(i+1,r,0)});
                res = max(res, multi);
                continue;    
            }
            ll resta = f(l,i,1) - f(i+1,r,0);
            ll multi = max({f(l,i,1) * f(i+1,r,1), f(l,i,1) * f(i+1,r,0), f(l,i,0) * f(i+1,r,1), f(l,i,0) * f(i+1,r,0)});
            ll suma = f(l,i,1) + f(i+1,r,1);
            res = max(res, max({resta, suma, multi}));
        }
    } else {
        res = inf;
        fr(l,r){
            if (s[i] == '-') {
                ll resta = f(l,i,0) - f(i+1,r,1);
                res = min(res, resta);
                continue;
            }
            if (s[i] == '+') {
                ll suma = f(l,i,0) + f(i+1,r,0);
                res = min(res, suma);
                continue;
            }
            if (s[i] == '*')  {
                ll multi = min({f(l,i,1) * f(i+1,r,1), f(l,i,1) * f(i+1,r,0), f(l,i,0) * f(i+1,r,1), f(l,i,0) * f(i+1,r,0)});
                res = min(res, multi); continue;
            }
            ll resta = f(l,i,0) - f(i+1,r,1);
            ll suma = f(l,i,0) + f(i+1,r,0);
            ll multi = min({f(l,i,1) * f(i+1,r,1), f(l,i,1) * f(i+1,r,0), f(l,i,0) * f(i+1,r,1), f(l,i,0) * f(i+1,r,0)});
            if (s[i] == '?') res = min(res, min({resta, suma, multi}));
        }
    }
    return res;
}

void solve() {
    fr(0,MAXN){
        rep(j,0,MAXN){
            seen[0][i][j] = false;
            seen[1][i][j] = false;
        }
    }    
    cin >> n;
    v.resize(2*n); s.resize(2*n);
    fr(0,n){
        cin >> v[i]; v[i+n] = v[i];
        cin >> s[i]; s[i+n] = s[i];
    }
    fr(0,n){
        cout << abs(f(i,i+n-1, 0)) << abs(f(i, i+n-1, 1));
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