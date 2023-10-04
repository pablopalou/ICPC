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

void solve(int n, int m, int k, int* a) {
    int res = 0;
    int l = m - 1;
    int r = m - 1;
    while (l > 0 && r < n-1){
        l = l-1;
        r = r+1;
        res = res + 10;
        if ((a[l] <= k && a[l] != 0) || (a[r] <= k && a[r] != 0)){
            cout << res << '\n';
            return;
        }
    }
    while (l>0){
        l = l-1;
        res = res + 10;
        if (a[l] <= k && a[l] != 0){
            cout << res << '\n';
            return;
        }
    }
    while (r < n-1){
        r = r + 1;
        res = res + 10;
        if (a[r] <= k && a[r] != 0){
            cout << res << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    int a[n]; 
    fr(0,n){
        cin >> a[i];
    }
    solve(n,m,k,a);
}
