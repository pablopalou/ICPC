#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    string s; getline(cin,s);
    map<char, int> m;
    // cout << s << endl;
    for(auto c: s){
        if (c != ' '){
            m[tolower(c)]++;
        }
    }
    int maxi = 0;
    fre(m){
        maxi = max(maxi, e.second);
        // cout << "m[ "<< e.first << " ] = " << e.second << endl;
    }
    // cout << maxi << endl;
    fre(m){
        if (e.second == maxi){
            cout << e.first;
        }
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
    cin.ignore();
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}