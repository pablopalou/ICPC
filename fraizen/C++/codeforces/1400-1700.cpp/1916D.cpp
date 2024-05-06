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
    int n; cin >> n;
    if (n == 1){ cout << "1\n";return;}
    fr(0,(n-3)/2 + 1){
        string zeroI(i,'0');
        string zeroF(n - i*2 - 3,'0');
        cout << 1 << zeroI << 6 << zeroI << 9 << zeroF << "\n";
        cout << 9 << zeroI << 6 << zeroI << 1 << zeroF << "\n";
    }
    cout << 196 << string(n-3,'0') << "\n";

    // map<string, int> m;
    // cout << fixed << setprecision(2) << sqrt(16900) << endl;
    // cout << fixed << setprecision(2) << sqrt(96100) << endl;
    // cout << fixed << setprecision(2) << sqrt(19600) << endl;

    // cout << fixed << setprecision(2) << sqrt(10609) << endl;
    // cout << fixed << setprecision(2) << sqrt(10609) << endl;
    // return;
    // fr(100,317){
    //     cout << i *i << endl;
    //     string s= to_string(i*i);
    //     sort(s.begin(), s.end());
    //     m[s]++;
    // }
    // fre(m){
    //     cout << e.first << "=> " << e.second << endl;
    // }
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