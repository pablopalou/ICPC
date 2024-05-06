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
    int n; cin >> n; int a[n]; int b[n];
    map<ll,ll> m1;
    fr(0,n){
        cin >> a[i];
        b[i] = a[i];
        m1[a[i]]++;
    }
    int p[n];
    int pOrig[n];
    p[0] = a[0];
    pOrig[0] = p[0];
    fr(1,n+1){
        p[i] = p[i-1] ^ a[i];
        pOrig[i] = p[i];
    }
    sort(b,b+n);
    sort(p,p+n);
    // fr(0,n){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    // fr(0,n){
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
    // cout << "PORIG" << endl;
    map<ll,ll> m2;

    fr(0,n){
        // cout << pOrig[i] << ' ';
        m2[pOrig[i]]++;
    }
    // cout << endl;
    // cout << "A " << endl;
    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // fre(p){
    //     cout << p << " ";
    // }
    // cout << endl;
    ll res = 0;
    fre(p){
        //tengo un elemento de p, sumo los menores
        res += n - (lower_bound(b, b+n, e) - b); 
    }
    set<int> s;
    fre(a){
        s.insert(e);
    }
    res -= (n-s.size());
    // fre(s){
    //     if (m1.find(e) != m1.end()){
    //         res--;
    //     }
    // }
    // fr(0,n){
    //     if (pOrig[i] == a[i]){
    //         res--;
    //         // cout << "SACO " << endl;
    //     }
    // }
    cout << res << '\n';

    // rep(x,0,n){
    //     rep(y,x,n){
    //         rep(z,y,n){
    //             int xy = 0;
    //             int xz = 0;
    //             int yz = 0;
    //             rep(f,x,y+1){
    //                 xy ^= a[f];
    //             }
    //             rep(f,x, z+1){
    //                 xz ^= a[f];
    //             }
    //             rep(f,y, z+1){
    //                 yz^= a[f];
    //             }
    //             if ((xy ^ yz) > xz){
    //                 cout << x+1 << " " << y+1 << ' ' << z+1 << endl;
    //             }
    //             // cout << "xy " << xy << endl;
    //             // cout << "xz " << xz << endl;
    //             // cout << "yz " << yz << endl;
    //         }
    //     }
    // }
    // int p[n+1];
    // p[0] = 0;
    // fr(1,n+1){
    //     p[i] = p[i-1] ^ a[i-1];
    // }
    // fr(0,n+1){
    //     cout << p[i] << ' ';
    // }
    // fr(1,n+1){
    //     rep(j,i,n+1){
    //         rep(z,j,n+1){
    //             if ((p[j] ^ p[i-1]) ^ (p[z] ^ p[j-1]) > (p[z] ^ p[i-1])){
    //                 cout << i << ", " << j << ", " << z << endl;               
    //             }
    //         }
    //     }
    // }
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