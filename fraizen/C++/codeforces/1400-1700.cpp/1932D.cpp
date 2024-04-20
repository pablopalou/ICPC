#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

//la idea ta bien, pero ta todo buggeado, habria que arrancar de 0. 

//lo mejor en estos ejercicios seria hacer string suites = "CDHS" y luego hacer find  ahi...



// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    char c; cin >> c;
    map<char, vector<int>> m;
    fr(0,2 * n){
        string s; cin >> s;
        m[s[1]].pb(s[0] - '0');
    }
    if (m[c].size() < ((m['C'].size() & 1) + (m['S'].size() & 1) + (m['H'].size() & 1) + (m['D'].size() & 1) - (m[c].size() & 1))){
        cout << "IMPOSSIBLE\n"; return;
    }
    // fre(m['C']){
    //     cout << e << ' ';
    // }
    // cout << endl;
    // fre(m['S']){
    //     cout << e << ' ';
    // }
    // cout << endl;
    // fre(m['D']){
    //     cout << e << ' ';
    // }
    // cout << endl;
    // fre(m['H']){
    //     cout << e << ' ';
    // }
    char suits[] = {'C', 'D', 'H', 'S'};
    for (char suit: suits){
        sort(m[suit].begin(), m[suit].end());
    }

    cout << endl;
    vector<string> falta;
    if (c != 'C'){
        cout << "Entro a C" << endl;
        for (int i = 0; i < m['C'].size(); i+=2){
            if (i+1 < m['C'].size()){
                cout  << m['C'][i] << "C" << ' '  << m['C'][i+1] << "C" << "\n";
            } else {
                cout << "Agrego a falta " << m['C'][i] + "C";
                falta.pb(m['C'][i] + "C");
            }
        }
    }
    if (c != 'S') {
        cout << "Entro a S" << endl;
        for (int i = 0; i < m['S'].size(); i+=2){
            if (i+1 < m['S'].size()){
                cout << m['S'][i] << "S" << ' ' << m['S'][i+1] << "S" << "\n";
            } else {
                cout << "Agrego a falta " << m['S'][i] + "S";
                falta.pb( m['S'][i] + "S");
            }
        }
    }
    if (c!='H'){
        cout << "Entro a H" << endl;
        for (int i = 0; i < m['H'].size(); i+=2){
            if (i+1 < m['H'].size()){
                cout<< m['H'][i]  << "H" << ' '<< m['H'][i+1] << "H"  << "\n";
            } else {
                cout << "Agrego a falta " << m['H'][i] + "H";
                falta.pb(m['H'][i] + "H");
            }
        }
    }
    if (c!= 'D'){
        cout << "Entro a D" << endl;
        for (int i = 0; i < m['D'].size(); i+=2){
            if (i+1 < m['D'].size()){
                cout << m['D'][i] << "D" << ' ' << m['D'][i+1] << "D" << "\n";
            } else {
                cout << "Agrego a falta " << m['D'][i] + "D";
                falta.pb( m['D'][i] + "D");
            }
        }
    }
    int j = 0;
    fre(falta){
        cout << e << ' ' << m[c][j] + c << "\n"; 
        j++;
    }
    for (int i = j; i < m[c].size(); i+=2){
        cout  << m[c][i] << c << ' ' << m[c][i+1] << c<< "\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}