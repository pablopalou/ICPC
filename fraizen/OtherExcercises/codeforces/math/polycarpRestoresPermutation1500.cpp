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

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n-1);
    fr(0,n-1){
        int b;
        cin >> b;
        v[i] = b;
    }
    vector<ll> prefix(n-1,0);
    prefix[0] = v[0];
    ll maximo = max(0,v[0]);
    ll minimo = min(0,v[0]);
    fr(1,n-1){
        prefix[i] = prefix[i-1] + v[i];
        if (prefix[i] > maximo){
            maximo = prefix[i];
        } else if (prefix[i] < minimo){
            minimo = prefix[i];
        }
    }

// cout(maximo);
// cout(minimo);
// cout(n-1);
    if (maximo - minimo > n-1){
        cout("-1");
        return 0;
    }

    set<int> s;
    int inicio = maximo > 0 ? n-maximo : n ;
    vector<int> res(n);
    res[0] = inicio;
    int cur = inicio;
    s.insert(inicio);
    fr(1,n){
        res[i] = cur + v[i-1];
        cur = res[i];
        if (s.find(cur) == s.end()){
            s.insert(cur);
        } else {
            cout("-1");
            return 0;
        }
    }

    fr(0,n){
        cout << res[i] << ' ';
    }
}