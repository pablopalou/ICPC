#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define mod 998244353

ll fact[200100];

void precomp(){
    fact[0] = 1;
    fact[1] = 1;
    fr(2,200100){
        fact[i] = ((fact[i-1] % mod) * (i % mod)) % mod;
    }
}

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    s.pb('3');
    char ant = '2';
    ll cur = 1;
    ll res1 = 0;
    ll largos = 1;
    fr(0,s.size()){
        if (s[i] == ant){
            cur++;
        } else {
            res1 += cur-1;
            largos = (largos * cur) % mod;
            ant = s[i];
            cur = 1;
        }
    }
    ll res2 = (largos * fact[res1]) % mod;
    cout << res1 << ' ' << res2 << "\n";
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
    precomp();
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}