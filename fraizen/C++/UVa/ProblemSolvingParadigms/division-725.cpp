#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

string add0(int num){
    if (num < 10000){
        return "0" + to_string(num);
    }
    return to_string(num);
}
// Copiar obligatoriamente 0
void solve() {
    int n; 
    while(cin >> n){
        if (n == 0){return;}
        //probamos numerador crecientes
        int res = 0;
        for (int abcde = 1234; abcde <= 98765; abcde++){
            if (abcde % n == 0){
                int fghij = abcde / n;
                // solo falta ver si use todos del 0 al 9;
                int used = 0;
                int a = abcde;
                int b = fghij;
                fr(0,5){
                    used |= (1 << (a % 10));
                    a /= 10; 
                    used |= (1 << (b % 10));
                    b /= 10; 
                }
                if (used == ((1 << 10) - 1)){
                    cout << add0(abcde) << " / " << add0(fghij)   << "\n";
                    res++;
                }
            }
        }
        if (res == 0){
            cout << "There are no solutions for " << n << ".\n";
        }
        cout << "\n";
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