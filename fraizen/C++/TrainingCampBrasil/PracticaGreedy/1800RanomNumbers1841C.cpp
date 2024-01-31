#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll value(string s){
    // cout << "Trying: " << s << endl;
    map<char, int> last;
    int n = s.size();
    last['A'] = -1;
    last['B'] = -1;
    last['C'] = -1;
    last['D'] = -1;
    last['E'] = -1;
    map<char, int> valor;
    valor['A'] = 1;
    valor['B'] = 10;
    valor['C'] = 100;
    valor['D'] = 1000;
    valor['E'] = 10000;

    fr(0,n){
        last[s[i]] = i;
    }
    ll ans = 0;
    fr(0,n){
        char c = s[i];
        c++;
        bool vale = true;
        for(c; c <= 'E'; c++){
            if (i < last[c]){
                vale = false;
            }
        }
        if (vale){
            // cout<< "Sumo "<< valor[s[i]] << endl;
            ans += valor[s[i]];
        } else {
            // cout<< "Resto "<< valor[s[i]] << endl;
            ans -= valor[s[i]];
        }
    }
    return ans;
}

// Copiar obligatoriamente 0
void solve() {
    string s;
    cin >> s;
    map<char, int> last;
    map<char, int> first;
    int n = s.size();

    fr(0,n){
        if (first.count(s[i]) <= 0){
            first[s[i]] = i;
        }
        last[s[i]] = i;
    }
    ll ans = value(s);
    string s2;
    //veo de decrementar
    for (auto it=last.begin(); it!=last.end(); ++it){
        for(char c = 'A'; it->first >= c; c++){
            s2 = s;
            s2[it->second] = c;
            ans = max(ans, value(s2));
        }
    }
    // cout << "fdsafads" << endl;
    //veo de incrementar
    for (auto it=first.begin(); it!=first.end(); ++it){
        for(char c = it->first; c <= 'E'; c++){
            s2 = s;
            s2[it->second] = c;
            ans = max(ans, value(s2));
        }
    }
    cout << ans << "\n";
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