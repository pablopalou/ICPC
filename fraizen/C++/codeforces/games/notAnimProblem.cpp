
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
#define MAXP 10000001  // no necesariamente primo
int criba[MAXP + 1];

void solve() {
    fr(0,MAXP) criba[i] = 1;
    criba[0] = 0;
    criba[2] = 0;
    criba[3] = 2;
    int primos = 2;
    fr(2, MAXP){
        if (criba[i] == 1){ //es un primo
            primos++;
            criba[i] = primos;
            for(ll j = i; j < MAXP; j+=i){
                if (criba[j]==1){
                    criba[j] = primos;
                }
            }
        } else {
            //ya lo calcule, salvo que este en el caso de i == 2 o i == 3
            if (i == 2){
                for(int j = 4;j<MAXP;j+=2){
                    criba[j] = criba[i];
                }
            } else if (i == 3){
                for(int j = 9;j<MAXP;j+=3){
                    if (criba[j]==1){
                        criba[j] = criba[i];
                    }
                }
            }
        }
    }
    int cases; cin >> cases;
    while(cases--){
        int n; cin >> n; int a[n];fr(0,n) cin >> a[i];
        int res = 0;
        fr(0,n){
            res^=criba[a[i]];
        }
        if (res){
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    fr(0,60){
        cout << i << ' ';
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}