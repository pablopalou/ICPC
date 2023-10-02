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
ll team1[MAXN];
ll team2[MAXN];
ll dp[MAXN][2];

void solve(ll n) {
    fr(1,n+1){
        dp[i][0] = max(dp[i-1][1] + team1[i-1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] + team2[i-1], dp[i-1][1]);
    }

    cout(max(dp[n][0], dp[n][1]));
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Parsing

    ll n;
    cin >> n;
    fr(0,n){
        ll a;
        cin >> a;
        team1[i] = a;
    }
    fr(0,n){
        ll a;
        cin >> a;
        team2[i] = a;
    }
    fr(0,n+1){
        rep(j,0,2){
            dp[i][j] = 0;
        }
    }
    solve(n);
}