#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int query(int l, int r, int shift = 0){
    cout << "? ";
    fr(l,r+1){
        cout << (i<<shift) << " ";
    }
    cout << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int a1 = query(0,99);
    int a2 = query(1,100, 7);
    a1 = (a1 >> 7) << 7;
    a2 = a2 & (127);
    int a3 = a1|a2;
    cout << "! " << a3 << endl;
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