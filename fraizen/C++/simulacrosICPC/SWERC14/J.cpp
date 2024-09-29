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
#define mod 1000000007

// ESTA MAL, EL J2.cpp si da ACCPETED.

// P should be a prime number, could be randomly generated,
// sometimes is good to make it close to alphabet size
// MOD[i] must be a prime of this order, could be randomly generated
const int P = 1777771, MOD[2] = {999727999, 1070777777};
const int PI[2] = {325255434, 10018302};  // PI[i] = P^-1 % MOD[i]
struct Hash {
  vector<int> h[2], pi[2];
  vector<ll> vp[2];  // Only used if getChanged is used (delete it if not)
  Hash(string& s) {
    forn(k, 2) h[k].rsz(s.size() + 1), pi[k].rsz(s.size() + 1),
        vp[k].rsz(s.size() + 1);
    forn(k, 2) {
      h[k][0] = 0;
      vp[k][0] = pi[k][0] = 1;
      ll p = 1;
      forr(i, 1, sz(s) + 1) {
        h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
        pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
        vp[k][i] = p = (p * P) % MOD[k];
      }
    }
  }
  ll get(int s, int e) {  // get hash value of the substring [s, e)
    ll H[2];
    forn(i, 2) {
      H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
      H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
    }
    return (H[0] << 32) | H[1];
  }
};

void solve() {
    int h1,w1,h2,w2; cin >> h1 >> w1>>h2>>w2;
    string patron[h1];
    fr(0,h1){
        cin >> patron[i];
    }
    string mat[h2];
    fr(0,h2){
        cin >> mat[i];
    }
    //hasheo todas las filas
    ll sumaPatron = 0;
    ll valPatron[h1][w1];
    fr(0,h1){
        Hash hash = Hash(patron[i]);
        rep(j,0,w1){
            valPatron[i][j] = (hash.get(0,j+1) % mod);
        }
    }
    fr(0,h1){
        rep(j,0,w1){
            if (i > 0){
                valPatron[i][j] = (valPatron[i][j] + valPatron[i-1][j]) % mod;
            }
            if (j > 0){
                valPatron[i][j] = (valPatron[i][j] + valPatron[i][j-1]) % mod;
            }
            if (i > 0 && j > 0){
                valPatron[i][j] = (((valPatron[i][j] - valPatron[i-1][j-1]) % mod) + mod) % mod;
            }
        }
    }
    fr(0,h1){
        rep(j,0,w1){
            cout << valPatron[i][j] << " ";
        }
        cout << endl;
    }
    sumaPatron = valPatron[h1-1][w1-1];
    cout << sumaPatron << endl;
    ll val[h2][w2];
    fr(0,h2){
        Hash hash = Hash(mat[i]);
        rep(j,0,w2){
            val[i][j] = hash.get(0,j+1) % mod;
        }
    }

    fr(0,h2){
        rep(j,0,w2){
            if (i > 0){
                val[i][j] = (val[i][j] + val[i-1][j]) % mod;
            }
            if (j > 0){
                val[i][j] = (val[i][j] + val[i][j-1]) % mod;
            }
            if (i > 0 && j > 0){
                val[i][j] = (((val[i][j] - val[i-1][j-1]) % mod) + mod) % mod;
            }
        }
    }

    fr(0,h2){
        rep(j,0,w2){
            cout << val[i][j] << " ";
        }
        cout << endl;
    }
    ll sumaColumnas[h2][w2];
    fr(0,w2){
        rep(j,0,h2){
            sumaColumnas[j][i] = val[j][i];
            if (j > 0){
                sumaColumnas[j][i] = (sumaColumnas[j][i] + sumaColumnas[j-1][i]) % mod;
            }
        }
    }
    cout << "suma columnas " << endl;
    fr(0,h2){
        rep(j,0,w2){
            cout << sumaColumnas[i][j] << ' ';
        }
        cout << endl;
    }
    ll sumaFilas[h2][w2];
    fr(0,h2){
        rep(j,0,w2){
            sumaFilas[i][j] = val[i][j];
            if (j > 0){
                sumaFilas[i][j] = (sumaFilas[i][j] + sumaFilas[i][j-1]) % mod;
            }
        }
    }
    cout << "suma filas " << endl;
    fr(0,h2){
        rep(j,0,w2){
            cout << sumaFilas[i][j] << ' ';
        }
        cout << endl;
    }
    //ya tengo la matrix armada de valores, es solo recorrer y sumar a la respuesta cuando tenga eso basicamente...
    ll res = 0;
    fr(h1-1, h2){
        rep(j, w1-1, w2){
            cout << "i = " << i << ", j = " << j <<  endl;
            ll cur = val[i][j];
            if (i >= h1){
                if (j >= w1){
                    cur = (((cur - (h1 * (sumaFilas[i-h1][j] - sumaFilas[i-h1][j-w1]))) % mod) + mod )% mod;
                } else {
                    cur = (((cur - h1 * (sumaFilas[i-h1][j])) % mod) + mod )% mod;
                }
            }
            if (j >= w1){
                if (j >= h1){
                    cur = (((cur - w1 * (sumaColumnas[i][j-w1] - sumaColumnas[i-h1][j-w1])) % mod) + mod )% mod;
                } else {
                    cur = (((cur - h1 * (sumaColumnas[i][j-w1]))  % mod) + mod) % mod;
                }
            }
            // if (i >= h1){
            //     cur = (((cur - val[i-h1][j]) % mod )+ mod )% mod;
            // }
            // if (j >= w1){
            //     cur = (((cur - val[i][j-w1]) % mod )+ mod )% mod;
            // }
            // if (i >= h1 && j >=w1){
            //     cur = (cur +  val[i-h1][j-w1] )% mod;
            // }
            if (cur == sumaPatron){
                cout << "ACA ENCONTRE " << endl;
                res++;
            }
        }
    }
    cout << res << '\n';
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("J.in", "r", stdin);
        // freopen("A.out", "w", stdout);
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