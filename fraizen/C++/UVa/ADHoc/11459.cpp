#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    int players,b,c; cin >> players>>b>>c;
    map<ll, ll> m;
    fr(0,b){
        int s, e; cin >> s >> e;
        m[s] = e;
    }
    int turn = 1;
    int a[players+1];
    fr(1,players+1){
        a[i] = 1;
    }
    bool win = false;
    fr(0,c){
        int nro; cin >> nro;
        if (win){
            continue;
        }
        if (turn > players){
            turn = 1;
        }
        if (a[turn] == 100){
            turn++;
            win = true;
            continue;
        }
        if (a[turn] + nro >= 100){
            a[turn] = 100;
            turn++;
            win = true;
            continue;
        }
        if (m[a[turn] + nro] != 0){
            a[turn] = m[a[turn] + nro];
        } else {
            a[turn] = a[turn] + nro;
        }
        if (a[turn] == 100){
            win = true;
        }
        turn++;
    }
    fr(1,players+1){
        cout << "Position of player " << i << " is " << a[i] << ".\n";
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