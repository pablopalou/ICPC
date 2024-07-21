#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
//NO ANDA, LO HICE EN EL D2 QUE si dio ACCEPTED
// Copiar obligatoriamente 0
void solve() {
    int cant1 = 0; int cant0 = 0;
    int res = 0;
    string s; cin >> s;
    fr(0,s.size()){
        if (s[i] == '1'){
            cant1++;
        } else {
            cant0++;
        }
    }
    if (cant1 == s.size() || cant0 == s.size()){
        cout << 1 << "\n"; return;
    }
    if(cant0 == 1 && s[s.size()-1] == '0'){
        cout << 2 << "\n"; return;
    }
    int cambios = 0;
    char ant = s[0];
    fr(1,s.size()){
        if (s[i] != ant){
            cambios++;
            ant = s[i];
        }
    }
    cout << cambios << "\n";
    // bool hayUno = false;
    // int i = 0;
    // while(i < s.size()){
    //     if (!hayUno && s[i] == '0'){
    //         i++; continue;
    //     }
    //     if (!hayUno && s[i] == '1'){
    //         hayUno = true; i++; continue;
    //     }
    //     if (hayUno && s[i] == '1'){
    //         i++; continue;
    //     }
    //     if (hayUno && s[i] == '0'){
    //         hayUno = false;
    //         i++;
    //         res++;
    //     }
    // }
    // cout << res+1 << "\n";
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