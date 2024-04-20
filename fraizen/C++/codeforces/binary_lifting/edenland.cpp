#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll const MAXN = 200005;
ll n, q;
ll a[MAXN];
ll b[MAXN];
ll const MAXH = 21;
ll nxt[MAXH][MAXN];
ll pa[MAXN], pb[MAXN], dif[MAXN];

#define mp make_pair
void precompute(){
    pa[0] = 0; pb[0] = 0;
    fr(0,n){
        pa[i+1] = pa[i] + a[i];
        pb[i+1] = pb[i] + b[i];
    }
    fr(1,n+1){
        dif[i-1] = pa[i] - pb[i-1];
    }
    // fr(0,n+1){
    //     cout << pa[i] << " ";
    // }
    // cout << "\n";
    // fr(0,n+1){
    //     cout << pb[i] << " ";
    // }
    // cout << endl;
    // cout << "dif " << endl;
    // fr(0,n){
    //     cout << dif[i] << ' ';
    // }
    // cout << endl;
    //
    stack<pair<ll, ll> > s;
    s.push(mp(dif[0], 0));
    ll i = 1;
    while(i < n){
        // cout << "Estoy en i = " << i << endl;
        while(!s.empty() && s.top().first < dif[i]){
            int index = s.top().second;
            s.pop();
            // cout << "saco de la pila" << endl;
            nxt[0][index] = i;
            // cout << nxt[0][index] << i << endl;
        }
        s.push(mp(dif[i], i));
        // cout << "agrego el i a la pila" << endl;
        i++;
    }
    while(!s.empty()){
        int index = s.top().second;
        s.pop();
        nxt[0][index] = n;
    }
    nxt[0][n-1] = n;
    //n+1
    // cout << endl;
    // cout << "NEXT " << endl;
    // fr(0,n){
    //     cout << nxt[0][i] << ' ';
    // }
    // cout << endl;
        
    
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    fr(0,n){
        cin >> b[i];
    }
    cin >> q;
    precompute();
    //calcular lo que falta de next
    rep(h, 0 , MAXH){
        nxt[h][n] = n; 
    } // no se porque razon necesito esto...
    rep(h, 1, MAXH){
        rep(i, 0, n+1){
            nxt[h][i] = nxt[h-1][nxt[h-1][i]];
            // nxt[1][6] = nxt[0][15]
            // if (nxt[h][i] == 0){
            //     cout << "H = " << h << " I = " << i << endl;
            // }
            if ((1<<h) + i >= n ){
                nxt[h][i] = n;
            }
            // cout << nxt[h][i] << " ";

        }
        // cout << endl;
    }

    // cout << "q" << q << endl;

    fr(0,q){
        int l,r; cin >> l >> r;
        if (l == r){
            cout << b[r-1] << endl;
            continue;
        }
        int fraizen = l;
        l--;
        //tengo que hacer next[l] desde 20 pa abajo digamos;
        int pos;
        for(int k = MAXH-2; k >= 0; k--){
            pos = nxt[k][l] + 1;
            // cout << "nxt["<< k << "][" <<l << "] = " << nxt[k][l] << endl;
            // cout << "new pos = " << pos << endl;
            // if (n != r){
            if (pos <= r){
                // if ( pos == 1){
                //     cout << "Pos = 1 cuando k = " << k << " y l = " << l << endl; 
                //     cout << nxt[k][l] << endl;
                // }
                l = max(pos, l);
                // cout << "pos = " << pos << endl;
                // cout << "Actualizo l = " << l << endl;
            }
            // } else {
            //     if (pos < r){
            //         l = max(pos, l);
            //     }
            // }
        }
        if (l == fraizen -1){
            l++;
        }
        
        // cout << "caso " << i << endl;
        // cout << "r = " << r << " l = " << l << endl;
        // cout <<  pb[r] - pb[l-1] << endl;
        // cout << (pa[r] - pa[l]) << endl;
        cout << pb[r] - pb[l-1] - (pa[r] - pa[l]) << endl;
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