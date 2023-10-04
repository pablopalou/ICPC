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
    ll d, k;
    cin >> d >> k;
    ll res = 0;
    pair<ll, ll> best = make_pair(0,0);
    pair<ll, ll> cur = make_pair(0,0);
    ll total = d * d;
    while (cur.first * cur.first + cur.second*cur.second <= total){
        cur = make_pair(cur.first + k, cur.second + k);
        if (cur.first * cur.first + cur.second*cur.second <= total){
            best = cur;
        }
        // cout <<"Cur:" <<  cur.first << ' ' << cur.second << endl;
        // cout <<"Best:" << best.first << ' ' << best.second << endl; 
    }
    if ((best.first + k) * (best.first + k) + best.second*best.second <= total){
        best = make_pair(best.first +k, best.second);
    }
    // cout <<"Best:" << best.first << ' ' << best.second << endl; 
    res = best.first / k + best.second / k;
    cout << ((res % 2 == 1) ? "Ashish" : "Utkarsh") << "\n";
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