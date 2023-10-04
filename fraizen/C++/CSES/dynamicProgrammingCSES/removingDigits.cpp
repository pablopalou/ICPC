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
int dp[MAXN];

void solve(int n) {
    fr(1,n+1){
        for (char c: to_string(i)){
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < MAXN; ++i) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    int n;
    cin >> n;
    
    solve(n);
    cout << dp[n] << "\n";
}