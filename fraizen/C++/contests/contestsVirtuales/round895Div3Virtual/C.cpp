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

bool prime(int n) { 
    if (n < 2) return false; 
    for (int x = 2; x*x <= n; x++) { 
        if (n%x == 0) return false; 
    } 
    return true; 
}


void solve(int a, int b) {
    if (a == b && a&1 && prime(a)){
        cout(-1);
        return;
    }
    if(b<=3){
        cout(-1);
        return;
    }
    if (a==b){
        if((a&1) == 0){
            cout << 2 << ' ' << b-2 << "\n";
            return;
        }
        int divisor = 1;
        for (int x = 2; x*x <= a; x++) { 
            if (a%x == 0){
                divisor = x;
                break;
            };
        } 
        cout << a/divisor << ' ' << a - a/divisor << "\n";
        return;
    }
    int r = b;
    int l = a;
    // if (r-l < 2){
    //     if (l & 1){
    //         cout << 2 << ' ' << b-2 << "\n";
    //     } else {
    //         cout << 2 << ' ' << l-2 << "\n";
    //     }
    //     return;
    // }
    // if (r-l == 2 && l & 1){
    //     cout << 2 << ' ' << b-3 << "\n";
    //     return;
    // }
    if (b & 1){
        cout << 2 << ' ' << b-3 << "\n";
        return;
    } else {
        cout << 2 << ' ' << b-2 << "\n";
        return;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--){
        int a, b;
        cin >> a >> b;
        solve(a,b);
    }
}