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
#define prDouble(x) cout << fixed << setprecision(6) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

void solve(int n, int m, vector<ll> arr, vector<pair<ll,d>> prob) {
    ll cur = n;
    while (cur >= 1 && cur == arr[cur-1]){
        cur--;
    }
    if (cur == 0){
        prDouble(1.0);
        cout << "\n";
        return;
    }
    d res = 1.0;
    ll pos;
    d p;
    fr(0,m){
        pos= prob[i].first;
        p= prob[i].second;
        if (pos < cur){
            continue;
        }
        // cout << "Multiplico por 1-" << p << "\n";
        res *= (1-p);
    }
    prDouble(1- res);
    cout << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int cases;
    cin >> cases;
    while (cases--){
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        fr(0,n){
            ll a;
            cin >> a;
            arr[i] = a; 
        }
        vector<pair<ll,d>> prob(m);
        fr(0,m){
            ll pos;
            d p;
            cin >> pos >> p;
            prob[i] = make_pair(pos, p);
        }
        solve(n,m ,arr, prob);
    }
}