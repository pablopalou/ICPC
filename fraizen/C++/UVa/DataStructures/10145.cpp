#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    char c; int tid; int data;
    map<int, set<int>> usados;
    map<int ,int> exc;
    set<int> bloq;
    while(cin >> c){
        if (c == '#') {
            cout << "\n"; return;
        }
        cin >> tid >> data;
        // cout << c << " " << tid << ' ' << data << endl;
        if (bloq.find(tid) != bloq.end()){
            cout << "IGNORED\n";
            continue;
        }
        if (c == 'S'){
            if (exc[data] && tid != exc[data]){
                bloq.insert(tid);
                cout << "DENIED\n"; 
            } else {
                cout << "GRANTED\n";
                usados[data].insert(tid);
            }
        } else {
            if (exc[data] && tid!= exc[data]){//esta excluido por otro
                cout << "DENIED\n"; 
                bloq.insert(tid);
                continue;
            } else if (exc[data]){ //ya lo tengo excluido para mi
                exc[data] = tid;
                cout << "GRANTED\n"; continue;
            }
            if (usados[data].size() > 1){ //hay mas de uno usandolo
                cout << "DENIED\n";  
                bloq.insert(tid);
                continue;
            } else if (usados[data].size() == 1 && usados[data].find(tid) == usados[data].end()){ //hay uno usandolo y no soy yo
                cout << "DENIED\n"; 
                bloq.insert(tid); 
                continue;
            } else if (usados[data].size() == 1) { // lo tengo yo
                exc[data] = tid;
                cout << "GRANTED\n"; continue;
            }
            exc[data] = tid;
            usados[data].insert(tid);
            cout << "GRANTED\n";
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}