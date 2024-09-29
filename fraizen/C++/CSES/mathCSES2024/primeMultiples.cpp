#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,k; cin >> n >> k;
    ll a[21]; 
    fr(0,21){
        a[i] = 0;
    }
    fr(0,k) cin >> a[i];
    ll res = 0;
    fr(1,(1<<k)){
        // cout << "I = " << i << endl;
        ll cur = 1;
        ll cant = 0;
        bool noSumar = false;
        rep(j,0,21){
            if (((1 << j) & i) != 0){
                cant++;
                if (a[j] > n/cur){
                    cur = 0;
                    noSumar = true;
                }
                cur *= a[j];
                if (cur == 0){
                    break;
                }
            }
        }
        if (noSumar){
            continue;
        }
        if (cur != 0){
            cur = n / cur;
        }
        // cout << "Cur = " << cur << endl;
        if (cant & 1){
            res += cur;
        } else {
            res -=cur;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}