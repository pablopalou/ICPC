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
ll dp[5002][5002];
ll a[5002];

ll solve(ll l, ll r) {
    if (dp[l][r] != -inf){
        return dp[l][r];
    }
    ll ans;
    ans = max(- solve(l+1,r) + a[l], a[r] - solve(l,r-1));
    return dp[l][r] = ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    ll  n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    ll total = 0;
    fr(0,n){
        total += ll(a[i]);
    }
    fr(0,n){
        rep(j,0,n){
            dp[i][j] = -inf;
        }
    }
    fr(0,n){
        dp[i][i] = a[i];
    }
    ll dif = solve(0,n-1);
    ll jug2 = ( total - dif ) / 2;
    cout << jug2 + dif << "\n";
}