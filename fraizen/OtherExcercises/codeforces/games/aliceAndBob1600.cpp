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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } 

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> v(n);
    int maximo;
    fr(0,n){
        int a;
        cin >> a;
        if (i == 0){
            maximo = a;
        } else {
            maximo = max(maximo, a);
        }
        v[i] = a;
    }
    
    int divisor = v[0];
    fr(1,n){
        divisor = gcd(v[i], divisor);
    }
    cout << ((maximo / divisor - n) % 2 == 1 ? "Alice" : "Bob") << "\n";
}