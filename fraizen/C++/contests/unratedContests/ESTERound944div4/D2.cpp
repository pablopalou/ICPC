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
    string s; cin >> s;
    int n = s.size();
    char ant = s[0];
    int res = 0;
    fr(1,n){
        if (s[i] != ant){
            res++;
            ant = s[i];
        }
    }
    bool fraizen = false;
    fr(0,n-1){
        if (s[i] == '0' && s[i+1] == '1'){
            fraizen = true;
        }
    }
    if (fraizen){
        cout << res << '\n';
    } else {
        cout << res + 1 << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}