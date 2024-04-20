#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve(int caso) {
    string s; cin >> s;
    int res = 0;
    fr(0,s.size()){
        if (s[i] == '-'){
            if (i + 1 < s.size()){
                if (s[i+1] == 'B' || s[i+1] == 'S'){
                    continue;
                }
            }
            if (i + 2 < s.size()){
                if (s[i+2] == 'B'){
                    continue;
                }
            }
            if (i > 0){
                if (s[i-1] == 'S'){
                    continue;
                }
            }
            res++;
        }
    }
    cout << "Case " << caso << ": " << res << "\n";
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
    int i = 1;
    while(cases--){
        solve(i);
        i++;
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}