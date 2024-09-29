#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007

void solve() {
    string s; cin >> s;
    ll res = 1;
    fr(0,s.size()){
        if (s[i] == 'S'){
            if (i+1 < s.size() && (s[i+1] == 'E' or s[i+1] == 'W')){
                res = (res * 2) % mod;
            }
        } else if (s[i] == 'N'){
            if (i+1 < s.size() && (s[i+1] == 'E' or s[i+1] == 'W')){
                res = (res * 2) % mod;
            }
        }
    }
    cout << res << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // #ifdef JP
    //     freopen("A.in", "r", stdin);
    //     freopen("A.out", "w", stdout);
	// #endif
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);

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