#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#define MAXN 16
#else
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } 

int main()
{
	// agregar g++ -DANARAP en compilacion
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> va(n), vb(n);
	forn(i,n) cin >> va[i] >> vb[i];
	int gcdall = vb[0];
	forn(i,n) gcdall = gcd(gcdall, vb[i]);
	vector<int> vcnt(MAXN, 0);
	forn(i,n) vcnt[va[i]]++;
	bitset<MAXN> dp;
	dp.set(0);
	forn(i,MAXN) if(vcnt[i]) {
		int e = 0;
		while((1<<(e+1))-1 <= vcnt[i]) {
			dp |= dp << (i * (1<<e));
			// cout << i << ' ' << e << ": " << dp << '\n';
			e++;
		}
		vcnt[i] -= (1<<e)-1;
		dp |= dp << (i*vcnt[i]);
		// cout << "extra " << i << ' ' << vcnt[i] << ": " << dp << '\n';
	}
	int tot = 0;
	bool has0 = false;
	forn(i,n) tot += va[i];
	forn(i,n) if(va[i] == 0) has0 = true;
	bool ok = false;
	//forn(i,tot+1) cout << i << ": " << dp[i] << '\n';
	forn(i,tot+1) if(dp[i]) {
		if(i == 0 && !has0) continue;
		if(i == tot && !has0) continue;
		if(abs(i - (tot-i))%gcdall) continue;
		ok = true;
	}
	if(ok) cout << "Y\n";
	else cout << "N\n";
	return 0;
}
