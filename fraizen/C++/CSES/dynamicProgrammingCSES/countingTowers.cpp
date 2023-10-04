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
#define MAXN 1000003
ll dp[MAXN][2];

void solve() {
    fr(2,MAXN){
        dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][1] * 4 + dp[i-1][0]) % mod;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int cases;
    cin >> cases;
    
    dp[1][0] = 1;
    dp[1][1] = 1;

    // precomputo todo
    solve();
    while(cases--){
        ll n;
        cin >> n;
        ll res = (dp[n][0] + dp[n][1]) % mod;
        cout << res << "\n";
    }
}