#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
//codigo accepted: 
// void solve() {
//     int n;
//     while(cin >> n){
//         int a[(1<<n)];
//         fr(0,(1<<n)){
//             cin >> a[i];
//         }
//         int potencias[(1<<n)];
//         int mask = 0;
//         fr(0,1<<n){
//             mask = i;
//             int suma = 0;
//             //hago los 15 xor
//             rep(j,0,n){
//                 mask = mask ^ (1 << j);
//                 suma += a[mask];
//                 mask = i; 
//             }
//             potencias[i] = suma;
//         }
//         int res = -1e9;
//         fr(0,1 << n){
//             int cur = potencias[i];
//             int bestMask = 0;
//             int mask = i;
//             rep(j,0,n){
//                 mask = mask ^ (1<<j);
//                 bestMask = max(bestMask, potencias[mask]);
//                 mask = i;
//             }
//             res = max(res, cur + bestMask);
//         }
//         cout << res << "\n";
//     }
// }

void solve() {
    int n;
    while(cin >> n){
        int a[(1<<n)];
        fr(0,(1<<n)){
            cin >> a[i];
        }
        int potencias[(1<<n)];
        int mask = 0;
        fr(0,1<<n){
            mask = i;
            int suma = 0;
            //hago los 15 xor
            rep(j,0,n){
                mask = mask ^ (1 << j);
                suma += a[mask];
                mask = i; 
            }
            potencias[i] = suma;
        }
        int res = -1e9;
        fr(0,1 << n){
            int cur = potencias[i];
            int bestMask = 0;
            int mask = i;
            rep(j,0,n){
                mask = mask ^ (1<<j);
                bestMask = max(bestMask, potencias[mask]);
                mask = i;
            }
            res = max(res, cur + bestMask);
        }
        cout << res << "\n";
    }
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