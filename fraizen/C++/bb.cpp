#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
// #define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)

vi adj[100005];
vi p;
void dfs(int s){
    while(size(adj[s])){
        int u = adj[s].back(); adj[s].pop_back();
        dfs(u);
    }
    p.pb(s);
}

void solve(){
    int n,m;
    cin >> n >> m;
    int in[n+1];
    int out[n+1];
    fr(0, n+1) {in[i] = 0; out[i]=0;}
    rep(i,0,m){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        in[y]++, out[x]++;
    }
    int a=0,b=0,c=0,s1=0,s2=0;
    rep(i,1,n+1){
        if (in[i]==out[i]) c++;
        if (in[i]-out[i]==1) {b++;; s2=i;}
        if (in[i]-out[i]==-1) {a++; s1=i;}
    }
    if (s1!=1 || s2!=n){cout("IMPOSSIBLE"); return;}
    if (!(c==n-2 && a==1 && b==1)){cout("IMPOSSIBLE"); return;}
    dfs(1);
    if (size(p)!=m+1) {cout("IMPOSSIBLE"); return;}
    reverse(p.begin(), p.end());
    for (auto i: p) cout << i << " ";
}    

signed main(){
    solve();
}