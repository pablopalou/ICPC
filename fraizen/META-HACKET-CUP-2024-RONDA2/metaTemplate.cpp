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

}

// Para compilar: g++ -O2 -Wl,-stack_size,0x20000000 -o A A.cpp
// Para correr: ./A
// Acordate de usar LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //DESCOMENTAR ESTO PREVIO A BAJAR EL ARCHIVO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int cases = 1;
    cin >> cases;
    rep(i,1,cases+1){
        cout << "Case #" << i << ": "; 
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}