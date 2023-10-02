#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef long double ld;
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
int a[102];

void solve(ll n) {
    db ans = 0.0;
    fr(0,n){
        for(int j = i+1; j < n; j++){
            ll cur = 0;
            if (a[j] < a[i]){
                cur += (a[i] - a[j]) * a[j];
                cur += (a[j] * (a[j] - 1)) / 2;
            } else {
                cur += (a[i] * (a[i] - 1)) / 2;
            }
            // cout << "Pair (" << i << ',' << j << ") tiene: " << cur << "\n";
            ans += (db)cur / (db)(a[j] * a[i]);
        }
    }

    cout << fixed << setprecision(6) << ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    solve(n);
}