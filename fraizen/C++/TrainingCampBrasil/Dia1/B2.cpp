#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll fact[20];
ll cant[10];
set<string> used;
set<int> num;

ll get_ans(string s){
    sort(s.begin(),s.end());
    if (used.find(s) != used.end()){
        return 0;
    }
    used.insert(s);
    memset(cant, 0, sizeof(cant));
    fr(0,s.size()){
        cant[s[i]-'0']++;
    }
    fre(num){
        if (cant[e] == 0){
            return 0;
        }
    }

    ll ans = 0;
    ans += fact[s.size()];
    fr(0,10){
        ans /= fact[cant[i]];
    }
    if (cant[0] > 0){
        ll fraizen = fact[s.size()-1];
        cant[0]--;
        fr(0,10){
            fraizen /= fact[cant[i]];
        }
        ans-=(fraizen);
    }
    return ans;
}

void solve() {
    ll ans = 0;
    string s; cin >> s;
    fact[0] = 1;
    fr(1,21){
        fact[i] = fact[i-1] * i;
    }
    fr(0,s.size()){
        num.insert(s[i]-'0');
    }

    fr(1, (1<<s.size())+1){
        string c;
        rep(j,0,s.size()){
            if (i & (1<<j)){
                c += s[j];
            }
        }
        // cout << c << endl;
        ans += get_ans(c);
    }
    cout << ans << '\n';
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