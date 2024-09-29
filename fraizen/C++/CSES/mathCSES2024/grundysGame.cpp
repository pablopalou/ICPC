#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int dp[2002];

ll mex(vector<int> &v){
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());
    int res = 0;
    fr(0,v.size()){
        if (v[i] != i){
            return i;
        }
    }
    return v.size();
}

void fillDP(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    fr(3,2001){
        vector<int> v;
        rep(j,1,(i+1)/2){
            v.pb(dp[j] ^ dp[i-j]);
        }
        dp[i] = mex(v);
    }
}
void solve() {
    //aca magicamente si el valor es mas grande que 2000, siempre hay una forma para que gane el primero.
    //sacando la magia la idea seria: 
    //yo tengo una pila de tamaño x, y la puedo dividir en 2 pilas disjuntas, entonces ahi podria aplicar grundy.
    //entonces yo para saber el numero de grundy de x, puedo hacer el xor de los numeros de grundy de las 2 pilas (que dividi digamos)
    // como si yo tengo ponele 5 puedo dividir en 1,4 y 2,3, tengo que poner los 2 grundys. 
    // luego me quedo con el mex de los grundy y listo. 
    int n; cin >> n;
    if (n >= 2000){
        cout << "first\n"; return;
    }
    if (dp[n] == 0){
        cout << "second\n"; return;
    }
    cout <<"first\n"; return;
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
    fillDP();
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}