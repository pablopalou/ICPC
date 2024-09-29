#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define MAXN 55
#define pb push_back
ll n; 
ll xx,yy,zz; 
ll a[MAXN]; 
ll sumaTareas = 0;
ll dp[MAXN][502][502];

bool puedo(int tiempo){
    ll x = tiempo * xx;
    ll y = tiempo * yy;
    ll z = tiempo * zz;
    vector<int> v;
    v.pb(x); v.pb(y);v.pb(z);
    sort(v.begin(), v.end());

    // //hacer dp
    // fr(0,n+1){
    //     rep(j,0,v[0]+1){
    //         rep(z, 0, v[1]+1){
    //             dp[i][j][z] = -1;
    //         }
    //     }
    // }
    rep(j,0,v[0]+1){
        rep(z, 0, v[1]+1){
            dp[0][j][z] = 0;
        }
    }

    fr(1,n+1){
        rep(j,0,v[0]+1){
            rep(zFraizen, 0, v[1]+1){
                dp[i][j][zFraizen] = dp[i-1][j][zFraizen];
                if (j >= a[i-1]){
                    dp[i][j][zFraizen] = max(dp[i][j][zFraizen], dp[i-1][j-a[i-1]][zFraizen] + a[i-1]);
                }
                if (zFraizen >= a[i-1]){
                    dp[i][j][zFraizen] = max(dp[i][j][zFraizen], dp[i-1][j][zFraizen-a[i-1]]  + a[i-1]);
                }
            }
        }
    }
    //se que con los dos primeros llego a dp[n][x][y]
    ll llego = dp[n][v[0]][v[1]];
    // cout <<"con los dos primeros llego a " << llego << endl;
    ll falta = sumaTareas - llego;
    // cout << "todavia me falta " << falta << endl;
    if (v[2] >= falta){
        return true;
    } else {
        return false;
    }
    // cout << endl;
}

void solve() {
    cin >> n;
    cin >> xx >> yy >> zz;
    fr(0,n) cin >> a[i];
    fr(0,n) sumaTareas+=a[i];

    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;

    //hacer binaria
    ll l = 0;
    ll r = 505;
    ll res = r + 10;
    // cout  << "L = " << l << endl;
    // cout << "r = " << r << endl;
    while(l <= r){
        ll mid = l + (r-l) /2;
        // cout << "mid = " << mid << endl;
        if (puedo(mid)){
            // cout << "PUDE CON MID = " << mid << endl;
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << res << '\n';
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases=1;
    // cin >> cases;
    while(cases--) {
        solve();
    }
}