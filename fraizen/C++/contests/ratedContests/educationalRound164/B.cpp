#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; int a[n];
    map<int,int> m;
    fr(0,n){
        cin >> a[i];
        m[a[i]]++;
    }
    if (m.size() == 1){
        cout << "-1\n";return;
    }
    int izq = 1;
    fr(1,n){
        if (a[i] != a[0]){
            izq = i; break;
        }
    }
    int der = 0;
    for (int i = n-2; i >=0; i--){
        der++;
        if (a[n-1] != a[i]){
            break;
        }
    }
    int res = min(izq, der);
    //tambien tengo que contar los del medio
    vector<int> dis;
    fr(1,n){
        if (a[i] != a[0]){
            dis.pb(i);
        }
    }
    fr(1,dis.size()){
        if (dis[i] - dis[i-1] >= 2){
            res =min(res, dis[i]-dis[i-1]-1);
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}