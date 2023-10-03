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

void solve(int n, int k, int d, int w, int* a) {
    int res = 0, s = 0;
    fr(0,n){
        if (a[i] - (a[s] + w) > d || i - s + 1 > k){
            res++;
            s = i; 
        };
    }
    res++;
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // BORRAR
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);

    int cases;
    cin >> cases;
    while (cases)
    {
        int n,k,d,w;
        cin >> n >> k >> d >> w;
        int a[n]; 
        fr(0,n){
            cin >> a[i];
        }
        solve(n,k,d,w,a);
        cases--;
    }
}
