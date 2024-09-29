#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[19];

ll count(ll num){
    if (num < 1){
        return num == 0? 1: 0;
    }
    string numString = to_string(num);
    ll res = 0;
    fr(0,numString.size()){
        res += dp[i];
    }
    ll prev = 0;
    fr(0,numString.size()){
        ll digit = numString[i] - '0';
        ll diff = numString.size() - i - 1;
        ll below = prev < digit ? digit-1: digit;
        res += (digit == 0) ? 0 : below * dp[diff];
        if (digit == prev){
            return res;
        }
        prev = digit;
    }
    return res + 1;
}

void solve() {
    ll a,b; cin >> a >> b;
    dp[0] = 1;
    fr(1,20){//deberia ser hasta 19 este for me parece, pero dio ac asi que queda asi
        dp[i] = 9 * dp[i-1];
    }

    cout << count(b) - count(a-1) << '\n'; 
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