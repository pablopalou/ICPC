#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

int gcdF(int a, int b) { return b == 0 ? a : gcdF(b, a % b); } 

// Copiar obligatoriamente 0
void solve() {
    long long n; cin >> n;
    long long g[n];
    long long r[n];
    ll total = 0;
    bool pisoValido = false;
    fr(0,n){
        cin >> g[i] >> r[i];
        if (g[i] == 0){
            pisoValido = true;
        }
        total += g[i];
    }
    if (n == 1) {
        cout << "N\n"; return;
    }
    long long gcd = gcdF(r[0], r[1]);
    fr(2,n){
        gcd = gcdF(gcd, r[i]);
    }
    if (gcd == 1) {
        cout << "Y\n";
        return;
    }
    map<long long, long long> m; //cantidad de ocurrencias de cada gi
    fr(0,n){
        m[g[i]]++;
    }
    n = m.size();
    long long s[n]; //arreglo de cantidad repetidos
    long long newG[n];
    // recorrer mapa y ahi obtener el costo con sus repetidos ? 
    long long i  = 0;
    fre(m){
        newG[i] = e.first;
        s[i] = e.second;
        i++;
    }
    // fre(m){
    //     cout << e.first << " " << e.second << endl;
    // }
    int dp[2][200006];
    fr(0, 200005){
        dp[0][i] = -1;
    }
    long long c[n];
    fr(0,n){
        c[i] = newG[i];
    }
    dp[0][0] = 0;
    fr(1,n+1){
        rep(j,0,200004){
            if(dp[0][j] >= 0){
                dp[1][j] = 0;
            } else if (j-c[i-1] >= 0 && dp[1][j-c[i-1]] >= 0 && dp[1][j-c[i-1]] < s[i-1]){
                dp[1][j] = dp[1][j-c[i-1]] + 1;
            } else {
                dp[1][j] = -1;
            }
        }
        std::swap(dp[1], dp[0]);
    }

    rep(j,1,200003){
        if (dp[0][j] != -1){
            long long dif = abs(j - (total - j)); 
            if (!pisoValido && dif == total){
                continue;
            }
            if (dif % gcd == 0){
                cout << "Y\n"; return;
            }
        }
    }
    cout << "N\n";
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