#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
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

void solve() {
    set<ll> s;
    fr(1,100){
        rep(j,i+1,100){
            // if (j <= i){
            //     cout << 0 << ' ';
            // } else {
            //     cout << -i*i + j*j << ' ';
            // }
            s.insert(-i*i + j*j);
        }
    }
    fre(s){
        cout(e);
        // ll first, second, third;
        // tie(first, second, third) = e;
        // cout << first  << ' ' << second << ' ' << third << endl;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n;
    cin >> n;
    if (n==1){
        cout(3);
        return 0;
    }
    cout(3 + 4 * (n/3) + n%3);
    // solve();
}