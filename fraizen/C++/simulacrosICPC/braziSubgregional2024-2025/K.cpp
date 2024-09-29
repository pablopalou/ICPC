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

void solve() {
    ll n; cin >> n; ll a[n]; fr(0,n) cin >> a[i];
    ll suma = 0;
    fr(0,n) suma+=a[i]; if (suma % 2 == 1) { cout << "-1\n"; return;}
    ll mitad = suma/2;
    //tengo que ver una forma de sumar mitad. 
    bool dp[105][102*102];
    fr(0,105){
        rep(j,0,102*102){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    fr(1,n+1){
        rep(j,0,suma+1){
            dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]];
        }
    }
    if (!dp[n][mitad]){
        cout << "-1\n"; return;
    }
    // es posible, tengo que ir para arriba en la dp para conseguir mis numeros y los del otro
    map<ll,ll> mios;
    ll cur = mitad;
    for(ll i = n; i > 0; i--){
        if (dp[i-1][cur]){
            //no pongo nada
        } else {
            //pongo el a[i-1]
            mios[a[i-1]]++;
            cur-=a[i-1];
        }
    }
    vector<ll> yo;
    fre(mios){
        fr(0,e.second){
            yo.pb(e.first);
        }
    }
    //tengo los mios en el vector YO
    map<ll,ll> m;
    fr(0,n){
        m[a[i]]++;
    }
    map<ll,ll> tuyo;
    fre(m){
        if (e.second > mios[e.first]){
            tuyo[e.first] = e.second - mios[e.first];
        }
    }
    vector<ll> el;
    fre(tuyo){
        fr(0,e.second){
            el.pb(e.first);
        }
    }
    //se supone que tenog los mios y los de el
    // cout <<" YO " << endl;
    // fre(yo){
    //     cout << e << ' ';
    // }
    // cout << "\n EL " << endl;
    // fre(el){
    //     cout << e << ' ';
    // }
    sort(yo.begin(), yo.end());
    sort(el.begin(), el.end());
    ll curYo = 0;
    ll curEl = 0;
    ll iter1 = 0;
    ll iter2 = 0;
    fr(0,n){
        //saco pal que tiene menos
        if (curYo <= curEl){
            cout << yo[iter1] << " ";
            curYo+=yo[iter1];
            iter1++;
        } else {
            cout << el[iter2] << " ";
            curEl+=el[iter2];
            iter2++;
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