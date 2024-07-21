#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n,x,y; cin >> n >> x >> y; x--; y--;
    swap(x,y);
    vector<int> res(n,0);
    fr(x,y+1){
        res[i] = 1;
    }
    for(int i = y+1; i<n; i+=2){
        res[i] = -1;
        if (i+1 < n){
            res[i+1] = 1;
        }
    }
    for(int i = x-1; i>=0; i-=2){
        // cout << "i = "<< i << endl;
        res[i] = -1;
        if (i-1 >= 0 ){
            res[i-1] = 1;
        }
    }
    fre(res){
        cout << e << ' ';
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