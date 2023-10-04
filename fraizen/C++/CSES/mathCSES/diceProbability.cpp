#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
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
db dp[102][610];
void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;
    
    fr(0,n+1){
        rep(j,1, 6*n+1){
            dp[i][j] = 0.0;
        }
    }
    dp[0][0] = 1.0;
    
    fr(1,n+1){
        rep(j,1,6*n + 1){
            rep(k,1,7){
                if (j-k >=0){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j] /= 6;
        }
    }
    db ans = 0;
    fr(a,b+1){
        ans += dp[n][i];
    }
    ans *= 1e6;
    ans = llround(ans);
    ans /= 1e6;
    cout << fixed << setprecision(6) << ans;
}