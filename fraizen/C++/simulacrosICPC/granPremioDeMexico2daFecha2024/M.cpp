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
#define PI 3.141592653589793238462
typedef long double ld;
ld l,r;
ld j;

ld medir(ld h){
    j = sqrt(l*l-h*h);
    ld R = r + j;
    return PI * h * (1.0/3) * (R * R + r * r + R * r);
}

void solve() {
    cin >> l >> r;
    ld minimo = 0; //esto seria la altura digamos
    ld maximo = l;
    int iter = 0;
    while(iter < 200){
        iter++;
        ld m1 = minimo + (maximo - minimo)/3;
        ld m2 = minimo + (maximo - minimo)/3.0*2;
        if (medir(m1) < medir(m2)){
            minimo = m1;
        } else {
            maximo = m2;
        }
    }
    //ahora tengo la altura, con esto puedo hallar el angulo.
    cout << fixed << setprecision(12) << (PI/2.0 + acos(minimo/l)) << '\n';
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