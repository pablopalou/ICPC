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
ll dp[MAXN];

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n = n / 2;
    }
    return res % mod;
}

void solve(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 6;
    fr(4,n+1){
        dp[i] = (dp[i-1] + dp[i-2] + 2) %mod;
        // dp[i] = (dp[i]%mod + (modular_expo(2,n-3) % mod - 1) %mod) % mod;
    }
    cout(dp[n]);
    return;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    ll n;
    cin >> n;
    solve(n);
}