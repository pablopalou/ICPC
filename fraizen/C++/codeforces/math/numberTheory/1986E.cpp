#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,k; cin >> n >>k;
    ll a[n]; fr(0,n) cin >> a[i];
    sort(a, a+n);
    map<ll,vector<ll>> m;
    fr(0,n){
        m[a[i]%k].pb(a[i]);
    }
    ll cantImpar = 0;
    fre(m){
        if (e.second.size() & 1){
            cantImpar++;
        }
    }
    if (n & 1){
        if (cantImpar >=2 ){
            cout << -1 << "\n"; return;
        }
    } else {
        if (cantImpar >=1){
            cout << -1 << "\n"; return;
        }
    }

    ll res = 0;
    ll l = 0; ll r = n-1;
    fre(m){
        if (e.second.size() % 2 == 1){
            // cout << "here " << endl;
            ll n = e.second.size();
            ll paresIzq[n], paresDer[n];
            ll cur = 0;
            paresDer[n-1] = 0;
            for(int i = 1; i < n; i+=2){
                paresIzq[i-1] = cur;
                paresIzq[i] = cur + e.second[i] - e.second[i-1];
                cur = paresIzq[i];
            }
            paresIzq[n-1] = cur;
            cur = 0;
            for(int i = n-2; i >= 0; i-=2){
                paresDer[i+1] = cur;
                paresDer[i] = cur + e.second[i+1] - e.second[i];
                cur = paresDer[i];
            }
            paresDer[0] = cur;
            ll best = min(paresIzq[n-1], paresDer[0]);
            fr(1,n-1){
                //pruebo eliminar el i
                ll cur = 0;
                cur += paresIzq[i-1] + paresDer[i+1];
                if (i&1){
                    cur+= e.second[i+1] - e.second[i-1];
                }
                best = min(best, cur);
            }
            res += best/k;
            // fr(0,n){
            //     cout << paresDer[i] << " ";    
            // }
            // cout << endl;
        } else {
            for(int i = 0; i<e.second.size(); i+=2){
                res += (e.second[i+1] - e.second[i]) / k;
            }
        }
    }
    cout << res << '\n';
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