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
    ll n; cin >> n;
    ll a[n+1];
    fr(1,n+1){
        cin >> a[i];
    }
    string s; cin >> s;
    ll q; cin >> q;
    ll xorCeros = 0;
    ll xorUnos = 0;
    //precomputo
    ll xora[n+1];
    xora[1] = a[1];
    fr(2,n+1){
        xora[i] = xora[i-1] ^ a[i];
    }
    fr(1,n+1){
        if (s[i-1] == '0'){
            xorCeros ^= a[i];
        } else {
            xorUnos ^= a[i];
        }
    }
    //respondo las queries
    while(q--){
        ll a;
        cin >> a;
        if (a == 1){
            ll b,c;
            cin >> b >> c;
            //actualizo xorCeros y xorUnos
            if (b == 1){
                xorCeros ^= xora[c] ;
                xorUnos ^= xora[c] ;
            } else {
                xorCeros ^= xora[c] ^ xora[b-1];
                xorUnos ^= xora[c] ^ xora[b-1];
            }

        } else {
            ll d;
            cin >> d;
            if (d==0){
                cout << xorCeros << ' ';
            } else {
                cout << xorUnos << ' ';
            }
        }
    }
    cout(' ');
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