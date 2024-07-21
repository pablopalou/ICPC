#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)

    //si para cada uno veo en log n, despues es solo ver si el otro llega. (casos de todo izquierda o todo derecha se pueden ver por separado.)
    // entonces, Veo como partir el arreglo A. 
    //hago los casos borde primero ;
    //uso la izquierda para el A. 
    //en vez de eso de lower_bound para A en cualquier posicion, me fijo los bordes directamente para A, B y C. es mas facil creo.
    //le doy hasta pos-1 inclusive a A.


void solve() {
    ll n; cin >> n;
    ll a[n];
    ll b[n], c[n];
    ll tot = 0;
    ll pa[n+1],pb[n+1], pc[n+1];
    ll sa[n+1],sb[n+1], sc[n+1];
    pa[0] = 0;
    pb[0] = 0;
    pc[0] = 0;
    sa[n] = 0;
    sb[n] = 0;
    sc[n] = 0;
    fr(0,n){
        cin >> a[i];
        tot += a[i];
        pa[i+1] = pa[i] + a[i];
    }
    fr(0,n){
        cin >> b[i];
        pb[i+1] = pb[i] + b[i];
    }
    fr(0,n){
        cin >> c[i];
        pc[i+1] = pc[i] + c[i];
    }
    for(int i = n-1; i>=0; i--){
        sa[i] = sa[i+1] + a[i];
    }
    for(int i = n-1; i>=0; i--){
        sb[i] = sb[i+1] + b[i];
    }
    for(int i = n-1; i>=0; i--){
        sc[i] = sc[i+1] + c[i];
    }
    ll dar = tot/3;
    if (tot% 3 != 0){
        dar+=1;
    }
    sort(sa, sa+n+1);
    sort(sb, sb+n+1);
    sort(sc, sc+n+1);

    //pruebo A C B
    auto pos1 = lower_bound(pa, pa+n+1, dar) - pa;
    
    auto pos2 = lower_bound(sb, sb+n+1, dar) - sb;
    auto suma = pc[n-(pos2)] - pc[pos1];
    if (suma >= dar){
        // cout << "CASO 1 " << endl;
        cout << "1 " << pos1 << " ";
        cout << n-pos2+1 << " " << n << " ";
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << '\n';
        return;
    }

    // A B C
    pos2 = lower_bound(sc, sc+n+1, dar) - sc;
    suma = pb[n-(pos2)] - pb[pos1];
    if (suma >= dar){
        // cout << "CASO 2 " << endl;
        cout << "1 " << pos1 << " ";
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << n-pos2+1 << " " << n << " ";
        cout << '\n';
        return;
        // cout << "1 " << pos1 << " " <<  pos1+1 << " " << n-pos2 << " " << n-pos2+1 << " " << n << "\n"; return; 
    }

    // PRUEBO B C A
    pos1 = lower_bound(pb, pb+n+1, dar) - pb;
    
    pos2 = lower_bound(sa, sa+n+1, dar) - sa;
    suma = pc[n-(pos2)] - pc[pos1];
    if (suma >= dar){
        // cout << "CASO 3 " << endl;
        cout << n-pos2+1 << " " << n << " ";
        cout << "1 " << pos1 << " ";
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << '\n';
        return;
    }

    // B A C
    pos2 = lower_bound(sc, sc+n+1, dar) - sc;
    suma = pa[n-(pos2)] - pa[pos1];
    if (suma >= dar){
        // cout << "CASO 4 " << endl;
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << "1 " << pos1 << " ";
        cout << n-pos2+1 << " " << n << " ";
        cout << '\n';
        return;
    }

    // pruebo C B A
    pos1 = lower_bound(pc, pc+n+1, dar) - pc;
    
    pos2 = lower_bound(sa, sa+n+1, dar) - sa;
    suma = pb[n-(pos2)] - pb[pos1];
    if (suma >= dar){
        // cout << "CASO 5 " << endl;
        cout << n-pos2+1 << " " << n << " ";
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << "1 " << pos1 << " ";
        cout << '\n';
        return;
    }

    // C A B
    pos2 = lower_bound(sb, sb+n+1, dar) - sb;
    suma = pa[n-(pos2)] - pa[pos1];
    if (suma >= dar){
        // cout << "CASO 6 " << endl;
        cout << pos1+1 << " " << n-pos2 << " ";
        cout << n-pos2+1 << " " << n << " ";
        cout << "1 " << pos1 << " ";
        cout << '\n';
        return;
    }

    cout << "-1\n";
    
    //pruebo B al final 
    //ahora veo si B puede ir al final
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