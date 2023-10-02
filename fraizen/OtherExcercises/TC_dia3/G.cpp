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

void solve(int n, int* a, int* b) {
    ll res = 0;
    ll result[n];

    for (int i = 0; i < n; ++i) {
        result[i] = a[i] - b[i];
    }
    sort(result, result + n);

    int l = 0; int r = n-1;
    while (l<r){
        if (result[r] + result[l] > 0){
            res = res + (r-l);
            r--;
        } else {
            l++;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    fr(0,n){
        cin >> a[i];
    }
    int b[n];
    fr(0,n){
        cin >> b[i];
    }
    solve(n,a,b);
}
