#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll res = 0;
    // fr(0,200){
    //     cout << i * i << endl;
    // }
    // cout << endl;
    fr(0,s.size()){
        // cout << s[i] << endl;
        if (s[i] == '1' or s[i] == '2' or s[i] == '3' or s[i] == '4' or s[i] == '5' or s[i] == '7' or s[i] == '9'){
            res++;
        }
    }
    cout << res << '\n';
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases=1;
    // cin >> cases;
    while(cases--) {
        solve();
    }
}