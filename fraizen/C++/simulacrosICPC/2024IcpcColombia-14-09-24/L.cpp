#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

void solve() {
    string s; cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper); 
    int n = s.size();
    int l = 0;
    int r = n-1;
    int res = 0;
    while(l < r){
        if ((s[l] == '3' && s[r] =='E') or (s[l] == 'E' && s[r] =='3') or (s[l] == '6' && s[r] =='9') or (s[l] == '9' && s[r] =='6')){
            //no hago nada
        } else if ((s[l] == s[r]) && ((s[l] == '0') or (s[l] == '1') or (s[l] == '2') or (s[l] == '5') or (s[l] == '8'))){
            //no hago nada
        } else if (s[l] == '3' or s[l] == 'E' or s[l] == '6' or s[l] == '9' or (s[l] == '0') or (s[l] == '1') or (s[l] == '2') or (s[l] == '5') or (s[l] == '8') or s[r] == '3' or s[r] == 'E' or s[r] == '6' or s[r] == '9' or (s[r] == '0') or (s[r] == '1') or (s[r] == '2') or (s[r] == '5') or (s[r] == '8')){
            res++;
        } else {
            res+=2;
        }
        l++;
        r--;
    }
    if (n % 2 == 1){
        if (((s[n/2] == '0') or (s[n/2] == '1') or (s[n/2] == '2') or (s[n/2] == '5') or (s[n/2] == '8'))){

        } else {
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

    int cases = 1;
    // cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}