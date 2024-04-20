
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    // cout << "6" << endl;
    set<char> s;
    string words[n];
    set<char> proh;
    vector<char> primera;
    char ultima;
    fr(0,n){
        string ss; cin >> ss;
        words[i] = ss;
        proh.insert(ss[0]);
        if (i < n-1){
            primera.pb(ss[ss.size()-1]);
        } else {
            ultima = (ss[ss.size()-1]);
        }
        rep(j, 0, ss.size()){
            s.insert(ss[j]);
        }
    }
    //PRUEBA DIEGO
    map<char, int> mapaLetra;
    int i = 0;
    fre(s){
        mapaLetra[e] = i;
        i++;
    }
    
    vector<char> prohibidos;
    fre(proh){
        prohibidos.pb(e);
    }
    vector<char> vectorS;
    fre(s){
        vectorS.pb(e);
    }
    if (s.size() > 10){
        cout << 0 << "\n"; return;
    }
    ll res = 0;
    vector<int> a;
    fr(0,10){
        a.pb(i);
    }
    int iter = 0;
    unordered_map<char,int> m;
    unordered_set<string> seen;
    do{
        string numero = "";
        bool continuar = false;
        fr(0,vectorS.size()){
            char val = vectorS[i];
            if (a[i] == 0){
                rep(j,0,prohibidos.size()){
                    if (prohibidos[i] == val){
                        continuar = true;
                        break;  
                    }
                }
            }
            if (continuar){
                break;
            }
            m[val] = a[i];
            numero+=m[val];
            // numero += a[mapaLetra[val]];
        }
        if (continuar){
            continue;
        }
        if (seen.find(numero) != seen.end()){
            continue;
        }
        seen.insert(numero);

        ll last = 0;
        fr(0,primera.size()){
            last += m[primera[i]];
            // last += a[mapaLetra[primera[i]]];
        }
        if (last % 10 != m[ultima]){
            continue;
        }
        // if (last % 10 != a[mapaLetra[ultima]]){
        //     continue;
        // }

        ll suma = 0;
        ll curWord = 0;
        fr(0,n){
            curWord = 0;
            string s1 = words[i];
            for (char c: s1){
                curWord = curWord * 10 + m[c]; //a[mapaLetra[c]]
            }
            if(i == n-1){
                if (curWord == suma){
                    res++;
                }
            }
            suma += curWord;
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << res << "\n";
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