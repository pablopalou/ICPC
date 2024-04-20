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
    ll a,b,c;cin>>a>>b>>c;
    if (c != a+1) {cout << "-1\n"; return;}
    //pongo los a
    if (a == 0){
        cout << b << '\n'; return;
    }
    ll nodos = 0;
    ll nivel = (ll)log2(a);
    ll res = nivel;
    ll ocupados = a - ((1 << nivel) - 1);
    ll curLevel = (1<<nivel) - ocupados;
    ll next = ocupados * 2;
    // cout << "curLevel = "<< curLevel << endl;
    // cout << "next = " << next << endl;
    // cout << "res " << res << endl;
    if (b >= curLevel){
        b-=curLevel;
        next+=curLevel;
        curLevel = 0;
        swap(curLevel, next);
    } else {
        if (next > 0){
            cout << res + 1 << '\n';return;
        } else {
            cout << res << '\n';return;
        }
    }
    //hasta aca deje todo prolijo el arbol. Ahora falta poner los b que faltan en los siguientes niveles. Cuando ponga al menos uno de esos, ya la altura es +1
    res += (b+curLevel-1)/curLevel;
    cout << res+1 << '\n';
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