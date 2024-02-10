#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define ld long double

struct Point{
    ld x,y,z;
};
Point points[102];
const int MAXC = 10004;
ld lx, ly, lz;
int n;



ld distance (ld x, ld y, ld z, Point p){
    ld dx = p.x - x;
    ld dy = p.y - y;
    ld dz = p.z - z;
    return dx * dx + dy * dy + dz*dz;
}

ld dist(ld x, ld y, ld z){
    ld maxDist = 0;
    fr(0,n){
        maxDist = max(maxDist, distance(x, y , z, points[i]));
    }
    return maxDist;
}

ld ternaryz(ld x, ld y){
    ld ini = -MAXC; ld fin = MAXC;
    fr(0,80){
        ld m1 = ini + (fin - ini) / 3; ld m2 = fin - (fin - ini) / 3;
        if (dist(x, y, m1) < dist(x,y, m2)){
            fin = m2;
        } else {
            ini = m1;
        }
    }
    lz = ini;
    return dist(x,y,lz);
}

ld ternaryy(ld x){
    ld ini = -MAXC; ld fin = MAXC;
    fr(0,60){
        ld m1 = ini + (fin - ini) / 3; ld m2 = fin - (fin - ini) / 3;
        if (ternaryz(x, m1) < ternaryz(x, m2)){
            fin = m2;
        } else {
            ini = m1;
        }
    }
    ly = ini;
    return ternaryz(x,ly);
}

void ternaryx(){
    ld ini = -MAXC; ld fin = MAXC;
    fr(0,60){
        ld m1 = ini + (fin - ini) / 3; ld m2 = fin - (fin - ini) / 3;
        if (ternaryy(m1) < ternaryy(m2)){
            fin = m2;
        } else {
            ini = m1;
        }
    }
    lx = ini;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n){
        Point p; cin >> p.x >> p.y >> p.z;
        points[i] = p;
    }
    // como son 100 puntos y calculamos la distancia solo al final, podria hacer aprox 70*70*90*100y deberia funcionar (no funciono asi que baje a 60*60*80*100).
    ternaryx(); //hace la ternaria en x. (la ternaria en x se encarga de llamar a "y" y la "y" de llamar a "z")
    cout << fixed << setprecision(10) << lx << ' ' << ly << ' ' << lz << '\n';
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