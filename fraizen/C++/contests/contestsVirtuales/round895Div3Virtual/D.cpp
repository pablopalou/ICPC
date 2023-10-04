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
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a%b); 
}

int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve() {
    ll n,x,y;
    cin >> n >> x >> y;
    ll cantSuman = 0;
    ll cantRestan = 0;
    ll ans = 0;
    ll gcda = lcm(x,y);
    cantSuman = max(ll(0),n/x - n/(gcda));
    cantRestan = max(ll(0), n/y - n/(gcda));
    
    ll suma = 0;
    ll resta = 0;
    ll limInf = n-cantSuman;
    suma = n * (n+1) / 2 - limInf * (limInf + 1) / 2;
    // cout(suma);
    resta = cantRestan * (cantRestan + 1) / 2;
    // cout(resta);
    cout(suma-resta);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}