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
bool dp[MAXN];
int a[102];

void solve(int n, int k) {
    fr(1,n+1){
        rep(j, 0, k){
            if (dp[i]){
                break;
            }
            if (i - a[j] >= 0 && (!dp[i-a[j]])){
                dp[i] = true;
            }
        }
    }

    fr(1,n+1){
        cout << ((dp[i] == 1) ? "W" : "L");
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    memset(dp,false,sizeof(dp));
    int n,k;
    cin >> n >> k;
    fr(0,k){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    
    solve(n,k);
}