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

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b){
            cout(ceil(double(a-b)/double(2*c)));
        } else if (b>a){
            cout(ceil(double(b-a)/double(2*c)));
        } else{
            cout(0);
        }
    }
}