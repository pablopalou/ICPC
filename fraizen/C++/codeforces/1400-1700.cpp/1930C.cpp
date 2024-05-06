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
    int n; cin>>n; 
    int a[n+1];
    fr(1,n+1){
        int num; cin >> num;
        a[i] = num + i;
    }
    sort(a+1, a+n+1, greater<int>());
    // vector<int> res;
    // set<int> s;
    int minimo = 2e9+1;
    fr(1,n+1){
        cout << min(minimo-1, a[i])<< ' ';
        minimo = min(minimo-1, a[i]);
        // if (find(s.begin(), s.end(), a[i]) == s.end()){
        //     res.pb(a[i]);
        //     minimo = a[i];
        //     s.insert(a[i]);
        // } else {
        //     res.pb(minimo-1);
        //     s.insert(minimo-1);
        //     minimo--;
        // }
    }
    // fr(0,res.size()){
    //     cout << res[i] << ' ';
    // }
    cout << "\n";
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