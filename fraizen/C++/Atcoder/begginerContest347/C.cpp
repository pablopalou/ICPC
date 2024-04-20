#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    int n, a, b; cin >> n >> a >> b;
    int d[n];
    fr(0,n){
        cin >> d[i];
    }
    fr(0,n){
        d[i] %= (a+b);
    }
    int mini = d[0];
    int maxi = d[0];
    fr(1,n){
        mini = min(mini, d[i]);
        maxi = max(maxi, d[i]);
    }
    // fr(0,n){
    //     cout << d[i] << ' ';
    // }
    // cout << endl;
    // cout << maxi << endl;
    // cout << mini << endl;
    // cout << maxi-mini+1 << endl;
    int minDif = maxi-mini+1;
    sort(d,d+n);
    fr(1,n){
        minDif = min(minDif, a+b - d[i] + d[i-1] + 1);
    }
    if (minDif <= a){
        cout << "Yes\n";
    } else {
        cout << "No\n"; 
    }
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