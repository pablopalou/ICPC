#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int maxn = 1001000;

void solve() {
    ll n,m,k; cin >> n >>m>>k;
    ll a[maxn]; fr(0,n) cin >> a[i];
    a[n] = 0;
    tuple<ll,ll,ll> t[m]; 
    fr(0,m){
        ll l,r,v; cin >> l >> r >> v;
        t[i] = {l,r,v};
    }
    ll cant[maxn];
    memset(cant, 0LL, sizeof(cant));
    fr(0,k){
        ll x, y; cin >> x >> y;
        cant[x]+=1;
        cant[y+1]-=1;
    }
    fr(1,n+4){
        cant[i] += cant[i-1];
    }
    ll fraizen[maxn]; memset(fraizen, 0LL, sizeof(fraizen));
    fr(0,m){
        ll l1 = get<0>(t[i]);
        ll r1 = get<1>(t[i]);
        ll v1 = get<2>(t[i]);
        fraizen[l1] += cant[i+1] * v1;
        // cout << "agrego " << cant[i] * v << endl;
        fraizen[r1+1] -= cant[i+1] * v1;
    }
    fr(1,n+4){
        fraizen[i] += fraizen[i-1];
    }
    fr(0,n){
        cout << a[i]+fraizen[i+1] << ' ';
    }
    cout << '\n';
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