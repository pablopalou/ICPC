#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

void imprimirHora(int mini){
    int hora = mini / 3600;
    mini %= 3600;
    int minutos = mini / 60;
    mini %= 60;
    int seg = mini;
    string res = "0";
    res += to_string(hora);
    res.pb(':');
    if (minutos < 10){
        res.pb('0');
    }
    res += to_string(minutos);
    res.pb(':');
    if (seg < 10){
        res.pb('0');
    }
    res += to_string(seg);
    cout << res << "\n";
}

void solve2(vector<int> a){
    int mini = 1e9;
    fr(0,a.size()){
        mini = max(0,min(a[i]-5, mini));
    }
    // cout << mini << endl;
    fr(mini, 18001){
        bool verde = true;
        rep(j,0,a.size()){
            if (i % (2 * a[j]) >= a[j] - 5){
                verde = false;
                break;
            }
        }
        if (verde){
            imprimirHora(i);
            return;
        }
    }
    cout << "Signals fail to synchronise in 5 hours" << "\n";
    // fr(0,a.size()){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
}

// Copiar obligatoriamente 0
void solve() {
    int n;
    while(1){
        vector<int> a;
        while(cin >> n){
            if (n==0 && a.size() == 0){
                return;
            } else if (n==0){
                break;
            }
            a.pb(n);
        }
        solve2(a);
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