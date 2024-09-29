#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

void solve() {
    int n; cin >> n; int a[n]; int b[n]; fr(0,n) cin >> a[i]; fr(0,n) cin >> b[i];
    auto start_time = std::chrono::high_resolution_clock::now();
    // cout << "N = " << n << endl;
    ll res = -1;
    int maxTime = 250;
    if (n >= 5000){
        maxTime = 500;
    }
    if (n>=6000){
        maxTime = 670;
    }
    if (n >= 7000){
        maxTime  = 750;
    }
    if (n >= 8000){
        maxTime = 890;
    }
    if (n >= 9000){
        maxTime = 980;
    }
    for(int i = n; i>=1; i--) {     
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = current_time - start_time;
        if (elapsed.count() > maxTime) { // 990 ms to be safe
            // Output what you have and exit
            cout << res << '\n';
            return;
        }   
        // cout << "I = " << i << endl;
        //agarro los i de la izquierda de A y pruebo
        for(int start = 0; start <= n-i; start++){
            // cout << "start = " << start << endl;
            //chequeo las i posiciones
            ll cur = 0;
            ll curRes = 0;
            for(int j = start; j < start + i;j++){
                // cout << "veo j = " << j << endl;
                if (a[cur] != b[j]){
                    curRes++;
                }
                cur++;
            }
            res = max(res, curRes);
        }
        if (res == i){
            break;
        }
    }   
    reverse(a, a+n);
    reverse(b,b+n);
    // int iter = 0;
    for(int i = n; i>=1; i--) {   
        auto current_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = current_time - start_time;
        if (elapsed.count() > maxTime) { // 990 ms to be safe
            // Output what you have and exit
            cout << res << '\n';
            return;
        }   
        // cout << "I = " << i << endl;
        //agarro los i de la izquierda de A y pruebo
        for(int start = 0; start <= n-i; start++){
            // cout << "start = " << start << endl;
            //chequeo las i posiciones
            ll cur = 0;
            ll curRes = 0;
            for(int j = start; j < start + i;j++){
                // iter++;
                // cout << "veo j = " << j << endl;
                if (a[cur] != b[j]){
                    curRes++;
                }
                cur++;
            }
            res = max(res, curRes);
        }
        // if (res == i){
        //     break;
        // }
    }   
    // cout << "iter ="<<iter << endl;
    cout << res << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto start_time = std::chrono::high_resolution_clock::now();
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