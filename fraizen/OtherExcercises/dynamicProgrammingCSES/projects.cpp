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
#define MAXN 200008
int dp[MAXN];

void solve(int n,const vector<tuple<ll,ll,ll>>& projects) {
    ll best = 0;
    map<ll, ll> dp; // {end: totalRewardSoFar}
    dp[0] = 0;
    for (auto project: projects){
        ll start, end, reward;
        tie(end, start, reward) = project;

        auto it = dp.lower_bound(start);
        it--;
        ll totalReward = it->second + reward;
        best = max(best, totalReward);
        dp[end] = best;
    }
    cout << best << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n;
    cin >> n;
    vector<tuple<ll,ll,ll>> projects(n);
    fr(0,n){
        ll start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {end, start, reward};
    }
    sort(projects.begin(), projects.end());
    solve(n, projects);
}