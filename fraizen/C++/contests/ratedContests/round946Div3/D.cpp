#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int cant(int a, int b, int c, int d){
    return (a > 0) + (b > 0) + (c >0) + (d >0);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    map<char, vector<int>> pos;
    fr(0,s.size()){
        m[s[i]]++;
        pos[s[i]].pb(i);
    }
    int cantN = m['N'];
    int cantS = m['S'];
    int cantE = m['E'];
    int cantW = m['W'];

    if (cant(cantN, cantS, cantE, cantW) == 1){
        if ((cantN + cantS + cantE + cantW)&1){
            cout << "NO\n"; return;
        } else {
            fr(0,s.size()/2){
                cout << "RH";
            }
            cout << "\n"; return;
        }
    }
    if (cant(cantN, cantS, cantE, cantW) == 2 && ((cantN + cantS + cantE + cantW))==2){
        cout << "NO\n"; return;
    }
    if ((abs(cantN - cantS) % 2 ) == 1){
        cout << "NO\n";return;
    }
    if ((abs(cantE - cantW) % 2 ) == 1){
        cout << "NO\n";return;
    }
    char ans[n];
    //asumo que es posible
    bool masNorte = cantN >= cantS;
    bool masEste = cantE >= cantE;
    int objV = abs(cantN - cantS)/2;
    int objH = abs(cantE - cantW)/2;
    int cantV = 0;
    int cantH = 0;

    vector<char> assignment(n, 'R');
    int halfN = cantN / 2;
    int halfS = cantS / 2;
    int halfE = cantE / 2;
    int halfW = cantW / 2;

    for (int i = 0; i < halfN; ++i) assignment[pos['N'][i]] = 'H';
    for (int i = 0; i < halfS; ++i) assignment[pos['S'][i]] = 'H';
    for (int i = 0; i < halfE; ++i) assignment[pos['E'][i]] = 'H';
    for (int i = 0; i < halfW; ++i) assignment[pos['W'][i]] = 'H';
    int cant1 = 0;
    int cant2 = 0;
    for(char c: assignment){
        if (c == 'R') {
            cant1++;
        } else {
            cant2++;
        }
    }
    if (cant2 == 0){
        if (cantE == 1 && cantW == 1){
            assignment[pos['E'][0]] = 'H';
            assignment[pos['W'][0]] = 'H';
        } else if (cantS == 1 && cantN == 1){
            assignment[pos['S'][0]] = 'H';
            assignment[pos['N'][0]] = 'H';
        }
    }
    for (char c : assignment) cout << c;
    cout << "\n";
    // Ajustar las instrucciones verticales
    // if (objV > 0) {
    //     if (masNorte) {
    //         fr(0, pos['N'].size()) {
    //             if (cantV < objV) {
    //                 ans[pos['N'][i]] = 'H';
    //                 cantV++;
    //             }
    //         }
    //     } else {
    //         fr(0, pos['S'].size()) {
    //             if (cantV < objV) {
    //                 ans[pos['S'][i]] = 'H';
    //                 cantV++;
    //             }
    //         }
    //     }
    // }

    // // Ajustar las instrucciones horizontales
    // if (objH > 0) {
    //     if (masEste) {
    //         fr(0, pos['E'].size()) {
    //             if (cantH < objH) {
    //                 ans[pos['E'][i]] = 'H';
    //                 cantH++;
    //             }
    //         }
    //     } else {
    //         fr(0, pos['W'].size()) {
    //             if (cantH < objH) {
    //                 ans[pos['W'][i]] = 'H';
    //                 cantH++;
    //             }
    //         }
    //     }
    // }

    // fr(0,n){
    //     cout << ans[i];
    // }
    // cout << '\n';
    // fr(0,s.size()){
    //     if (s[i] == 'N'){
    //         if (masNorte){
    //             if (cantV < objV){
    //                 cout << "R";
    //             } else {
    //                 cout << "H";
    //             }
    //         } else {
    //             if (cantV < objV){
    //                 cout << "R";
    //             } else {
    //                 cout << "H";
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