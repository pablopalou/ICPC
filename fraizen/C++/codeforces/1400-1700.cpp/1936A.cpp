#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    vector<int> v;
    //me quedo con el maximo
    int maxi = 0;
    fr(0,n-1){
        cout << "? " << maxi << " " << maxi << " " << i+1 << " " << i+1 << endl;
        char c; cin >> c;
        if (c == '<'){
            maxi = i+1;
        }
    }
    //supongo que tengo el maximo en maxi
    //ahora deberia ver cuantos dan el maximo xor y guardarlos
    v.pb(0);
    int curMaxi = 0;
    fr(1,n){
        cout << "? " << maxi << " " << curMaxi << " " << maxi << " " << i << endl;
        char c; cin >> c;
        if (c == '<'){
            v.clear();
            v.pb(i);
            curMaxi = i;
        } else if (c == '='){
            v.pb(i);
        }
    }
    int mini = v[0];
    for (int i = 1; i < v.size(); i++){
        cout << "? " << mini << " " << mini << " " << v[i] << ' ' << v[i] << endl;
        char c; cin >> c;
        if (c == '>'){
            mini = v[i];
        }
    }
    cout << "! " << maxi << ' ' << mini << endl;
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