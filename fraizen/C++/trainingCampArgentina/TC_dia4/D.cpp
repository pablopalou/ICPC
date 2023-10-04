#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
#include <math.h>
#include <cmath>
#include <set>
set<int> asc;
set<int> esc;
const ll INF = 1e18;

void solve(int a, int b, int c, int d, int v) {
    if (a == c){
        cout << abs(d-b) << '\n';
        return;
    }

    ll res = 0;
    ll ascRight, ascLeft, escLeft, escRight;
    escLeft = INF;
    escRight = INF;
    ascLeft = INF;
    ascRight = INF;

    // tenemos 4 opciones, hay que evaluarlas
    auto itAscLeft = asc.lower_bound(b);
    if (itAscLeft != asc.begin()) {
        --itAscLeft;
        ascLeft = *itAscLeft;
    } else {
        ascLeft = INF;
    }
    auto it = asc.lower_bound(b);
    if (it != asc.end()) {  
        ascRight = *it;
    } else {
        ascRight = INF;
    }

    auto itescLeft = esc.lower_bound(b);
    if (itescLeft != esc.begin()) {
        --itescLeft;
        escLeft = *itescLeft;
    } else {
        escLeft = INF;
    }
    auto itF = esc.lower_bound(b);
    if (itF != esc.end()) {
        escRight = *itF;
    } else {
        escRight = INF;
    }

    ll resEscLeft, resEscRight, resAscLeft, resAscRight;
    resEscLeft = INF;
    resEscRight = INF;
    resAscLeft = INF;
    resAscRight = INF;

    // opcion 1, tomar escalera de la izquierda
    if (escLeft != INF){
        resEscLeft = (b-escLeft) + (abs(c-a)) + abs(d-escLeft);
    }

    // opcion 2, tomar esclaera de la derecha
    if (escRight != INF){
        resEscRight = (escRight-b) + (abs(c-a)) + abs(d-escRight);
    }

    //opcion 3, tomar ascensor de la izquierda
    if (ascLeft != INF){
        resAscLeft = (b-ascLeft) + (abs(c-a) + v-1)/v + abs(d-ascLeft);
    }
    //opcion 4, tomar ascensor de la derecha
    if (ascRight != INF){
        resAscRight = (ascRight-b) + (abs(c-a) + v-1)/v + abs(d-ascRight);
    }

    cout << min(min(resEscLeft,resEscRight), min(resAscLeft, resAscRight)) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,cant1, cant2, v;
    cin >> n >> m >> cant1 >> cant2 >> v;

    fr(0,cant1){
        int x;
        cin >> x;
        esc.insert(x);
    }
    fr(0,cant2){
        int x;
        cin >> x;
        asc.insert(x);
    }
    int q;
    cin >> q;
    fr(0,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        solve(a,b,c,d,v);
    }
    
}
