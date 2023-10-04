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
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
const int N = int(1e7) + 5;

int mind[N];

void precalc(){
    fore(i,0,N){
        mind[i] = i;
    }
    for(int p = 2; p < N; p++){
        if (mind[p] != p)
            continue;
        for(int d=2*p; d < N; d+=p)
            mind[d] = min(mind[d],p);
    }
}

vector<int> getPrimes(int v){
    vector<int> ps;
    while (v > 1){
        if (ps.empty() || ps.back() != mind[v])
            ps.push_back(mind[v]);
        v/=mind[v];
    }
    return ps;
}

void solve(int x, int y) {
    int d  = y-x;
    if (d == 1){
        cout << -1 << "\n";
        return;
    }
    int r = 1e9+8;
    for (int p: getPrimes(d)){
        r = min(r, ((x+p-1)/p)*p);
    }
    cout << r - x << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precalc();
    // Parsing
    int cases;
    cin >> cases;
    while(cases--){
        int x, y;
        cin >> x >> y;
        solve(x,y);
    }
}