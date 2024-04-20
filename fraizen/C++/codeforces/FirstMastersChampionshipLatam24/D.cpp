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
    ll h; ll minutos; cin >> h >> minutos;
    ll m = 60*h + minutos;
    ll n; cin >> n;
    ll a[n], b[n];
    fr(0,n){
        ll x,y; 
        cin >> a[i] >> b[i];
        if (i > 0){
            a[i] += a[i-1];
        }
    }
    m = min(m, a[n-1]);
    ll res = 0;
    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int pos = -1;
    for(int i = n-1; i>=0; i--){
        if (m >= a[i]){
            pos = i;
        }
    }
    if (pos < n-1){
        pos++;
    }   
    // cout << pos << endl;
    for(int i = pos; i>=1; i--){
        res+= (m-a[i-1]) * b[i];
        a[i] = m;
    }

    res += min(m,a[0]) * b[0];

    cout << res << "\n";
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