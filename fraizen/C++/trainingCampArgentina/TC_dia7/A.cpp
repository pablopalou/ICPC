#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<ll> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define MAXN 100005
#define fre(s) for(auto e:s)

void solve(ll n, ll k, si s) {
    if (k == 0){
        cout(n);
        return;
    }

    ll mins = MAXN;
    ll i = 0;
    while (mins == MAXN){
        if (s.count(i) == 0){
            mins = i;
            break;
        }
        i += 1;
    }
    if (mins > *s.rbegin()){
        cout(n+k);
        return;
    }
    if (s.count(ceil(double(mins+*s.rbegin())/2)) == 0) {
        cout(n+1);
    } else {
        cout(n);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll cases;
    cin >> cases;
    while (cases){
        ll n,k;
        cin >> n >> k;
        si s;
        fr(0,n){
            ll a;
            cin >> a;
            s.insert(a);
        }
        solve(n,k,s);
        cases-=1;
    }
}