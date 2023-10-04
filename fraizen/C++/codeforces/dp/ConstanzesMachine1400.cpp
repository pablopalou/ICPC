#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

void solve(string s) {
    int n = s.length();
    vector<ll> dp(n+10);
    dp[0] = 1;
    char ant = '4';
    fr(0,n){
        if (s[i] == 'm' || s[i] == 'w'){
            cout(0);
            return;
        }
        if (s[i] == 'n' && ant == 'n' || s[i] == 'u' && ant == 'u'){
            dp[i+1] = (dp[i] + dp[i-1]) % mod;
        } else {
            dp[i+1] = dp[i];
        }
        ant = s[i];
    }
    cout(dp[n]);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    // devolver con mod
    string s;
    cin >> s;
    solve(s);
}