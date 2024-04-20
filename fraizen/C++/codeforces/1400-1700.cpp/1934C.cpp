#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// bool printIfZero(int d,int x,int y){
//     if (d == 0){
//         ans(x,y); return true;
//     }
//     return false;
// }

// void query(int x, int y){
//     cout << "? " << x << " " << y << endl;
// }

// void ans(int x, int y){
//     cout << "! " << x << " " << y << endl;
// }

// Copiar obligatoriamente 0
void solve() {
    int n,m;cin>>n>>m;
    auto query = [&](int x, int y){
        if (x < 1 || x > n || y < 1 || y > m) return -1;
        cout << "? " << x << " " << y << endl;
        int z; cin >> z; return z;
    };
    int d = query(1,1);
    int arrDer = max(1, d+2 - m);
    int abaIzq = max(1, d+2 - n);
    int p = query(arrDer, d+2 - arrDer);
    int q = query(d+2 - abaIzq, abaIzq);
    if (query(arrDer + p/2, d+2 - arrDer - p/2) == 0){
        cout << "! " << arrDer + p/2 << " " << d+2 - arrDer - p/2 << endl;
    } else {
        cout << "! " << d+2 - abaIzq - q/2 << " " << abaIzq +q/2 << endl;
    }
    // //consulto por 1 1
    // cout << "? 1 1"<<endl;
    // int d; cin >> d;
    // if (printIfZero(d,1, 1)) return;
    // //ahotra tengo que preguntar por los dos extremos de la diagonal

    // if (d+1 <= n){
    //     query(d+1,1);
    //     int d1; cin >> d1;
    //     if (printIfZero(d1, d+1, 1)) return;
        
    // } else {
    //     query(n, d-n);
    //     int d1; cin >> d1;
    //     if (printIfZero(d1, n, d-n)) return;
    // }


    // query(1,d+1);
    // int d2; cin >> d2;
    // if (printIfZero(d2, d+1, 1)) return;
    // query(d+1-d1, 1+d1);
    // int d3; cin >> d3;
    // if (printIfZero(d3, d+1-d1, 1+d1)) return;
    // ans(1+d2, d+1-d2);
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