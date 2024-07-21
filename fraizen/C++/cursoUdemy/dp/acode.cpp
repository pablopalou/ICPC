#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
string s;
vector<int> dp;

int fillDP(int i){
    if (i == s.size()) return 1;
    int &ans = dp[i];
    if (s[i] == '0') return 0;
    if (ans != -1){
        return ans;
    }
    ans = 0;
    if (s[i] >= '0'){
        ans += fillDP(i+1);
    }
    if (i+1 < s.size() && s[i] == '1'){
        ans += fillDP(i+2);
    }
    if (i+1 < s.size() && s[i] == '2' && (s[i+1] <= '6')){
        ans += fillDP(i+2);
    }
    return ans;
}

void solve() {
    while(true){
        cin >> s;
        if (s == "0") break;
        dp.assign(s.size(), -1);
        cout << fillDP(0) << '\n';
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