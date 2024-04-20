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
    int n,m; cin >>n>>m;
    int a[n];
    fr(0,n) cin >>a[i];
    int l = 0;
    int r = n-1;
    string s; cin >> s;
    fr(0,s.size()-1){
        if (s[i] == 'L'){
            l++;
        } else {
            r--;
        }
    }
    vector<int> res;
    res.pb(a[l]%m);
    int cur = a[l] % m;
    int indexIzq = l;
    int indexDer = r;
    for (int i = n-2; i>=0; i--){
        if (s[i] == 'L'){
            indexIzq--;
            cur = (cur * (a[indexIzq] % m)) %m;
        } else {
            indexDer++;
            cur = (cur * (a[indexDer] % m)) %m;
        }
        res.pb(cur);
    }   
    reverse(res.begin(), res.end());
    fr(0,res.size()){
        cout << res[i] << " ";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}