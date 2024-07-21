#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back


// int dp[101][101][101*101]; // dp[i][cnt0][cnt01] = minima cantidad de cambios que necesito hacer en mi string de hasta i caracteres (cambiar de 0 a 1 o de 1 a 0), teniendo
// cnt0 ceros y cnt01 de subsecuencias 01.
// esto no entra en memoria xq son 100 millones pero la dp depende solo de la fila anterior, entonces la primera dimension la hacemos de 2 nomas.
int dp[2][101][101*101];

//las transiciones de la dp son: 
// pongo un 0 entonces: 
// dp[i+1][cnt0+1][cnt01] = dp[i][cnt0][cnt01] + (1 si s[i]==1 else 0)

// pongo 1 entonces:
// dp[i+1][cnt0][cnt01+cnt0] = dp[i][cnt0][cnt01] + (1 si s[i]==0 else 0)

//la respuesta va a ser dp[n][cnt0 en el string original][need] / 2. donde need = (cnt0 * cnt1)/ 2 debido a que queremos la misma cantidad de subsecuencias 01 que 10.

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s; int n = s.size(); int iniZero = 0;
    fre(s){ //cuento los ceros
        if(e == '0'){
            iniZero++;
        }
    }
    //el primer valor si es 0
    dp[0][0][0] = 0;
    //lleno la dp
    for (int i = 0; i < n; i++){
        //toda la dp con "infinito" en un principio (recordar que memset no funciona!, solo anda para -1 y 0).
        for(int cnt0 = 0; cnt0<=n; cnt0++){
            for( int cnt01 = 0; cnt01 < (cnt0 * ((i+1)-cnt0) + 1); cnt01++){
                dp[1][cnt0][cnt01] = n;
            }
        }
        for(int cnt0 = 0; cnt0<=n; cnt0++){
            for( int cnt01 = 0; cnt01 < (cnt0 * (i-cnt0) + 1); cnt01++){ //aca voy solo hasta la cant01 que podia tener antes, por eso no le sumo el +1 a la i.
                dp[1][cnt0+1][cnt01] = min(dp[1][cnt0+1][cnt01], dp[0][cnt0][cnt01] + (s[i]=='1'));
                dp[1][cnt0][cnt01+cnt0] = min(dp[1][cnt0][cnt01+cnt0], dp[0][cnt0][cnt01] + (s[i]=='0'));
            }
        }
        swap(dp[0], dp[1]);
    }


    cout << dp[0][iniZero][iniZero * (n-iniZero) / 2] /2 << '\n';
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