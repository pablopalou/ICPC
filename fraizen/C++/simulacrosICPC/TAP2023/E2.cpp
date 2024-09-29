#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
ll aof,rof;

bool isAlmostInteger(double x, double epsilon = 1e-9) {
    double rounded = round(x);
    return abs(x - rounded) < epsilon;
}

bool check(ll d, ll x1, ll s) {
    ll a=d, b=(2*x1)-d, c=-2*s;
    ll r = (b*b)-4*a*c;
    if (r < 0) return false;
    long double rsqrt = sqrtl(r);
    if (rsqrt != ll(rsqrt)) return false;
    long double r1 = (d-(2*x1)+rsqrt)/(2*d);
    long double r2 = (d-(2*x1)-rsqrt)/(2*d);
    return (isAlmostInteger(r1) && round(r1)>0 && (x1 + (d*(round(r1)-1)) >= aof) && (x1 + (d*(round(r1)-1)) <= rof)) 
    || (isAlmostInteger(r2) && round(r2)>0 && (x1 + (d*(round(r2)-1)) >= aof) && (x1 + (d*(round(r2)-1)) <= rof));
}

void solve() {
    ll s,l; cin>>aof>>s>>l>>rof;
    ll res = 0;
    if (aof==s) {
        cout(1);
        return;
    }
    ll k = rof-l;
    for(ll d=1; d<=k; d++) {
        for(ll x1=aof; x1>=l; x1-=d) {
            if (check(d,x1,s)) res++;
        }
    }
    cout(res);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
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