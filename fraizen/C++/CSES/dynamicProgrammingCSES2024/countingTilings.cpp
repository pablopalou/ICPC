#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mod 1000000007
map<int, vector<int>> prevTilings;

void generateNextTilings(int idx, int n, int prev, int next){
    if (idx == n){
        prevTilings[next].pb(prev);
        return;
    }
    if ( ((1 << idx) & prev) != 0){
        generateNextTilings(idx+1, n, prev, next);
        return;
    }
    //veo si puedo meter una vertical
    if (idx < n-1 && ((1 << (idx+1)) & prev) == 0){
        generateNextTilings(idx+2, n, prev, next);
    }
    //meto una horizontal
    generateNextTilings(idx+1, n, prev, next | (1<<idx));
}

void solve() {
    int n,m; cin >> n >> m;
    int limit = 1 << n;
    for(int tile = 0; tile < limit; tile++){
        generateNextTilings(0, n, tile, 0);
    }

    // fr(0,limit){
    //     fre(prevTilings[i]){
    //         cout << e << ' ';
    //     }
    //     cout << endl;
    // }
    // return;

    vector<ll> prevRow(limit);
    vector<ll> dp(limit); //cantidad de formas de obtener esta columna de fichas
    prevRow[0] = 1;
    fr(0,m){
        rep(j,0,limit){
            fre(prevTilings[j]){
                dp[j] = (dp[j] + prevRow[e]) % mod;
            }
        }
        swap(dp, prevRow);
        fill(dp.begin(), dp.end(), 0);
    }
    cout << prevRow[0] << "\n";
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