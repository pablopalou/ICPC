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
    string s[n];
    set<char> letras;
    set<char> prohibidos;
    ll fact[10];
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    fact[3] = 6;
    fact[4] = 24;
    fact[5] = 120;
    fact[6] = 720;
    fact[7] = 7 * fact[6];
    fact[8] = 8 * fact[7];
    fact[9] = 9 * fact[8];
    fr(0,n){
        cin >> s[i];
        prohibidos.insert(s[i][0]);
        rep(j,0,s[i].size()){
            letras.insert(s[i][j]);
        }
    }
    int cantLetras = letras.size();
    char a[cantLetras];
    int i = 0;
    fre(letras){
        // cout << e << endl;
        a[i] = e; i++;
    }
    vector<int> perm;
    fr(0,10){
        perm.pb(i);
    }
    //tengo como mucho 10 letras
    ll res= 0;
    int valor[26]; memset(valor, 0, sizeof(valor));
    // unordered_set<ll> usado;
    int iter = 0;
    map<char, int> m;
    fr(0,cantLetras){
        m[a[i]] = i;
    }
    do {
        iter++;
        //cada una de las letras va a tener el valor de perm
        ll valorPerm = 0;
        bool salir = false;
        // if (perm[0] == 0 && perm[1] == 8 && perm[2] == 3 && perm[3] == 1 && perm[4] == 2 && perm[5]== 4 && perm[6] == 5 && perm[7]==6 && perm[8] == 7 && perm[9] == 9){
        //     cout << "SIIIII " << endl;
        // }
        // fr(0,10){
        //     cout << perm[i] << ' ';
        // }
        // cout << endl;
        fr(0,cantLetras){
            // cout << (a[i]-'A') << endl;
            valor[a[i]-'A'] = perm[i];
            if (perm[i] == 0 && prohibidos.find(a[i]) != prohibidos.end()){
                salir = true;
                break;
            }
            valorPerm = valorPerm * 10 + valor[a[i]-'A'];
        }
        // if (perm[0] == 0 && perm[1] == 8 && perm[2] == 3 && perm[3] == 1 && perm[4] == 5 && perm[5]== 4 && perm[6] == 6 && perm[7]==2 && perm[8] == 7 && perm[9] == 9){
        //     cout << "valor = " << endl;
        // fr(0,26){
        //     cout << valor[i] << " ";
        // }
        // cout << endl;
        // }
        // cout << "valor = " << endl;
        // fr(0,26){
        //     cout << valor[i] << " ";
        // }
        // cout << endl;
        if (salir){
            // cout << "ya use" << endl;
            continue;
        }
        //hago la cuentita
        ll suma = 0; ll ultimaPalabra = 0;
        fr(0,n-1){
            //calcular la palabra
            ll valorPalabra = 0;
            fre(s[i]){
                // cout << e << endl;
                // cout << "valor de e " << valor[e-'A'] << endl;
                valorPalabra = valorPalabra * 10 + valor[e-'A'];
            }
            // if (perm[0] == 0 && perm[1] == 8 && perm[2] == 3 && perm[3] == 1 && perm[4] == 5 && perm[5]== 4 && perm[6] == 6 && perm[7]==2 && perm[8] == 7 && perm[9] == 9){
            //     cout << "valor palabra = " << valorPalabra << endl;
            // }
            // if (valor[0] == 0 && valor[2] == 8 && valor[4] == 3 && valor[6] == 1 && valor[14] == 5 && valor[15] == 4 && valor[17] == 6){
            //     cout << "valor palabra = " << valorPalabra << endl;
            // }
            suma += valorPalabra;
        }
        fre(s[n-1]){
            ultimaPalabra = ultimaPalabra * 10 + valor[e-'A'];
        }
        // cout << "Suma =  " << suma << endl;
        // cout << "Ult pal " << ultimaPalabra << endl;
        // cout << "ult palb " << ultimaPalabra << endl;
        if (suma == ultimaPalabra){
            res++;
        }
        // usado.insert(valorPerm);
        // cout << "res " << res << endl;
    } while(next_permutation(perm.begin(), perm.end()));
    cout << res / fact[10-cantLetras] << '\n';
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