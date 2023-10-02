#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(ll i = a; i<b; i++)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

struct P {
    ll x,y;
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x-b.x, y -b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    ll operator * (const P& b) const{
        return (ll) x*b.y - (ll) y * b.x;
    }
    bool operator < (const P& B) const{
        return make_pair(x,y) < make_pair(B.x, B.y);
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n <= 2){
        if (n == 1){
            cout(4);
            return 0;
        }
        // cout("CONSIDERAR ESTE CASO APARTE SUPONGO");
        // return 0;
    }
    vector<P> points(n);
    fr(0,n){
        points[i].read();
    }
    sort(points.begin(), points.end());
    vector<P> hull;
    fr(0,2){
        const ll S = hull.size();
        for(P C: points){
            while ((int) hull.size() - S >= 2){
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                if ((B-A) * (C-A) <= 0){
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(C);
        }
        hull.pop_back(); //remove rightmost point
        reverse(points.begin(), points.end());
    }
    // cout << hull.size() << "\n";
    // for(P p:hull){
    //     cout << p.x << ' ' << p.y << "\n";
    // }
    ll res = 0;
    n = hull.size();
    ll x1,y1;
    x1 = hull[0].x;
    y1 = hull[0].y;
    ll x2, y2;
    if (n == 2){
        x2 = hull[1].x;
        y2 = hull[1].y;
        if (x2-x1 == y2-y1){
            res++;
        }
        if (x1 == x2){
            if (y2 > y1){
                cout((y2-y1-1) * 2 + 6);
            } else {
                cout((y1-y2-1) * 2 + 6);
            }
            return 0;
        }
        if (y1 == y2){
            if (x2 > x1){
                cout((x2-x1-1) * 2 + 6);
            } else {
                cout((x1-x2-1) * 2 + 6);
            }
            return 0;
        }
    }
    bool caso1, caso2, caso4, caso5;
    caso1 = false;
    caso2 = false;
    caso4 = false;
    caso5 = false;
    fr(1,n+1){
        if (i == n){
            x2 = hull[0].x;
            y2 = hull[0].y;
        } else {
            x2 = hull[i].x;
            y2 = hull[i].y;
        }
        // cout << "Pinto del punto (" << x1 << "," << y1 << ") al punto (" << x2 << "," << y2 <<  ")" << endl;
        if (x2 > x1){
            if (y2 > y1){
                caso1 = true;
                //pinto arriba hasta el costado izquierdo digamos
                res += 1;
                ll llegarX = x2-1;
                ll llegarY = y2-1;
                if (llegarX - x1 < llegarY - y1){ // me tengo que mover menos en x
                    res += llegarX - x1;
                    res += llegarY-y1 - (llegarX-x1);
                } else {
                    res += llegarY-y1;
                    res += llegarX-x1 - (llegarY-y1);
                }
                // cout << "caso 1. Res = " << res << endl;
            } else if (y2 < y1){ //aca arranco a descender
                caso2= true;
                // tengo que pintar el de arriba y al arriba del siguiente
                res += 1;
                // ll llegarY = y2+1;
                // ll inicioY = y1+1;
                if (x2 - x1 < y1-y2){
                    res += x2 - x1;
                    res += y1-y2 - (x2-x1);
                } else {
                    res += y1-y2;
                    res += x2-x1 - (y1-y2);
                }
                // cout << "caso 2. Res = " << res << endl;
            } else { //las y son iguales
                res += 1;
                res += x2-x1-1; //no le pinto arriba al x2 xq despues le pinto
                // cout << "caso 3. Res = " << res << endl;
            }
        } else if (x2 < x1){ //toy volviendo para atras
            if (y2<y1){ // estoy yendo hacia abajo
                //pinto el de abajo hasta al costado derecho
                caso4= true;
                res+=1;
                ll yInicial = y1-1;
                ll llegarX = x2+1;
                if (x1-llegarX < yInicial-y2){
                    res += x1-llegarX;
                    res += yInicial-y2 - (x1-llegarX);
                } else {
                    res += yInicial-y2;
                    res += x1-llegarX - (yInicial-y2);
                }
                // cout << "caso 4. Res = " << res << endl;
            } else if (y2 > y1) {// arranque a subir de vuelta 
                //tengo  que pintar el de abajo y el de abajo del siguiente
                caso5= true;
                res+=1;
                if (x1-x2 < y2 - y1){
                    res += x1-x2;
                    res += y2-y1 - (x1-x2);
                } else {
                    res += y2-y1;
                    res += x1-x2 - (y2-y1);
                }
                // cout << "caso 5. Res = " << res << endl;
            } else { // misma altura
                res += 1;
                res += x1-x2-1; //no le pinto arriba al x2 xq despues le pinto
                // cout << "caso 6. Res = " << res << endl;
            }
        } else { // estoy subiendo o bajando ni idea
            if (y2 > y1){ // estoy subiendo
                //no pinto el costado xq despues lo pinto;
                res += y2-y1-1;
                // cout << "caso 7. Res = " << res << endl;
            } else { //estoy bajando
                // if (!caso2){
                //     res+=1;
                // }
                res += y1-y2; //aca hay uno que pinto al final...
                // cout << "caso 8. Res = " << res << endl;
            }
        }

        x1 = x2;
        y1 = y2;
    }
    res+=1; //pinto el del costado derecho del de mas a la derecha
    res+=1; // pinto el del costado izquierdo
    // cout(res);
    if (caso1 == false){
        res+=1;
    }
    if (caso2 == false){
        res+=1;
    }
    if (caso4 == false){
        res+=1;
    }
    if (caso5 == false){
        res+=1;
    }
    if ((!caso1 || !caso2 || !caso4 || !caso5) && n >= 3){
        res-=1;
    }
    // cout(caso1);
    // cout(caso2);
    // cout(caso4);
    // cout(caso5);

    // cout << "Sumo el del costado a la derecha y el de la izquierda y res = " << res << endl;
    cout << res;
}