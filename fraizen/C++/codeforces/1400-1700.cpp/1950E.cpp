#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

bool casiIguales(string s1, string s2){
    int cont = 0;
    fr(0,s1.size()){
        if (s1[i] != s2[i]){
            cont++;
            if (cont == 2){
                return false;
            }
        }
    }
    return true;
}

bool esSolucion(int largo, string s){
    int n = s.size();
    int cant = n/largo;
    string prefix = s.substr(0,largo);
    string suffix = s.substr(n-largo);
    string s1,s2;
    fr(0,cant){
        s1+=prefix;
        s2+=suffix;
    }
    return casiIguales(s1, s) || casiIguales(s2,s);
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; string s; cin >> s;
    set<int> div;
    fr(1,int(ceil(sqrt(n)))+1){
        if (n % i == 0){
            div.insert(i);
            div.insert(n/i);
        }
    }
    fre(div){
        if (esSolucion(e, s)){
            cout << e << "\n"; return;
        }
    }
    cout << n << "\n"; //no deberia llegar aca
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}