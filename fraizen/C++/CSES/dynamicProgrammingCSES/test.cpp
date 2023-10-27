#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
int dp[1010][1010];
string s[1010];
 
int main(){FIN;
	int n,m,ans=0; cin>>n>>m;
	fore(i,0,n) cin>>s[i];
	fore(i,0,n) fore(j,0,m){
		bool up=i&&j&&s[i-1][j]==s[i-1][j-1];
		bool dw=j&&s[i][j-1]==s[i][j];
		if(up&&dw) dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
		else dp[i][j]=1;
		ans=max(ans,dp[i][j]);
	}
    // print matrix
    fore(i,0,n){
        fore(j,0,m){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
	cout << ans*ans << "\n";
}