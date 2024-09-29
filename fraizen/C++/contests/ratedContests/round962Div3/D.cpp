#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll n,x; cin >> n >> x;
    ll raiz = sqrt(n);
    ll res = 0;
    ll todosIguales = 0;
    ll dosIguales = 0;
    ll distintos = 0;
    for(int a = 1; a <= raiz; a++){
        for(int b = a; b <=raiz; b++){
            // cout << "A = " << a << " b= " << b << endl; 
            //cuanto puede ser c ? 
            ll c = 1e9;
            c = min(c, x - a - b);
            c = min(c, (n - a*b)/ (a+b));
            c = max(c, 0LL);
            // cout << "c = " << c << endl;
            if (c >= b){ //agrego solo el caso del c == b
                if (a == b){
                    todosIguales++;
                } else {
                    dosIguales++;
                }
            } 
            if(c>b) {
                if (a == b){
                    dosIguales += c-b;
                } else {
                    distintos += c-b;
                }
            }
        }
    }
    // cout << "Distintos = " << distintos << endl;
    // cout << "dosIguales = " << dosIguales << endl;
    // cout << "todosIguales = " << todosIguales << endl; 
    res = distintos * 6 + dosIguales * 3 + todosIguales;
    cout << res << '\n';
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