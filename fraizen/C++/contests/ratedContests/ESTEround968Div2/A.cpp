#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    fr(1,n/2+1){
        // cout << "Pruebo largo " << i << endl;
        if (n % i == 0){
            set<char> primeras;
            set<char> ultimas;
            bool puedo = true;
            int cur = 0;
            rep(j,1,n/i + 1){
                // cout << "Cur " << cur << endl;
                primeras.insert(s[cur]);
                // cout << "agrego " << s[cur] << endl;
                if (ultimas.find(s[cur]) != ultimas.end()){
                    puedo = false;
                }
                ultimas.insert(s[cur + i - 1]);
                // cout << "agrego a ultimas " << s[cur+i-1] << endl;
                cur += i;
            }
            if (puedo){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n"; return;
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