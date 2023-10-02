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
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008
int coins[105];
int dp[105][MAXN];

void solve(int n, int x){
    fr(1,n+1){
        rep(j,0,x+1){
            dp[i][j] = dp[i-1][j];
            if (j-coins[i-1] >= 0){
                dp[i][j] += dp[i][j-coins[i-1]] % mod;
                dp[i][j]%=mod;
            }
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    int n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
    }
    solve(n, x);
    int res = dp[n][x];
    cout << res << "\n";
}