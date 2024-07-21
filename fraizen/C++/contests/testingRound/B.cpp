#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back


void solve() {
    int n; cin >> n;
    if (n%10 == 9){
        cout << "NO\n"; return;
    }
    string s = to_string(n);
    if (s[0] != '1'){
        cout << "NO\n"; return;
    }
    fr(0,s.size()-1){
        if (s[i] == '0'){
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n"; return;
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