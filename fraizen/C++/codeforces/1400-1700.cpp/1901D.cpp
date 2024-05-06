#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    ll pre[n], suf[n];
    fr(0,n){
        pre[i] = n-i-1 + a[i];
        suf[i] = i + a[i];
    }
    fr(1,n){
        pre[i] = max(pre[i], pre[i-1]);
    }
    for(int i = n-2; i>=0; i--){
        suf[i] = max(suf[i], suf[i+1]);
    }
    ll ans = 1e18;
    //veo de donde arranco
    fr(0,n){
        ll cur = a[i];
        if (i > 0){ //tengo que matar a los de la izquierda
            cur = max(cur, pre[i-1]);
        }
        if (i < n-1){ //tengo que matar a los de la derecha
            cur = max(cur, suf[i+1]);
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
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