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

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, ll> mapIzq;
    map<string, ll> mapDer;
    map<string, ll> mapAny;
    set<string> socks;
    ll n;
    cin >> n;
    fr(0,n){
        string a, b;
        ll c;
        cin >> a >> b >> c;
        if (b == "left"){
            mapIzq[a] = c;
        } else if (b == "right"){
            mapDer[a] = c;
        } else {
            mapAny[a] = c;
        }
        socks.insert(a);
    }
    // for(auto it = mapIzq.cbegin(); it != mapIzq.cend(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    //     for(auto it = mapDer.cbegin(); it != mapDer.cend(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    //     for(auto it = mapAny.cbegin(); it != mapAny.cend(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    ll ans = 0;
    bool impossible = true;
    fre(socks){
        ll izq, der, cual;
        izq = mapIzq[e];
        der = mapDer[e];
        cual = mapAny[e];
        // cout(e);
        // cout(izq);
        // cout(der);
        // cout(cual);
        // cout(' ');
        if (impossible){
            if (cual >= 2){
                impossible = false;
            }
            if (izq >= 1 && der >= 1){
                impossible = false;
            }
        }
        if ((izq > 0 && der > 0 && cual >0) || ((izq > 0 || der > 0 )&& cual > 0 ) || (izq > 0 && der > 0 )){
            ans += max(der,izq);
        } else if (izq > 0){
            ans += izq;
        } else if (der > 0) {
            ans+= der;
        } else if (cual > 0){
            ans += 1;
        }
    }
    if (impossible){
        cout << "impossible" << "\n";
        return 0;
    }
    cout << ans+1;
}