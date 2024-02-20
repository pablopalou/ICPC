#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define inf 1e9
#define mp make_pair

int highest_bit_set(int n) {
  int result = 1;
  while(n >>= 1) /* keep shifting right until n == 0 */
    result++;
  return result;
}

// Copiar obligatoriamente 0
void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    map<int, vector<int> > pos;
    fr(0,n){
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    if (k >= 25){
        vector<int> res;
        set<int> s;
        vector<bool> buscando(k+1,true);
        int k2 = k;
        fr(0,n){
            if (buscando[a[i]] && s.find(a[i])==s.end()){
                s.insert(a[i]);
                // cout << s.size() << endl;
                if (s.size() == k2){
                    // cout << "llegue" << endl;
                    res.pb(a[i]);
                    buscando[a[i]] = false;
                    k2--;
                    s.clear();
                }
            }
        }
        fr(1,k+1){
            if (buscando[i]){
                res.pb(i);
            }
        }
        fr(0,k){
            cout << res[i] << endl;
        }
        return;
    }
    // k<= 24, dp con bitmasks
    // dp[mask] = max (x pertenciente a mascara) next(x, dp[mask-x]). Next(A,i) es el primer indice j > i tal que V[j] = A.
    //tendria que guardar otro valor mas me parece, que seria el anterior que me dejo en este estado... o sea guardo pareja con valor y mascara previa
    //MENTIRA, GUARDO EL BIT QUE APAGUE DIGAMOS.
    pair<int,int> dp[1<<k ];
    fill(dp, dp+(1<<k), mp(-1,-1));
    bool encontre = false;
    int mascaraInf;
    int anterior = -1;
    fr(1,k+1){
        if (pos[i].size() == 0){
            encontre = true;
            mascaraInf = 1 << (i-1); // mp((1 << (i-1)), i-1);
            break;
        }
        dp[1 << (i-1)] = mp(pos[i][0], -1);
    }
    if (!encontre){
        // cout << "entreo" << endl;
        rep(mask, 3,1<<k){
            // cout << "mask " <<  mask << endl;
            if (dp[mask].first!=-1) continue;
            fr(0,k){ //apago el bit i si lo tiene prendido
                if (mask & (1<<i)){
                    int prevMask = mask - (1<<i);
                    auto it = lower_bound(pos[i+1].begin(), pos[i+1].end(), dp[prevMask].first);
                    if (it == pos[i+1].end()){
                        dp[mask] = mp(inf, i);
                        encontre = true;
                        mascaraInf = mask;
                        anterior = i;
                        break;
                    } else {
                        if (dp[mask].first > *it){
                            //me quedo con dp mask, no actualizo nada
                        } else {
                            dp[mask] = mp(*it, i);
                        }
                    }
                }
            }
            if (encontre) break;
        }
    }
    // fr(1, (1<<k)){
    //     cout<< dp[i].first << ',' << dp[i].second << endl;
    // }
    if (! encontre){
        cout << "*\n"; return;
    }
    //reconstruyo respuesta usando la dp y luego pongo todos los que no estan en la mascara.
    //tengo mascara infinita.
    // lo primero que hago es ver cuales estan faltando...
    vector<int> falta;
    fr(0,k){
        if(! ((1 << i) & mascaraInf)){
            falta.pb(i+1);
        }
    }
    // fr(0,falta.size()){
    //     cout << falta[i] << ' ';
    // }

    //ahora voy pa atras en la mascara...
    vector<int> res;
    // cout << anterior << endl;
    while(anterior!=-1){
        // cout << "ant = " << anterior << endl;
        res.pb(anterior + 1);
        mascaraInf -= (1 << (anterior)); //capaz el anterior es -+1
        // cout << "masc = " << mascaraInf << endl;
        anterior = dp[mascaraInf].second;
    }
    // cout << mascaraInf << endl;
    //ver si no tengo que dar vuelta aca
    // cout << "highest " << highest_bit_set(mascaraInf) << endl;
    res.pb(highest_bit_set(mascaraInf));
    reverse(res.begin(), res.end());
    //todavia queda agregar todos los que tengo en el vector faltan
    fr(0,falta.size()){
        res.pb(falta[i]);
    }

    fr(0,res.size()){
        cout << res[i] << ' ';
    }
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