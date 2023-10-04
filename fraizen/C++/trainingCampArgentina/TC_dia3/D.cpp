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

void solve(int n, int* a) {
    int* min_index = min_element(a, a + n);
    int* max_index = max_element(a, a + n);
    int min_idx = distance(a, min_index);
    int max_idx = distance(a, max_index);
    int res;
    int aux;
    res = min(max(min_idx, max_idx) + 1, max(n - min_idx, n-max_idx));
    if (min_idx > max_idx){
        aux = max_idx;
        max_idx = min_idx;
        min_idx = aux;
    }
    res = min(res, min_idx + 1 + n - max_idx);
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    int n;
    cin >> cases;
    while (cases > 0){
        cin >> n;
        int a[n];
        fr(0,n){
            cin >> a[i];
        }
        solve(n,a);
        cases--; 
    }

}
