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

void solve(int a, int b, int c, int d) {
    int res = 0;
    
    if (a != d){
        cout << '0' << '\n';
        return;
    }

    if (c > 1){
        c = 1;
    }

    if (c==1 && (a == 0 || d == 0)){
        cout << '0' << '\n';
        return;
    }
    cout << '1' << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    solve(a,b,c,d);
}
