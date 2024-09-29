#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[3005][3005];
string s,t; 

ll f(int i, int j){
    if (i == s.size() or j==t.size()){
        return 0;
    }
    ll &res = dp[i][j];
    if (res!=-1) return res;
    return res = max({f(i+1, j), f(i, j+1), f(i+1,j+1) + (s[i]==t[j])});
}

void solve() {
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    ll res = f(0,0);
    int i = 0; int j = 0;
    while(res){
        if (f(i,j+1) == res){
            j++;
        } else if (f(i+1,j) == res){
            i++;
        } else if (f(i+1, j+1) == (res-1)){
            cout << s[i]; i++; j++; res--;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}