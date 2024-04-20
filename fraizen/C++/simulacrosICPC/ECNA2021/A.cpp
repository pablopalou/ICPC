#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const ll MAXN = 100100; 
ll dp[MAXN];
ll n;

int digits(int i){
    int res = 0;
    while(i > 0){
        res++;
        i/=10;
    }
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    memset(dp,-1,sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    fr(3,n+1){
        //sumo uno
        ll best = dp[i-1]+1;
        for(int h = 1; h < (i/2)+1; h++){
            ll cur = dp[h] + dp[i-h];
            best = min(best, cur);
        }
        // cout << "primer best = ";
        // cout(best);
        //multiplico
        rep(j,2,sqrt(i)+1){
            if (j * (i/j) == i){
                // cout << "j = " << j << " i = " << i << endl;
                best = min(best, dp[i/j] + dp[j]);
            }
        }
        // cout << "segundo best ";
        // cout(best);
        //operacion prefijo y sufijo
        int cantDig = digits(i);
        if (cantDig >= 2){
            rep(k, 1, cantDig){
                string s = to_string(i);
                string a = s.substr(0, k);
                string b = s.substr(k, cantDig - k);
                if (b[0] != '0'){
                    best = min(best, dp[stoi(a)] + dp[stoi(b)]);
                }
            }
        }
        dp[i] = best;
    }
    // fr(1,n+1){
    //     cout << "DP["<< i <<"] = "<< dp[i] << endl;
    // }
    // cout << "\n";
    cout << dp[n] << "\n";
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