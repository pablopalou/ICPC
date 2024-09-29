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

#define MAXN 1000100
int f[MAXN], nxt[MAXN]; //Array de frecuencias (cuantas veces tengo una flor con x polen). Array de este numero, paso el siguiente.

int sumDigits(int n){
    int res = 0;
    while(n){
        res += n%10;
        n/=10;
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    memset(f, 0,sizeof(f));
    memset(nxt, 0, sizeof(nxt));
    fr(0,n){
        int num; cin >> num;
        f[num]++;
    }
    fr(0,MAXN-10){
        nxt[i] = i - sumDigits(i);
    }
    //ahora veo desde MAXN hasta 0. 
    for(int i = MAXN-10; i >= 0; i--){
        k -= f[i]; // tengo f[i] con i de polen, entonces puedo como que ir a cada una de esas flores. 
        //las flores ahora se actualizan y quedan con menos polen (en particular, quedan con nxt[i] polen)
        f[nxt[i]]+=f[i];
        if (k <= 0){
            //la reina saco el polen en esta iteracion, entonces retornamos
            cout << i - nxt[i] << '\n'; return;
        }
    }
    cout << 0 << '\n';
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