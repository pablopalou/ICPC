#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

bool estaEnElMedio(int a, int b, int c){
    if (a >=b && a <= c){
        return true;
    }
    if (a >=c && a <= b){
        return true;
    }
    return false;
}

set<int> posiciones(int i, int j){
    set<int> s;
    if (i>0){
        s.insert((i-1)*8 + j);
    }
    if (i<7){
        s.insert(8*(i+1) + j);
    }
    if (j > 0){
        s.insert(i*8 + j - 1);
    }
    if (j < 7){
        s.insert(i*8 + j + 1);
    }
    return s;
}

// Copiar obligatoriamente 0
void solve() {
    int k,q,newQ;
    while(cin >> k >> q >> newQ){
        if (k == q) {
            cout << "Illegal state\n"; continue;
        }
        int i1 = k/8;
        int j1 = k%8;
        int i2 = q/8;
        int j2 = q%8;
        int i3 = newQ/8;
        int j3 = newQ%8;

        if ((i2 != i3 && j2!=j3) || (newQ == q)){ //si no me puedo mover porque no es misma fila o columna 
            cout << "Illegal move\n"; continue;
        }
        // o tengo que pasar por arriba del otro:
        if (i1 == i3){
            if (estaEnElMedio(j1,j2,j3)){
                cout << "Illegal move\n"; continue;
            }
        } else if (j1 == j3){
            if (estaEnElMedio(i1,i2,i3)){
                cout << "Illegal move\n"; continue;
            }
        }
        //el movimiento lo podria hacer pero esta a uno del rey:
        set<int> s = posiciones(i1,j1);
        if (s.find(newQ) != s.end()) {
            cout << "Move not allowed\n"; continue;
        }
        //el king acorralado
        if ((k==0 && newQ == 9) || (k == 7 && newQ == 14) || (k == 56 && newQ == 49) || (k == 63 && newQ == 54)){
            cout << "Stop\n"; continue;
        }
        //todo legal:
        cout << "Continue\n"; continue;
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