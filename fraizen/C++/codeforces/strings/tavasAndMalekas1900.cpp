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
ll z[MAXN];

void z_function(string s){
    ll n = s.size();
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
    z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
    ++z[i];
    if (i + z[i] - 1 > r)
    l = i, r = i + z[i] - 1;
    }
}

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
    if (n % 2 == 1)
    res = ((res % mod) * (x % mod)) % mod;
    x = ((x % mod) * (x % mod)) % mod;
    n = n / 2;
    }
    return res % mod;
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll largo = s.size();
    vi pos(m);
    fr(0,m){
        ll a;
        cin >> a;
        pos[i] = a;
    }
    ll ans = 1;
    z_function(s);
    set<ll> sufijos;
    fr(0,largo){
        if (z[i] + i == largo){
            sufijos.insert(largo-i);
        }
    }
    ll cur = 1;
    ll libres = 0;
    fr(0,m){
        if (i == 0){
            // cout("Libres al principio")
            libres = pos[i] - 1;
            // cout(libres);
            cur = pos[i];
        }
        if (pos[i] < cur){
            if (sufijos.find(cur-pos[i]) != sufijos.end()){
                cur = pos[i] + largo;
            } else {
                cout(0);
                return 0;
            }
        } else if (pos[i] == cur){
            cur += + largo;
        } else {
            libres += pos[i] - cur;
            // cout << "libres: " << libres << endl;
            cur = pos[i] + largo;
        }
    }
    cout << modular_expo(26,libres + n - cur + 1);
}