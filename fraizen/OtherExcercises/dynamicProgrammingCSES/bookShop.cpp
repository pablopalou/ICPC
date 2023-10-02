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
int dp[1002][MAXN];
int costs[1002];
int pages[1002];

void solve(int n, int plata) {
    fr(1,n+1){
        rep(j,1,plata+1){
            dp[i][j] = dp[i-1][j];
            if (j >= costs[i]){
                dp[i][j] = max(dp[i-1][j - costs[i]] + pages[i], dp[i][j]);
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
    int n,plata;
    cin >> n >> plata;

    fr(1,n+1){
        cin >> costs[i];
        // cout << costs[i] << ' ';
    }

    fr(1,n+1){
        cin >> pages[i];
        // cout << pages[i] << ' ';
    }


    solve(n, plata);
    cout << dp[n][plata] << "\n";
}