#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define LSOne(S) ((S) & -(S))

// Copiar obligatoriamente 0
void solve() {
    int n,p; cin >>n >> p;
    int a[p];
    fr(0,p) cin >> a[i];
    if (n == 0){
        cout << "YES\n"; return;
    }
    // cout << "n " << n << endl;
    //aca estoy agarrando cada mascara y fijandome cada bit si esta prendido o no, funciona joya, pero hay una opcion con LSOne que solo va por los bits en 1, entonces es el doble de rapida
    // fr(1, (1 << p)){
    //     int cur = 0;
    //     rep(j,0,p){
    //         if ((i & (1 << j)) != 0){
    //             cur += a[j];
    //             if (cur == n){
    //                 cout << "YES\n";
    //                 return;
    //             } else if (cur > n){
    //                 break;
    //             }
    //         }
    //     }
    //     // cout << "cur " << cur << endl;
    // }
    fr(1, (1 << p)){
        int cur = 0;
        int mask = i;
        while(mask){
            int ls = LSOne(mask);
            int index = __builtin_ctz(ls);
            cur+=a[index];
            mask-=ls;
            if (cur == n){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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