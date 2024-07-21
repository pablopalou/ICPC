#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    fr(0, n) {
        cin >> a[i];
    }
    
    bool hasOne = false;
    fr(0, n) {
        if (a[i] == 1) {
            hasOne = true;
            break;
        }
    }
    if (hasOne) {
        cout << "Yes\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<ll> faltan;
    fr(1, n) {
        if (a[i] % a[0] != 0){
            faltan.pb(a[i]);
        }
    }

    sort(faltan.begin(), faltan.end());
    fr(1, faltan.size()){
        if (faltan[i] % faltan[0] != 0){
            cout << "No\n"; return;
        }
    }
    cout << "Yes\n"; return;
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