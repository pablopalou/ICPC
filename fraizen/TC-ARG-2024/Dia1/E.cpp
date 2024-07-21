#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll dp[405][203];
ll prefix[402];

void solve() {
    ll n,k; cin >> n >> k;
    ll a[n];
    fr(0,n) cin >> a[i];
    sort(a,a+n);
    prefix[0] = 0;
    fr(0,n){
        prefix[i+1] = prefix[i] + a[i];
    }
    memset(dp, -1, sizeof(dp));
    fr(0,n+1){
        dp[i][0] = 0;
    }
    fr(0,n+1){
        rep(j,0,k+1){
            // cout << "I = " << i << " J = " << j << endl;
            if (dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]); // no uso el i
            // cout << "No uso i entonces queda " << dp[i+1][j] << endl;
            //ahora veo las opciones usando i
            //puedo jugar hasta k-j turnos
            for(int turnos = 1; turnos <= min(k-j, (n-i)/2); turnos++){
                // cout << "Turnos = " << turnos << endl;
                ll sumaIzq = prefix[i+turnos] - prefix[i];
                ll sumaDer = prefix[i+ turnos * 2] - prefix[i+turnos];
                // cout << "sumaIzq = " << sumaIzq << endl;
                // cout << "sumaDer = " << sumaDer << endl;
                ll sumita = sumaDer - sumaIzq;
                dp[i+2*turnos][j+turnos] = max(dp[i][j] + (sumita), dp[i+2*turnos][j+turnos]);
                // cout << "pongo dp[" << i+2*turnos<< "][" << j+turnos <<"] = " << dp[i+2*turnos][j+turnos]  << endl;
            }
        }
    }

    // fr(0,n+1){
    //     rep(j,0,k+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << dp[n][k] << '\n';
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