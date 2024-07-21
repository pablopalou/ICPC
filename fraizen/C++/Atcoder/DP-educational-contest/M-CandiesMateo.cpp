#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;
#define mod MOD

ll dp[105][100005];
ll n,k;
ll ps[105][100005];
ll a[105];

// ll f(ll x, ll cant){
// 	ll &res=dp[x][cant];
// 	if(res>=0)return res;
// 	if(x==n){
// 		if(cant==0){
// 			res=1; return res;
// 		}
// 		res=0; return res;
// 	}
// 	res=(ps[x+1][cant+1]-ps[x+1][max(0ll,cant-a[x])]+MOD)%MOD;
// 	return res;
// }

ll f(ll x, ll cant){
    ll &res = dp[x][cant];
    if (res != -1) return res;
    if (x == n && cant == 0) return 1;
    if (x == n) return 0;
    //asumo que ya tengo ps entonces seria solo hacer esa cuenta.
    res = ((ps[x+1][cant] - ps[x+1][max(0ll,cant-1-a[x])]) + mod )% mod;
    return res;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	fore(i,0,n+1){
		fore(j,1,k+2){
			ps[n-i][j]=f(n-i,j-1)+ps[n-i][j-1];
			if(ps[n-i][j]>MOD)ps[n-i][j]-=MOD;
		}
	}
	fore(i,0,n+1){
		fore(j,0,k+2){
			cout<<ps[i][j]<<" ";
		}
		cout<<"\n";
	}
	fore(i,0,n+1){
		fore(j,0,k+1){
			cout<<f(i,j)<<" ";
		}
		cout<<"\n";
	}
	cout<<f(0,k);
	return 0;
}