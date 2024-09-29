#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define MAXN 500

void solve() {
    string line;
    getline(cin, line);
    vector <string> words;
    stringstream check1(line);
    string intermediate;
    while(getline(check1, intermediate, ' ')){
        words.push_back(intermediate);
    }
    int cant = words.size();
    //tengo que generar todos los strings primero
    string s[MAXN];
    string medio;
    //pongo el primero
    if (cant == 4){
        medio = words[1][0] + words[2];
    } else if (cant == 3){
        medio = words[1];
    }
    //PONER LA PRIMERA A HUEVO
    s[0] = words[0][0] + medio + words[cant-1][0];
    int largoSegApellido = words[cant-1].size();
    int cont = 1;
    for(int i = 2; i < words[0].size()+1; i++){ //cant letras del primer nombre
        for(int j = 0; j <= min(largoSegApellido, i); j++){ // cant letras del segundo apellido
            s[cont] = words[0].substr(0, i) + medio + words[cant-1].substr(0,j);
            cont++;
        }
    }
    //ojo que pueden faltar si el largo del segundo apellido es mas largo que el primer nombre. LISTO 
    if (largoSegApellido > words[0].size()){
        for(int i = words[0].size()+1; i <= largoSegApellido; i++){
            //poner i letras del segundo apellido hasta terminar
            s[cont] = words[0] + medio + words[cant-1].substr(0,i);
            cont++;
        } 
    }
    //YA FORME TODO 
    //ahora solo hacer binaria.
    //encontrar la mas a la izquierda que devuelva 1
    int l = 0;
    int r = cont;
    int officialRes = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        cout << s[mid] << endl;
        int res; cin >> res;
        if (res == 1){ //usado, me voy pa la derecha
            l = mid+1;
        } else {
            officialRes = mid;
            r = mid-1;
        }
    }
    cout << "! " << s[officialRes] << endl;
    // fr(0,cont){
    //     cout << s[i] << '\n'; 
    // }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}