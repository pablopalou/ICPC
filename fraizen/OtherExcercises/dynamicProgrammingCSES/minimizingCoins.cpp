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
#define mod 1e9+7
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008
ll dp[MAXN];
ll coins[105];

void solve(ll n, ll x) {
    ll minCant;
    fr(1,x+1){
        if (dp[i] == 1){continue;}
        minCant = inf;
        rep(j,0,n){
            if (i > coins[j]){
                minCant = min(minCant, dp[i-coins[j]] + 1);
            }
        }
        dp[i] = minCant;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp, 0, sizeof dp);
    ll n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    solve(n,x);

    if (dp[x] == 0 || dp[x] == inf){
        cout("-1");
    } else {
        cout(dp[x]);
    }
}