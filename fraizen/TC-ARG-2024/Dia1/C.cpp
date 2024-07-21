#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll count(vector<ll> boxes, vector<ll> special){
    sort(boxes.begin(), boxes.end());
    sort(special.begin(), special.end());

    //cuento las cajas que ya estan bien
    deque<ll> good;
    fr(0, special.size()){
        auto it = lower_bound(boxes.begin(), boxes.end(), special[i]);
        if (it != boxes.end() && *it == special[i]){
            good.pb(special[i]);
        }
    }
    ll res = good.size();

    fr(0,special.size()){
        //cuento las cajas que estoy empujando
        ll boxesAnt = lower_bound(boxes.begin(), boxes.end(), special[i]) - boxes.begin();
        //cuento las cajas buenas hasta ahora (o sea me fijo si las special positions estan con estas cajas que vengo empujando)
        auto itR = lower_bound(special.begin(), special.end(), special[i]); //consigo el iterador de ahora
        auto itL = lower_bound(special.begin(), special.end(), special[i] - boxesAnt + 1);//consigo el iterador de la izquierda
        ll ahora = itR - itL + 1;
        //si la que estoy ahora es buena, la saco
        auto it = lower_bound(boxes.begin(), boxes.end(), special[i]);
        if (it != boxes.end() && *it == special[i]){
            good.pop_front();
        }
        //me quedo con el maximo
        res = max(res, ahora + ll(good.size()));
    }
    return res;
}

void solve() {
    ll n,m; cin >> n >> m;
    ll a[n];
    ll b[m];
    fr(0,n) cin >> a[i];
    fr(0,m) cin >> b[i];
    vector<ll> negA, negB, posA, posB;
    ll i = 0;
    fr(0,n){
        if (a[i] < 0){
            negA.pb(-a[i]);
        } else {
            posA.pb(a[i]);
        }
    }
    fr(0,m){
        if (b[i] < 0){
            negB.pb(-b[i]);
        } else {
            posB.pb(b[i]);
        }
    }
    cout << count(negA, negB) + count(posA, posB) << '\n';
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