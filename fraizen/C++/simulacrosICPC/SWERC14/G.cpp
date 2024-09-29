#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize

int realN, realN2;

struct pto{
    int x;
    int y;
    bool operator<(const pto& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }

    // Optional: Define equality operator if you need it elsewhere
    bool operator==(const pto& other) const {
        return x == other.x && y == other.y;
    }
};

vector<pto> rotar(int cant, int permX[], int permY[], int n){
    int permFraizenX[n], permFraizenY[n];
    fr(0,n){
        permFraizenX[i] = permX[i];
        permFraizenY[i] = permY[i];
    }
    fr(0,cant){
        //aca lo roto
        int maxi = 0;
        rep(j,0,n){
            maxi = max(maxi, permFraizenX[j]);
        }
        rep(j,0,n){
            int auxX = permFraizenX[j];
            permFraizenX[j] = permFraizenY[j];
            permFraizenY[j] = -auxX;
            permFraizenY[j] += maxi;
        }
    }
    vector<pto> res;
    fr(0,n){
        pto punto;
        punto.x = permFraizenX[i]; punto.y = permFraizenY[i];
        res.pb(punto);
    }
    return res;
}

void solve() {
    int n1; cin >> n1;
    int p1x[n1], p1y[n1];
    set<int> ejeX1, ejeY1;
    fr(0,n1){
        cin >> p1x[i] >> p1y[i];
        ejeX1.insert(p1x[i]);
        ejeY1.insert(p1y[i]);
    }
    int perm1x[n1], perm1y[n1];
    fr(0,n1){
        perm1x[i] = distance(ejeX1.begin(), ejeX1.find(p1x[i]));
        perm1y[i] = distance(ejeY1.begin(), ejeY1.find(p1y[i]));
    }

    int n2; cin >> n2;
    int p2x[n2], p2y[n2];
    set<int> ejeX2, ejeY2;
    fr(0,n2){
        cin >> p2x[i] >> p2y[i];
        ejeX2.insert(p2x[i]);
        ejeY2.insert(p2y[i]);
    }
    int perm2x[n2], perm2y[n2];
    fr(0,n2){
        perm2x[i] = distance(ejeX2.begin(), ejeX2.find(p2x[i]));
        perm2y[i] = distance(ejeY2.begin(), ejeY2.find(p2y[i]));
    }
    //ya tengo el permutominio pa los 2, es cuestion de rotar y ver si son iguales... 

    fr(0,4){
        vector<pto> puntos = rotar(i,perm1x, perm1y, n1);
        // cout << "primer permutominio luego de rotar " << i << " veces \n";
        // fre(puntos){
        //     cout << e.x << " " << e.y << endl;
        // }
        rep(j,0,4){
            vector<pto> puntos2 = rotar(j, perm2x, perm2y, n2);
            // cout << "segundo permutominio luego de rotar " << j << " veces \n";
            // fre(puntos2){
            //     cout << e.x << " " << e.y << endl;
            // }
            if (puntos.size() != puntos2.size()){
                continue;
            }
            bool salir = false;
            sort(puntos.begin(), puntos.end());
            sort(puntos2.begin(), puntos2.end());
            rep(k,0,puntos.size()){
                if ((puntos[k].x != puntos2[k].x) or (puntos[k].y != puntos2[k].y)){
                    salir = true;
                }
            }
            if (salir){
                continue;
            }
            cout << "yes\n"; return;
        }
    }
    cout << "no\n";return;
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