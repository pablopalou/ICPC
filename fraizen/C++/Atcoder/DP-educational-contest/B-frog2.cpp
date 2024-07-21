#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll n,k;
ll h[100005];

ll dp[100005];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==n-1)return 0;
    res = f(x+1)+abs(h[x+1]-h[x]);
    fr(2,k+1){
        if ((x+i) <= n-1){
	        res=min(res,f(x+i)+abs(h[x+i]-h[x]));
        } else {
            break;
        }
    }
	return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin>>n>>k;
	fr(0,n)cin>>h[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(0)<<"\n";
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

