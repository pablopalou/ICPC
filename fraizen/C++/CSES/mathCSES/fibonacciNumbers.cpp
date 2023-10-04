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

struct M22{
    ll a,b,c,d;
    M22 operator*(const M22 &p) const {
        return (M22){(a*p.a + b*p.c)%mod, (a*p.b + b*p.d)%mod, (c*p.a + d*p.c)%mod, (c*p.b + d*p.d)%mod};
    }
};

M22 operator^ (const M22 &p, ll n){
    if (!n) return (M22){1,0,0,1}; //identidad
    M22 q=p^(n/2); q = q * q;
    return n%2 ? p*q: q;
}


void solve(ll n) {
    M22 mat = (M22){1,1,1,0}^n;
    cout(mat.b%mod);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    
    solve(n);
}