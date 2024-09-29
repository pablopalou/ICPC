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
    int n; cin >> n;
    int a[n]; fr(0,n) cin >> a[i];
    ll unos = 0;
    fr(0,n){
        if (a[i] == 1){
            unos++;
        }
    }
    if (unos == 0){
        cout << 0 << '\n'; return;
    }
    vector<int> l2;
    vector<int> l1;
    int cur = 0;
    bool contar = false;
    fr(0,n){
        if (a[i] == 1){
            if (contar){
                l2.pb(cur+1);
            }
            contar = true;
            cur = 0;
        } else {
            cur++;
        }
    }
    l2.pb(cur+1);
    // fre(l2){
    //     cout << e << ' ';
    // }
    // cout << endl;
    int cont = 0;
    fr(0,n){
        if (a[i] == 0){
            cont++;
        } else {
            break;
        }
    }
    l1.pb(cont+1);
    fr(0,l2.size()-1){
        l1.pb(l2[i]);
    }
    // fre(l1){
    //     cout << e << ' ';
    // }
    // cout << endl;
    // fre(l2){
    //     cout << e << ' ';
    // }
    // cout << endl;
    ll res= 0;
    ll sumaImpar = 0;
    ll sumaPar = 0;
    fr(0,l2.size()){
        if (i % 2 == 0){
            sumaPar += l1[i];
            res += l2[i] * sumaPar;
            // cout << "SUmo " << l2[i] * sumaPar << endl;
        } else {
            sumaImpar += l1[i];
            res+= l2[i] * sumaImpar;
            // cout << "sumo " << l2[i] * sumaImpar << endl;
        }
    }
    cout << res << "\n";
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