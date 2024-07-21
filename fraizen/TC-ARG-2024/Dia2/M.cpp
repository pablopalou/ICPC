#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define forn(i, n) forr(i, 0, n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)

void solve() {
    int p, d; cin >> p >> d;
    cout << "P = " <<  p << endl;
    cout << "D = " << d << endl;
    int m = d / 2;
    if (d % 2 == 1) m++;
    vector<vector<int>> personas_dia(d);
    fr(0, d) {
        int id; cin >> id; id--;
        personas_dia[i].push_back(id);
    }
    vector<int> res(d);
    vector<int> cant(p, 0);
    fr(0, d) {
        cant[personas_dia[i][0]]++;
        res[i] = personas_dia[i][0];
    }
    fr(0, p) {
        if (cant[i] > m) {
            rep(j, 0, d) {
                if (res[j] == i && personas_dia[j].size() > 1 && cant[i] > m) {
                    res[j] = personas_dia[j][1];
                    cant[personas_dia[j][1]]++;
                    cant[personas_dia[j][0]]--;
                }
            }
        }
    }
    fr(0, p) {
        if (cant[i] > m) {
            cout("NO");
            return;
        }
    }
    cout("YES");
    fr(0, d) cout << res[i] + 1 << " ";
    cout << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    cin >> cases;
    while (cases--) {
        solve();
    }

    #ifdef JP
        cerr << "Time elapsed: " << clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define pb push_back
// #define mp make_pair

// void solve() {
//     int n,m; cin >> n >> m;
//     vector<int> days[m];
//     int maximo = m/2;
//     if (m%2 == 0){
//         maximo = m/2;
//     } else {
//         maximo += 1;
//     }
//     maximo++;

//     map<ll,ll> cant;
//     fr(0,m){
//         int x; cin >> x;
//         rep(j,0,x){
//             int f; cin >> f;
//             days[i].pb(f);
//             cant[f]++;
//         }
//     }
//     // fr(0,m){
//     //     fre(days[i]){
//     //         cout << e << ' ';
//     //     }
//     //     cout << endl;
//     // }
//     vector<int> res;
//     fr(0,m){
//         vector<pair<ll,ll>> v;
//         //agrego todos en este dia y pongo en la respuesta
//         fre(days[i]){
//             v.pb(mp(cant[e],e));
//         }
//         sort(v.begin(), v.end());
//         bool puse = false;
//         fre(v){
//             if (cant[e.second] > 0 && (!puse)){
//                 puse = true;
//                 res.pb(e.second);
//             }
//             cant[e.second]--;
//         }
//         // res.pb(v[0].second);
        
//         // cant[v[0].second]--;
//     }
//     // fre(res){
//     //     cout << e << ' ';
//     // }
//     // cout << "\n";
//     // return;
//     //si hay alguno que tenga mas que la mitad responder no. 
//     map<ll,ll> cantFinal;
//     fre(res){
//         cantFinal[e]++;
//         if (cantFinal[e] >= maximo){
//             cout << "NO\n"; return;
//         }
//     }
//     cout << "YES\n";
//     fre(res){
//         cout << e << ' ';
//     }
//     cout << "\n";
// }   

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }