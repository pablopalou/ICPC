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
    int n,q; cin >> n >> q;
    int a[n+1];
    int p[n+1];
    a[0] = 0;
    fr(1,n+1){
        cin >> a[i];
    }
    map<ll, vector<ll>> m;
    p[0] = 0;
    m[0].pb(0);
    fr(1,n+1){
        p[i] = p[i-1] ^ a[i];
        m[p[i]].pb(i);
    }
    // cout << "A = ";
    // fr(0,n+1){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << "P = ";
    // fr(0,n+1){
    //     cout << p[i] << " ";
    // }
    // cout << endl;
    fr(0,q){
        int l,r; cin >> l >> r;
        if (p[r]==p[l-1]){
            cout << "YES\n"; continue;
        }
        int buscar = (p[r]);
        //ahora caso de 3 segmentos. 
        auto it = lower_bound(m[buscar].begin(),m[buscar].end(),l);
        if (it!=m[buscar].end()){
            if (*it < r){
                int newBuscar = p[l-1];
                // cout << "newBuscar = " << newBuscar << endl;
                auto it2 = lower_bound(m[newBuscar].begin(),m[newBuscar].end(),*it+1);
                if (it2!=m[newBuscar].end() && *it2 < r){
                    cout << "YES\n"; continue;
                }
            }
        }
        cout << "NO\n"; continue;
    }
    cout << "\n";
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