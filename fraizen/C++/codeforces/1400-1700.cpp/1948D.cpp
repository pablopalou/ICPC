#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

bool puedo(int i, string s){
    string s1,s2;
    s1 = s.substr(0,i/2);
    s2 = s.substr(i/2, i/2);
    int iguales = 0;
    rep(j,0,s1.size()){
        if (s1[j] == s2[j] || (s1[j] == '?' || s2[j] == '?')){
            iguales++;
        }
        if (iguales == i/2) return true;
    }
    int d = i/2;
    rep(j,d, s.size() - d){ 
        if ((s[j] == s[j-d]) || (s[j] == '?' || s[j-d] == '?')){
            iguales--;
        }
        if ((s[j] == s[j+d]) || (s[j] == '?' || s[j+d] == '?')){
            iguales++;
        }
        if (iguales == d) return true;
    }
    return false;
}

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    for(int i = s.size(); i>=1; i--){
        if (i&1) continue;
        if (puedo(i, s)){
            cout << i << '\n'; return;
        }
    }
    cout << "0\n";
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