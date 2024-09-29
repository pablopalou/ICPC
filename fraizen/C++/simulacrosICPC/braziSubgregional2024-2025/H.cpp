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

ll expMod(ll b, ll e, ll m) {  // O(log e)
  if (e < 0) return 0;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * b % m;  // ret = mulMod(ret,b,m); //if needed
    b = b * b % m;                 // b = mulMod(b,b,m);
    e >>= 1;
  }
  return ret;
}

ll calcularN(string s){
    ll res = 0;
    fr(0,s.size()){
        res *=2;
        if (s[i] == '1'){
            res++;
        }
    }
    return res;
}

void solve() {
    string s1,s2; cin >> s1 >> s2;
    vector<ll> pos;
    fr(0,s2.size()){
        if (s2[i] == '*'){
            pos.pb(i);
        }
    }
    rep(mask, 0, (1<<pos.size())){
        string cur = s2;
        rep(j,0,pos.size()){
            if (mask & (1<<j)){
                cur[pos[j]] = '1';
            } else {
                cur[pos[j]] = '0';
            }
        }
        ll nuevoN = calcularN(cur);
        // cout <<" NUEVO N = " << nuevoN << endl;
        //tengo el nuevoN
        //para cada N, me tengo que fijar el M mod N para ver si alguno da 0. 
        //en principio veo los que estan fijos y los calculo...
        ll realMod = 0;
        ll mod = nuevoN;
        vector<ll> ast;
        fr(0,s1.size()){
            if (s1[i] == '1'){
                realMod = (realMod + (expMod(2,s1.size()-i-1, mod))) % mod;
            } else if (s1[i] == '*'){
                ast.pb(i);
            }
        }
        // cout <<"realMod " << realMod << endl;
        // cout << "asteriscos en " << endl;
        // fre(ast){
        //     cout << e << ' ';
        // }
        // cout << endl;
        //veo el resto del numero que tiene asteriscos a ver si lo puedo dejar en 0
        rep(mask2, 0, (1<<ast.size())){
            ll curMod = realMod; 
            string cur2 = s1;
            // cout << "Mask : " << mask2 << endl;
            rep(j,0,ast.size()){
                if (mask2 & (1 << j)){
                    cur2[ast[j]] = '1';
                    //actualizo el curMod
                    curMod = (curMod + (expMod(2,s1.size()-1-ast[j],mod))) % mod ;
                } else {
                    cur2[ast[j]] = '0';
                    //el curMod queda igual
                }
            }
            // cout << "pruebo con " << cur2 << endl;
            if (curMod == 0){
                cout << cur2 << "\n";
                return;
            }
        }
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