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
int dp[502][504*504/4];

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve(int n) {
    int m = (n * (n+1)) / 4;
    ll inversoModularDe2 = ll(inv(2));
    fr(1,n+1){
        rep(j,1,min(m+1, i * (i+1) / 2 + 1)){
            // cout << i  << ',' << j << "\n";
            if (j < i){
                dp[i][j] = dp[i-1][j] % mod;
            } else if (i == j){
                dp[i][j] = (dp[i-1][j] + 1) % mod;
            } else {
                dp[i][j] = (dp[i-1][j] % mod + dp[i-1][j-i] % mod) % mod;
            }
        }
    }
    // cout((dp[n][m] * 500000004ll) % mod); // Multiply by 500000004, which is (mod + 1) / 2 (modular inverse of 2 under the modulo 1e9+7)
    cout((dp[n][m] * inversoModularDe2) % mod);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n; 
    cin >> n;
    if ((n * (n+1)) % 4 != 0){
        cout(0);
        return 0;
    }
    int m = (n * (n+1)) / 4;
    fr(0,n+1){
        rep(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    solve(n);
}