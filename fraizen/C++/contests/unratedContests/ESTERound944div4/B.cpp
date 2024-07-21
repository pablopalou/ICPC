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
    set<char> st;
    fr(0,s.size()){
        st.insert(s[i]);
    }
    if (st.size() == 1){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    fr(1,s.size()){
        if (s[i] != s[0]){
            cout << s[i] << s.substr(1,i-1) << s[0] << s.substr(i+1) << '\n';
            return;
        }
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