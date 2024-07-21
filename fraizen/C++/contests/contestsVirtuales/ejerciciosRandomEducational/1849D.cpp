#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    int l = 0;
    int ans = 0;
    while(l < n){
        int r = l+1;
        bool tieneDos = (a[l] == 2);
        bool tieneMedioCero = false;
        while(r < n){
            if (r-1 > l){ //tengo al menos 3 elementos
                if (a[r-1] == 0){
                    tieneMedioCero = true;
                }    
            }
            if (a[r] == 2){
                tieneDos = true;
            }
            bool bueno = !tieneMedioCero && (tieneDos || (a[l]!=0 || a[r]!=0));
            if (!bueno){
                break;
            }
            r++;
        }
        l = r;
        ans++;
    }
    cout << ans << '\n';
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

// int l = 0;
//     int ans = 0;
//     while(l < n){
//         int r = l+1;
//         bool hasTwo = (a[l] == 2);
//         bool medioCero = false;
//         while (r < n){
//             if (r-1 > l && a[r-1] == 0){
//                 medioCero = true;
//             }
//             if (a[r] == 2){
//                 hasTwo = true;
//             }
//             bool bueno = !medioCero && (hasTwo || (a[l]!=0 || a[r]!=0));
//             if (!bueno){
//                 break;
//             }
//             r++;
//         }
//         l = r;
//         ans+=1;
//     }
//     cout << ans << '\n';