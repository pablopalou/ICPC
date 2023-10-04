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
ll coins[105];
ll dp[MAXN];

void solve(ll n, ll x){
    fr(1,x+1){
        rep(j,0,n){
            if (i > coins[j]){
                dp[i] += dp[i-coins[j]] % mod;
                dp[i] %= mod;
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
    ll n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    solve(n, x);
    cout(dp[x]);
}