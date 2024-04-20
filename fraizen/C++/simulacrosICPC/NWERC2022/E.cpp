#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    int a = int(s[0]-'0');
    int b = int(s[2]-'0');
    map<int, vector<int>> m;
    int suma = 0;
    int curNode = 1;
    // //pongo nodo 1 en distancia 0.
    // m[0] = {1}; 
    // cout << a<< endl;
    // cout << b << endl;
    if (a < b){
        if (a + 1 != b){
            cout << "impossible" << "\n";
            return;
        } else {
            //imprimir grafo de 1 conectado con todos
            cout << b << " " << b-1 << "\n";
            fr(2,b+1){
                cout << 1 << ' ' << i << "\n";
            }
            return;
        }
    } else if (a == b){
        //imprimir grafo 1 conectado con 2 y el 2 con 3. Despues todos conectados al 1.
        cout << "3 2\n";
        cout << "1 2\n";
        cout << "2 3\n";return;
    } else {
            int b2 = b;
            int iter = 0;
            // me parece que es mejor poner hasta n y fijarse cuanto daria...
            // cout << double(double(b2 * (b2-1) / 2)/ b2) << endl;
            // cout << double(a/double(b)) << endl;
            // return;
            while( double(double(b2 * (b2-1) / 2)/ b2) <= double(a/double(b))){
                // cout << "Entro con " << double(double(b2 * (b2-1) / 2)/ b2) << endl;
                //agrego todos digamos desde curNode a curNode + b (exclusive)
                fr(0,b){
                    m[b2-b + i] = {curNode};
                    curNode++;
                }
                suma = b2;
                b2 += b;
                iter++;
            }
            suma = (curNode-1) * (curNode-2) / 2;
            // cout << "suma actual " << suma << endl;
            // return;
            //ahora si es la ultima iteracion nomas seguro.
            //tendria que ver cuanto falta...
            //tengo suma en curNode. curNode deberia ser multiplo de b
            //voy a tener curNode + b nodos al final...
            int faltaSumar = (iter+1) * a - suma;
            int faltaPoner = b;
            // cout << faltaSumar << endl;
            // cout << faltaPoner << endl;
            // return;
            // if (m[faltaSumar / faltaPoner -1].size()>0){
            //     //ya ponemos ahi y terminariamos
            //     //cantidad de falta/faltaPoner+1 seria:
            //     int cantMasUno = faltaSumar % faltaPoner;
            //     int cantNormal = faltaPoner - cantMasUno;
            //     //TODO: agrego esos nodos e imprimo.
            //     // o sea agregar a faltaSumar / faltaPoner -1 esta cantidad de nodos: cantNormal 
            //     //agregar a cantMasUno esta cantidad de nodos: 
            // } else {
                //ir agregando hasta ese nodo minimo...
            while(m[(faltaSumar / faltaPoner)-1].size()==0){ //tengo el anterior...
                // cout << "agrego " << curNode << endl;
                suma += (faltaSumar / faltaPoner)-1;
                // cout << "Sumo " << (faltaSumar / faltaPoner)-1 << endl;
                //agrego el nodo
                m[(faltaSumar / faltaPoner)-1] = {curNode};
                faltaSumar -= ((faltaSumar / faltaPoner)-1);
                faltaPoner--;
                curNode++;
            }
            //ahora si ya tengo todo
            int cantMasUno = faltaSumar % faltaPoner;
            int cantNormal = faltaPoner - cantMasUno;
            //TODO: agrego esos nodos e imprimo.
            // o sea agregar a faltaSumar / faltaPoner -1 esta cantidad de nodos: cantNormal 
            fr(0,cantNormal){
                m[faltaSumar / faltaPoner].pb(curNode);
                curNode++;
            }
            //  //agregar a faltaSumar / faltaPoner esta cantidad de nodos : cantMasUno
            fr(0,cantMasUno){
                m[faltaSumar / faltaPoner + 1].pb(curNode);
                curNode++;
            }
            cout << curNode -1 << ' ' << curNode - 2 << "\n";
            fr(1, faltaSumar/faltaPoner + 1){
                fre(m[i]){
                    cout << e << ' ' << m[i-1][0] << '\n';
                }
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
        freopen("e.out", "w", stdout);
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