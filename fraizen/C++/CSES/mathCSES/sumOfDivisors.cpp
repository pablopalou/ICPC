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

int power(long long x, unsigned int y, int p)
{
    int res = 1; 	// Initialize result
    x = x % p; // Update x if it is more than or
                // equal to p
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1,j; i<=n; i=j){
        ll q = n/i;
        j = n/q + 1;
        ll rangeSumUpToJminus1 = ((((j%mod) * ((j-1)%mod)) % mod) * (power(2,mod-2, mod)))%mod;
        ll rangeSumUpToIminus1 = ((((i%mod) * ((i-1)%mod)) % mod) * (power(2,mod-2, mod)))%mod;
        ll rangeWithQuotientQ = (rangeSumUpToJminus1 - rangeSumUpToIminus1 + mod) % mod;
        ans = (ans + (q%mod) * (rangeWithQuotientQ)) % mod;
    }
    
    cout(ans);
}