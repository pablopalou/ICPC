#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define mp make_pair

// Copiar obligatoriamente 0
void solve() {
    int n,m; cin >> n >>m;
    string s; cin >> s;
    int leftCero[n], rightOne[n];
    if (s[n-1] == '1'){
        rightOne[n-1] = n-1;
    } else {
        rightOne[n-1] = n;
    }
    if (s[0] == '0'){
        leftCero[0] = 0;
    } else {
        leftCero[0] = -1;
    }
    fr(1,n){
        if (s[i] == '0'){
            leftCero[i] = i;
        } else {
            leftCero[i] = leftCero[i-1];
        }
    }
    for(int i = n-2; i>=0; i--){
        if (s[i] == '1'){
            rightOne[i] = i;
        } else {
            rightOne[i] = rightOne[i+1];
        }
    }
    // cout << "leftCero = ";
    // fr(0,n){
    //     cout << leftCero[i] << ' ';
    // }
    // cout << endl;
    // cout << "rightOne = ";
    // fr(0,n){
    //     cout << rightOne[i] << ' ';
    // }
    // cout << endl;
    set<pair<ll,ll>> res;
    fr(0,m){
        int l,r; cin >> l >> r; l--; r--;
        int newR = leftCero[r];
        int newL = rightOne[l];
        // cout << "l = " << l << " r = " << r << endl;
        // cout << "Newl = " << newL << " | newR = " << newR << endl; 
        if (newL > newR){
            res.insert(mp(-1,-1));
        } else {
            res.insert(mp(newL,newR));
        }
    }
    cout << res.size() << '\n';
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