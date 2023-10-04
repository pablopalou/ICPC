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
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

struct P {
    int x,y;
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
};

void solve() {
    P p1,p2,p3,p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    if ((p2-p1) * (p4-p3) == 0) {// son paralelos
        if ((p2-p1) * (p3-p1) != 0){//veo si estan en distintas lineas digamos
            cout("NO");
            return;
        }
        // si llego aca es xq estan en la misma linea, hay que chequear si se overlappean.
        // para eso se hace la tecnica de los boxes
        if (max(p1.x,p2.x) < min(p3.x, p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
            cout("NO");
            return;
        }
        swap(p1,p3);
        swap(p2,p4);
        // cambio por si el segmento estaba arriba...
        if (max(p1.x,p2.x) < min(p3.x, p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
            cout("NO");
            return;
        }
        cout("YES");
        return;
    }
    // caso general, se podrian cruzar en un punto P si hacemos las rectas.
    // me fijo si P esta incluido en A y si P esta incluido en B
    // Si esta incluido en ambos devuelvo YES, sino NO
    // me tengo que fijar que los dos puntos del segmento esten de distinto lado
    // para que P este en el segmento.
    ll sign1 = (p2-p1) * (p3-p1);
    ll sign2 = (p2-p1) * (p4-p1);
    if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)){
        cout("NO");
        return;
    }
    sign1 = (p4-p3) * (p2-p3);
    sign2 = (p4-p3) * (p1-p3);
    if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)){
        cout("NO");
        return;
    }
    cout("YES");
    return;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
}