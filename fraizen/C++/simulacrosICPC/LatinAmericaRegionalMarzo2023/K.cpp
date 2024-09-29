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

const int MAXN=100, K=12;
int ans[MAXN][MAXN],am[1<<K],total,k,tot;
vector<ii> res[MAXN*MAXN];

void print_ans(){
	// fore(x,0,tot) fore(i,0,MAXN) fore(j,0,MAXN) if(ans[i][j]&(1<<x)){
	// 	res[x].pb({i,j});
	// }
	
	// cout<<tot<<"\n";
	// fore(i,0,tot){
	// 	vector<int> to={SZ(res[i])};
	// 	for(auto x:res[i]) to.pb(x.fst+1), to.pb(x.snd+1);
	// 	fore(i,0,SZ(to))cout<<to[i]<<" \n"[i+1==SZ(to)];
	// }
	
	// exit(0);
}

void rem(int val){
	total-=am[val]==1;
	am[val]--;
}

void add(int val){
	total+=am[val]==0;
	am[val]++;
	if(total==k) print_ans();
}

int main(){FIN;
	cin>>k;
	int pw=1;
	while(pw<k) pw*=2,tot++;
	int n=tot/2, m=(tot+1)/2;
	
	if(k==1){
		cout<<"0\n";
		exit(0);
	}
	
	total=1;
	am[0]=MAXN*MAXN;
	
	//first row and column
	fore(x,0,tot) fore(i,0,MAXN) fore(j,0,MAXN) if(!i||!j){
		rem(ans[i][j]);
		ans[i][j]|=1<<x;
		add(ans[i][j]);
	}
	
	//rows
	fore(x,0,n) fore(i,1,MAXN) fore(j,1,MAXN) if(i&(1<<x)){
		rem(ans[i][j]);
		ans[i][j]|=1<<x;
		add(ans[i][j]);
	}

	//columns
	fore(x,0,m) fore(i,1,MAXN) fore(j,1,MAXN) if(j&(1<<x)){
		rem(ans[i][j]);
		ans[i][j]|=1<<(n+x);
		add(ans[i][j]);
	}

    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}