#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    string s;
    while(1){
        //esta lectura esta perfecta si pongo while(cin >> s) arriba y el chequeo del s == "0:00", el tema que es larga, lo mejor es hacer lo de abajo:
        // int horas, minutos; horas = minutos = 0;
        // if (s.size() == 5){
        //     horas = stoi(s.substr(0,2));
        //     minutos = stoi(s.substr(3,2));
        // } else {
        //     horas = stoi(s.substr(0,1));
        //     minutos = stoi(s.substr(2,2));
        // }
        int horas, minutos; char sep;
        cin >> horas >> sep >> minutos;
        if (horas == 0 && minutos == 0){
            return;
        }
        //esto tambien esta perfecto, pero es un poco mas compacto lo de abajo:
        // double gh = (horas % 12) * 30 + minutos/double(2.0);
        // double gm = minutos * 6.0;
        // double a = min(gh,gm);
        // double b = max(gh, gm);
        // double res = b-a;
        // res = min(res, 360-b + a);
        double gh,gm;
        gh = minutos * 6.0;
        gm = (horas % 12) * 30 + minutos/double(2.0);
        double res = fabs(gh-gm);
        res = (min(res, 360-res));
        cout << fixed << setprecision(3) << res << endl;
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