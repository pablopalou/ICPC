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
#define MAXN 17
ll mat[MAXN][MAXN];
ll n; 
ll valor[(1<<MAXN)];
ll dp[1<<MAXN];

ll score(int mask){
    vector<int> prendidos;
    fr(0,17){
        if ( (mask & (1<<i)) != 0){
            prendidos.pb(i);
        }
    }
    ll ans = 0;
    fr(0,prendidos.size()){
        rep(j,i+1,prendidos.size()){
            int primero = prendidos[i];
            int segundo = prendidos[j];
            ans += mat[primero][segundo];
        }
    }
    return ans;
}

ll f(int mask){
    if (mask == 0) return 0;
    ll &res = dp[mask];
    if (res!=-1) return res;
    res = 0;
    //recorro cada submascara de forma eficiente y me quedo con el mejor puntaje
    for (int submask = mask; submask;submask=(submask-1)&mask){
        res = max(res, valor[submask] + f(submask ^ mask));
    }
    return res;
}

void solve() {
    cin >> n;
    fr(0,n){
        rep(j,0,n){
            cin >> mat[i][j];
        }
    }
    valor[0] = 0;
    fr(1, (1<<n)){
        valor[i] = score(i);
    }
    memset(dp, -1, sizeof(dp));
    cout << f((1<<n)-1); //llamo con todo libre
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