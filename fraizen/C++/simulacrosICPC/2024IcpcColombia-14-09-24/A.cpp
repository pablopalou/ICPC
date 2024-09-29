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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    //puedo arrancar de 0,0 porque el tablero es como que igual no importa de donde salgamos y el pacman arranca siempre en la misma posicion que el ghost
    //donde queda el pacman? 
    int i = 0; int j = 0;
    fre(s){
        if (e == 'R'){
            j++;
            j+=15;
            j%=15;
        } else if (e == 'L'){
            j--;
            j+=15;
            j%=15;
        } else if (e == 'U'){
            i--;
            i+=15; i%=15;
        } else {
            i++;
            i+=15; i%=15;
        }
    }
    int posPacmanI = i; int posPacmanJ = j;
    // cout <<"posPacman " << posPacmanI <<", " << posPacmanJ << endl;
    //calculo el tiempo en el que llega la extension
    int tiempoWave[15][15];
    fr(0,15) rep(j,0,15) tiempoWave[i][j] = min(i,15-i) + min(j,15-j) + 1;
    // fr(0,15) {
    //     rep(j,0,15){
    //         cout << tiempoWave[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    //hago dp de probabilidades
    long double dp[51][15][15][2]; //dp[mov][i][j][stuck] => en mov movimientos, cual es la probabilidad de estar en la posicion (i,j) y si fue o no tocado por la onda expansiva
    rep(mov,0,51) rep(i,0,15) rep(j,0,15) rep(stuck,0,2) dp[mov][i][j][stuck] = 0.0;
    dp[0][0][0][0] = 1.0;
    // cout << fixed << setprecision(4) << dp[0][0][0][0] << endl;
    // for (int mov = 1; mov <= n; ++mov) {
    //     memset(dp[mov], 0, sizeof(dp[mov]));
        
    //     // First, handle the case where the ghost is stuck
    //     for (int i = 0; i < 15; ++i) {
    //         for (int j = 0; j < 15; ++j) {
    //             dp[mov][i][j][1] += dp[mov - 1][i][j][1]; // Ghost stays in the same cell
    //         }
    //     }

    //     // Now handle the movement for ghosts that are not stuck
    //     for (int prevI = 0; prevI < 15; ++prevI) {
    //         for (int prevJ = 0; prevJ < 15; ++prevJ) {
    //             if (dp[mov - 1][prevI][prevJ][0] > 0.0) { // Ghost is not stuck
    //                 for (int dir = 0; dir < 4; ++dir) {
    //                     int i = (prevI + dx[dir] + 15) % 15;
    //                     int j = (prevJ + dy[dir] + 15) % 15;
    //                     double prob = dp[mov - 1][prevI][prevJ][0] * 0.25;
                        
    //                     if (tiempoWave[i][j] <= mov) {
    //                         dp[mov][i][j][1] += prob;
    //                     } else {
    //                         dp[mov][i][j][0] += prob;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    rep(mov,1,n+1){
        rep(i,0,15){
            rep(j,0,15){
                // rep(stuck,0,2){
                //     if (stuck == 0){
                        dp[mov][i][j][1] += dp[mov-1][i][j][1]; //si estoy stuck, transiciono a mi mismo con p = 1;
                        if (tiempoWave[i][j] <= mov){ //quede stuck
                        // cout << "quede stuck con " << i << ", " << j << endl;
                            rep(idPos,0,4){
                                int newI = i; int newJ = j;
                                newI += dx[idPos]; newJ+= dy[idPos];
                                newI+=15; newI%=15; newJ+=15; newJ%=15;
                                dp[mov][i][j][1] += (dp[mov-1][newI][newJ][0])*(1.0/4);
                            }
                        } else {
                            rep(idPos,0,4){
                                int newI = i; int newJ = j;
                                newI += dx[idPos]; newJ+= dy[idPos];
                                newI+=15; newI%=15; newJ+=15; newJ%=15;
                                // cout << "sumo " << dp[mov-1][newI][newJ][0] << endl;
                                dp[mov][i][j][0] += (dp[mov-1][newI][newJ][0])*(1.0/4);
                            }
                        }
                //     } else {
                //         //ya estoy stuck.. 
                //     }
                // }
            }
        }
    }
    cout << fixed << setprecision(9) << (dp[n][posPacmanI][posPacmanJ][0] + dp[n][posPacmanI][posPacmanJ][1]) << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
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