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
vector<set<ll>> v(28);

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    fr(0,n){
        v[s[i]-'a'].insert(i);
    }
    ll res = 1;
    ll pos = -1;
    fr(0,m){
        // cout(t[i]);
        auto it = v[t[i]-'a'].lower_bound(pos+1);
        if (it != v[t[i]-'a'].end()){
            pos = *it;
            // cout << "acutalizo pos:" << pos << endl;
        } else {
            // cout << "Sumo 1 porque tuve que bajar" << endl;
            if (i != m-1){
                pos = *v[t[i]-'a'].lower_bound(-1);
            }
            res+=1;
        }
    }
    cout(res);
}


