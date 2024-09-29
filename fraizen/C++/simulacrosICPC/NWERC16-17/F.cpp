#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

struct UnionFind {
  int nsets;
  vector<int> f, setsz;  // f[i] = parent of node i
  UnionFind(int n) : nsets(n), f(n, -1), setsz(n, 1) {}
  int comp(int x) { return (f[x] == -1 ? x : f[x] = comp(f[x])); }  // O(1)
  bool join(int i, int j) {  // returns true if already in the same set
    int a = comp(i), b = comp(j);
    if (a != b) {
      if (setsz[a] > setsz[b]) swap(a, b);
      f[a] = b;  // the bigger group (b) now represents the smaller (a)
      nsets--, setsz[b] += setsz[a];
    }
    return a == b;
  }
};

void solve() {
    int n,m; cin >> n >> m;
    UnionFind uf = UnionFind(n);
    string s[m];
    fr(0,m){
        cin >> s[i];
        rep(j,0,s[i].size()){
            if (s[i][j] == '='){
                uf.join(stoi(s[i].substr(0,j)) - 1, stoi(s[i].substr(j+1)) - 1);
            }
        }
    }
    //ACORDARSE DE RESTAR UNO
    //meto en un mapa los de mismo componente
    map<ll,vector<int>> mapa;
    fr(0,n){
        mapa[uf.comp(i)].pb(i);
    }
    int colorComp[n]; fr(0,n) colorComp[i] = 7;
    int color[n]; fr(0,n) color[i] = 7;
    //ahora si proceso las queries (menos las qeu tienen igual que ya las procese)
    // cout << "Colores: " << endl;
    // fr(0,n){
    //     cout << color[i] << ' ';
    // }
    // cout << endl;
    bool compare[n];
    fr(0,n) compare[i] = false; 
    map<int,vector<int>> mapaFraizenMenor;
    map<int,vector<int>> mapaFraizenMayor;
    fr(0,m){
        rep(j,0,s[i].size()){
            if (s[i][j] == '<' or s[i][j] == '>'){
                int num1,num2;
                if (s[i][j] == '<'){
                    num1 = stoi(s[i].substr(0,j)) - 1;
                    num2 = stoi(s[i].substr(j+1)) - 1;
                } else {
                    num2 = stoi(s[i].substr(0,j)) - 1;
                    num1 = stoi(s[i].substr(j+1)) - 1;
                }
                mapaFraizenMenor[num1].pb(num2);
                mapaFraizenMayor[num2].pb(num1);
                compare[num1] = true;
                compare[num2] = true;
                color[num1] &= 3;
                int curColor = colorComp[uf.comp(num1)];
                color[num1] &= curColor;
                if (curColor == 1 or curColor == 2 or curColor == 4){

                } else {
                    colorComp[uf.comp(num1)] &= color[num1];
                    curColor = colorComp[uf.comp(num1)];
                    if (curColor == 1 or curColor == 2 or curColor == 4){
                        //tengo que pintar la componente
                        fre(mapa[uf.comp(num1)]){
                            color[e] = curColor;
                        }
                    }
                }

                color[num2] &= 6;
                curColor = colorComp[uf.comp(num2)];
                color[num2] &= curColor;
                if (curColor == 1 or curColor == 2 or curColor == 4){

                } else {
                    colorComp[uf.comp(num2)] &= color[num2];
                    curColor = colorComp[uf.comp(num2)];
                    if (curColor == 1 or curColor == 2 or curColor == 4){
                        //tengo que pintar la componente
                        fre(mapa[uf.comp(num2)]){
                            color[e] = curColor;
                        }
                    }
                }

                if (color[num1] == 2){
                    //ya lo tengo definido, entonces yo se que el mas grande es si o si el blanco
                    color[num2] = 4; 
                    curColor = colorComp[uf.comp(num2)];
                    if (curColor == 1 or curColor == 2 or curColor == 4){

                    } else {
                        colorComp[uf.comp(num2)] &= color[num2];
                        curColor = colorComp[uf.comp(num2)];
                        if (curColor == 1 or curColor == 2 or curColor == 4){
                            //tengo que pintar la componente
                            fre(mapa[uf.comp(num2)]){
                                color[e] = curColor;
                            }
                        }
                    }
                } else if (color[num2] == 2){
                    //el mas chico tiene que ser si o si azul, 1
                    color[num1] = 1;
                    curColor = colorComp[uf.comp(num1)];
                    if (curColor == 1 or curColor == 2 or curColor == 4){

                    } else {
                        colorComp[uf.comp(num1)] &= color[num1];
                        curColor = colorComp[uf.comp(num1)];
                        if (curColor == 1 or curColor == 2 or curColor == 4){
                            //tengo que pintar la componente
                            fre(mapa[uf.comp(num1)]){
                                color[e] = curColor;
                            }
                        }
                    }
                }
                cout << "Colores: " << endl;
                fr(0,n){
                    cout << color[i] << ' ';
                }
                cout << endl;
                break;
            }   
        }
    }
    bool tengo[3];
    tengo[0] = false;
    tengo[1] = false;
    tengo[2] = false;
    fr(0,n){
        if (color[i] == 1){
            tengo[0] = true;
        } else if (color[i] == 2){
            tengo[1] = true;
        } else if (color[i] == 4){
            tengo[2] = true;
        }
    }
    if (tengo[0] + tengo[1] + tengo[2] == 2){
        string falta; 
        if (!tengo[0]){
            falta = "B";
        } else if (!tengo[1]){
            falta = "R";
        } else {
            falta = "W";
        }
        fr(0,n){
            if (color[i] == 1){
                cout << "B";
            } else if (color[i] == 2){
                cout << "R";
            }else if (color[i] == 4){
                cout << "W";
            }else if (compare[i]){
                cout << falta;
            } else {
                cout << "?";
            }
        }
        return;
    }
    //hay que fijarse si ya tengo uno mas chico o algo
    fr(0,n){
        if (color[i] == 1){
            cout << "B";
        } else if (color[i] == 2){
            cout << "R";
        }else if (color[i] == 4){
            cout << "W";
        }else {
            bool salir = false;
            fre(mapaFraizenMenor[i]){
                if (color[e] == 2){
                    cout << "B";
                    salir = true;
                    break;
                }
            }
            fre(mapaFraizenMayor[i]){
                if (color[e] == 2){
                    cout << "W";
                    salir = true;
                    break;
                }
            }
            if (salir){
                continue;
            }
            cout << "?";
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
    //     freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);

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