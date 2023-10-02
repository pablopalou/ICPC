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
int dp[1009][1009];

void solve(int n) {
    fr(1,n){
        if ((dp[0][i] == 0) && (dp[0][i-1] == 1)){
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
        if ((dp[i][0] == 0) && (dp[i-1][0] == 1)){
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }

    fr(1,n){
        rep(j,1,n){
            if (dp[i][j] == -1){continue;}
            if (dp[i][j-1] != -1){
                dp[i][j] += dp[i][j-1] % mod;
            }
            if (dp[i-1][j] != -1){
                dp[i][j] += dp[i-1][j] % mod;
            }
            dp[i][j] %= mod;
        }
    }

    // fr(0,n){
    //     rep(j,0,n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout(' ');
    // }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    char number;
    fr(0,n){
        rep(j,0,n){
            cin >> number;
            if (number == '.'){
                dp[i][j] = 0; 
            } else {
                dp[i][j] = -1;
            }
        }
    }
    if (dp[0][0] == -1 || dp[n-1][n-1]){
        cout(0);
    } else {
        dp[0][0] = 1;
        solve(n);
        cout << dp[n-1][n-1] << "\n";
    }
}