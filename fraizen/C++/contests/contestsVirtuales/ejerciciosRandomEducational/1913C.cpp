#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
int cnt[30];

// Copiar obligatoriamente 0
void solve() {
    int op, num; cin >> op >> num;
    if (op == 1){
        cnt[num]++;
    } else { //tengo que contestar la query si puedo formar num
        //arranco con el mas grande y voy bajando
        for(int i = 29; i>=0; i--){
            int cant = min(num >> i, cnt[i]); //agarro el minimo entre lo que tengo y lo que le podria sacar al numero
            num -= cant << i;
        }
        if (num == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
        
    memset(cnt, sizeof(cnt), 0);
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