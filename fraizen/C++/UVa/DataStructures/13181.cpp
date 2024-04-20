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
    string s; 
    while(cin >>s){
        vector<int> pos;
        fr(0,s.size()){
            if (s[i] == 'X'){
                pos.pb(i);
            }
        }
        int res = 0;
        res = max(res, pos[0]-1);
        res = max(res, (int)s.size() - pos[pos.size()-1] - 2);
        // fr(0,pos.size()){
        //     cout << pos[i] << ' ';
        // }
        // cout << endl;
        fr(0,pos.size()-1){
            res = max(res, (pos[i+1] - pos[i] - 2)/2);
        }
        cout << res << "\n";
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