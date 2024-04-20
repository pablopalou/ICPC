#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    int n;
    while (cin >> n){
        if (n == 0) return;
        string a[n];
        fr(0,n){
            cin >> a[i];
        }
        sort(a, a+n);
        string s1 = a[n/2 -1];
        string s2 = a[n/2];
        // cout << "test" << endl;
        // cout << char(s1[s2.size()-1] + 1) << endl;
        // cout << char(s2[s2.size()-1]) << endl;
        if (s1.size() > s2.size() && s1.substr(0,s2.size() -1) == s2.substr(0,s2.size()-1) && char(s1[s2.size()-1] + 1) == char(s2[s2.size()-1])){
            if (s1.size() > s2.size()+1){
                int iter = s2.size();
                if (s1[s2.size()] != 'Z'){
                    cout << s1.substr(0,s2.size()) + char(s1[s2.size()] + 1) << "\n"; continue;
                } else {
                    cout << s1.substr(0,s2.size()) + 'Z';
                    iter++;
                    while(iter < s1.size() && s1[iter] == 'Z'){
                        cout << 'Z';
                        iter++;
                    }
                    if (iter == s1.size()-1){
                        cout << char(s1[iter]);
                    } else if (iter < s1.size()-1) {
                        cout << char(s1[iter] +1);
                    }
                    cout << "\n";
                }
            } else {
                cout << s1 << "\n";
            }
            continue;
        }
        fr(0,min(s1.size(), s2.size())){
            if (s1[i] == s2[i] || (i == min(s1.size()-1, s2.size()-1) && s1.size() <= s2.size())){
                cout << s1[i]; 
            } else {
                cout << char(int(s1[i]) + 1);
                break;
            }
        }
        cout << "\n";
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