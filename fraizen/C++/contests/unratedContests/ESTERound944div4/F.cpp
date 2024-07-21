#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define ld long double

ll dist(ll x1, ll y1){
    return y1*y1 + x1*x1;
}

// Copiar obligatoriamente 0
void solve() {
    ll r; cin >> r;
    ll fraizen = (r+1)*(r+1);
    ll valid = 0;
    rep(x,1,r+1){
        ll y = ll(sqrt(fraizen - x*x) + 1);
        double d = x*x+y*y;
        while(d >= fraizen){
            y--;
            d = x*x+y*y;
        }
        while(y>=0){
            d = x*x+y*y;
            if (d >= r*r){
                valid++;
                y--;
            } else {
                break;
            }
        }
    }
    cout << valid * 4 << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}