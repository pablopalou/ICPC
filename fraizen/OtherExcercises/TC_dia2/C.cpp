#include <bits/stdc++.h>
 
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

void solve(int k, ll p) {
    ll res = 0;
    for (ll i = 1; i <= k; i++) {
        string num_str = to_string(i);
        string reversed_str = num_str;
        reverse(reversed_str.begin(), reversed_str.end());
        string palindrome_str = num_str + reversed_str;
        ll palindrome_num = stoll(palindrome_str);
        res = (res + palindrome_num) % p;
    }
    cout << res % p << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, p;
    cin >> k >> p;
    solve(k,p);
}
