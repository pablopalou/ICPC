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
#define MAXN 100008
int dp[MAXN][102];
int a[MAXN];

void solve(int n, int m) {
    fr(2,n+1){
        if (a[i] == 0){
            rep(j,0,m+1){
                dp[i][j] = dp[i-1][j];
                if (j-1 >= 1){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= mod;
                }
                if (j+1 <= m){
                    dp[i][j] += dp[i-1][j+1];
                }
                dp[i][j] %= mod;
            }
        } else {
            int j = a[i];
            dp[i][j] = dp[i-1][j];
            if (j-1 >= 1){
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            }
            if (j+1 <= m){
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= mod;
        }
    }   
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp,0, sizeof dp);
    int n,m;
    cin >> n >> m;
    int ultPos = -1;
    fr(1,n+1){
        cin >> a[i];
        if (a[i] != 0) {
            ultPos = i;
        }
    }
    if (n>=1){
        if (a[1] == 0){
            fr(1,m+1){
                dp[1][i] = 1;
            }
        } else {
            dp[1][a[1]] = 1;
        }
    }
    solve(n,m);
    if (a[n] != 0){
        cout << dp[n][a[n]] << "\n";
    } else {
        int res = 0;
        fr(1,m+1){
            res += dp[n][i];
            res %= mod;
        }
        cout << res << "\n";
    }
}