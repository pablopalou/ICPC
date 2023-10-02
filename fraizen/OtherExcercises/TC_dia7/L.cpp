#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

void solve(ll k, ll n, ll m, ll* a, ll* b) {
    ll cant = k;
    vector<ll> res;
    ll i1,i2;
    i1 = i2 = 0;
    bool fraizen = false;
    int i =0;
    while (true){
        i++;
        // if (i1 <= n-1){
        //     cout(a[i1]);
        // }
        // if (i2 <= m-1){
        //     cout(b[i2]);
        // }
        bool ojo = false;
        if (i1 <= n-1 && a[i1] == 0){
            cant++;
            res.pb(a[i1]);
            i1++;
        } else if (i2 <= m-1 && b[i2] == 0){
            cant++;
            res.pb(b[i2]);
            i2++;
        } else if (i1 <= n-1 && a[i1] <= cant){
            res.pb(a[i1]);
            i1++;
        } else if (i2 <= m-1 && b[i2] <= cant){
            res.pb(b[i2]);
            i2++;
        }
        if (i1 == n && i2 == m){
            break;
        }
        if (i1 <= n-1 && a[i1] > cant || i1 > n-1) {
            ojo = true;
        }
        if (i2 <= m-1 && b[i2] > cant || i2 > m-1) {
            if (ojo){
                fraizen = true;
                break;
            }
        }
    }
    
    if (fraizen){
        cout << "-1";
    } else {
        fr(0,res.size()){
            cout << res[i] << ' ';
        }
    }

    cout << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll cases;
    cin >> cases;
    while (cases--){
        ll k, n, m;
        cin >> k >> n >> m;
        ll a[n]; 
        fr(0,n){
            cin >> a[i];
        }
        ll b[m]; 
        fr(0,m){
            cin >> b[i];
        }

        solve(k,n,m,a,b);
    }
}