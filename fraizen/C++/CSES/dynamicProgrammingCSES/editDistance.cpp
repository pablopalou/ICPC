#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define prDouble(x) std::cout << fixed << setprecision(10) << x
#define MAXN 1000008
int dp1[5005];
int dp2[5005];

void solve(string a, string b)
{
    int n, m;
    n = a.size();
    m = b.size();

    for (int i = 0; i <= m; ++i)
    {
        dp1[i] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp2[0] = i;
        for (int j = 1; j <= m; ++j)
        {
            dp2[j] = min({dp1[j] + 1, dp2[j - 1] + 1, dp1[j - 1] + (a[i - 1] != b[j - 1])});
        }
        swap(dp1, dp2);
        // fill(dp2, dp2+m+1,0); este fill es innecesario
    }
    cout << dp1[m] << "\n";
}

int main()
{
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Parsing
    string a, b;
    cin >> a >> b;

    solve(a, b);
}