#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

//por temas de precision esto es imposible, dejaron que hackers metan tests que deberiamos lidiar con una precision de abundantes decimales
// https://codeforces.com/blog/entry/117430
// https://codeforces.com/blog/entry/67743?#comment-1028372
void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    long double res = 0.0;
    fr(0,n){
        rep(j,i+1,n){
            ll k = 0;
            if (a[i] <= a[j]){
                // cout << "opt 1" << endl;
                k = a[i]*(a[i]-1)/2;
            } else {
                k = a[j]*(a[j]-1)/2;
                // cout << "K here " << k << endl;
                k += (a[i]-a[j]) * a[j];
            }
            res += (double)k / (a[i]*a[j]);
        }
    }
    cout << fixed << setprecision(6) << res;
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