#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

ll n, t; 
const int MAXN = 2005;

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> t;
    vector<pair<ll,ll> > a(n);
    fr(0,n){
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    for(auto &i:a){
        swap(i.first, i.second);
    }
    ll res = 0;
    fr(0,n){
        priority_queue<ll> pq;
        ll cur = 0;
        rep(j,i,n){
            ll difB = a[j].second - a[i].second;
            if (difB> t) break;
            pq.push(a[j].first);
            cur += a[j].first;
            while(cur + difB > t){
                ll f = pq.top(); pq.pop();
                cur -= f;
            }
            res = max(res, (ll)pq.size());
        }
    }
    cout << res << "\n";

    // sort(a.begin(), a.end());
    // ll res = 0;
    // for(auto &i:a){swap(i.first, i.second);}
    // fr(0,n){ //fijo que el rango empiece en i
    //     priority_queue<ll> pq;
    //     ll s = 0;
    //     rep(j, i, n){ //esto seria que el rango llegue hasta j
    //         if (a[j].second - a[i].second > t) break; //el rango obviamente tiene que ser menor o igual a time
    //         s+=a[j].first; //sumo el elemento que toy parado
    //         pq.push(a[j].first); //meto en la cola
    //         while(s+a[j].second-a[i].second > t){ // si me pase, tengo que sacar el mas pesado
    //             auto f = pq.top();pq.pop();
    //             s-=f;
    //         }
    //         res = max(res, (ll) pq.size()); //actualizo el maximo segun la cantidad que haya en la pq
    //     }
    // }
    // cout << res << "\n";
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