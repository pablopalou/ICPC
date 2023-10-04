#include <bits/stdc++.h>
 
#include <algorithm>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
 
using namespace std;

void solve(ll a, ll b) {
    int result;
    while (true) {
        if (a == 0 || b == 0) break;
        if (a >= 2 * b) {
            a %= (2 * b);
        } else if (b >= 2 * a) {
            b %= (2 * a);
        } else {
            break;
        }
    }
    // while (true){
    //     cout << a << ' ' << b << '\n';
    //     if (a == 0 || b == 0){
    //         break;
    //     }
    //     if (a >= 2*b){
    //         result = a / (2*b);
    //         a = a - b * 2 * result;
    //     } else {
    //         if (b >=2*a){
    //             result = b / (2*a);
    //             b = b - a * 2 * result;
    //             continue;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    cout << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    solve(a,b);
}
