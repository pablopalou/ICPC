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

void solve(int k, int* a) {
    int max_val = INT_MIN; // initialize maximum value with the smallest int possible
    for (int i = 0; i < k; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    cout << max(max_val -25,0) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int a[k]; 
    fr(0,k){
        cin >> a[i];
    }
    solve(k,a);
}
