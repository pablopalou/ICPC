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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    ll n; cin >> n;
    ll num[n+5]; memset(num, 0,sizeof(num));
    ll den[n+5]; memset(den, 1,sizeof(den));
    num[1] = 1; den[1] = 2;
    fr(2,n+1){
        num[i] = den[i-1];
        den[i] = den[i-1]+num[i-1];
    }
    int dividir = gcd(num[n],den[n]);
    cout << num[n]/dividir << '\n';
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