#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 200008
int a[MAXN];

void solve(int n) {
    vi res;
    fr(0,n){
        auto it = lower_bound(res.begin(), res.end(), a[i]);
        if (it == res.end()){
            res.pb(a[i]);
        } else if (*it > a[i]) {
            *it = a[i];
        }
    }
    cout << res.size() << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    
    solve(n);
}