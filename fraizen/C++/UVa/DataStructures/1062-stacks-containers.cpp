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
    vector<int> a[26];
    int caso = 1;
    while(cin >> s){
        if (s == "end") return;
        fr(0,26){
            a[i].clear();
        }
        rep(j,0,s.size()){
            int best = -1e9;
            int bestPos = -1;
            fr(0,26){
                if (a[i].size() > 0){
                    // rep(k, 0,a[i].size()){
                    //     cout << "fraizen ";
                    //     cout << a[i][k] << ' ';
                    // }
                    // cout << endl;
                    // cout << "entro con i = " << i << endl;
                    // cout << "here" << endl;
                    // cout << (s[j]-'A') << endl;
                    // cout << a[i][a[i].size()-1] << endl;
                    if ((s[j]-'A') - a[i][a[i].size()-1] <= 0){
                        if (((s[j]-'A') - a[i][a[i].size()-1]) > best){
                            bestPos = i;
                        }
                        best = max((s[j]-'A') - a[i][a[i].size()-1],best);
                    }
                    // cout << "best " << best << " con el i = " << i << endl;
                }
            }
            // cout << "best Pos " << bestPos << endl; 
            if (bestPos == -1){
                fr(0,26){
                    if (a[i].size() == 0){
                        a[i].pb(s[j] - 'A');
                        break;
                    }
                }
            } else {
                a[bestPos].pb(s[j] -'A');
            }
        }
        int res = 0;
        fr(0,26){
            if (a[i].size() > 0){
                res++;
            }
        }
        cout << "Case " << caso << ": " << res << "\n";
        caso++;
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