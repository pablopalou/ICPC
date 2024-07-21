#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define MAXN 100100

ll a[MAXN];
vector<vector<ll>> ps;
ll n; 

bool puedo(ll k){
    bool tengo[21];
    fr(0,21){
        tengo[i] = ps[k][i]>0;
    }
    // if (k == 2){
    //     fr(0,21){
    //         cout << "tengo[ "<< i << "] = " << tengo[i] << endl;
    //     }
    // }
    fr(k,n){
        rep(j,0,21){
            // cout << "I= " << i << " j = " << j <<endl;
            // cout << "valores " << endl;
            // cout << ps[i+1][j] << endl;
            // cout << ps[i+1-k][j] << endl;
            if (tengo[j] != (ps[i+1][j] - ps[i+1-k][j] > 0)){
                // cout << "da false en i = " << i << " y j = " << j << endl;
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    fr(1,n+1) cin >> a[i];
    ps.assign(n+1, vector<ll>(21,0));
    fr(0,21){
        ps[0][i] = 0;
    }
    fr(1,n+1){
        rep(j,0,21){
            ps[i][j] += ps[i-1][j];
            if (a[i] & (1<<j)){
                ps[i][j]++;
            }
        }
    }

    // fr(0,n+1){
    //     rep(j,0,21){
    //         cout << ps[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll l = 1;
    ll r = n;
    int ans = n;
    while(l <= r){
        ll mid = l + (r-l)/2;
        // cout << "pruebo mid " << mid << endl;
        if (puedo(mid)){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans << "\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}