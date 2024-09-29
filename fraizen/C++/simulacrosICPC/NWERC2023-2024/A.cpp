#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
ll n;
ll espacio;
ll a[200020];

bool puedo(ll cant){
    map<ll, vector<ll>> m;
    fr(0,cant){
        // cout << "agrego i = " << i << endl;
        m[a[i] % 3].pb(i);
    }
    // fre(m){
    //     fr(0,e.second.size()){
    //         cout << e.second[i] << " ";
    //     }
    //     cout << endl;
    // }
    fre(m[0]){
        // cout << "e " << e << endl;
        espacio -= a[e];
        // cout << "resto " << a[e] << endl;
    }
    // cout << "espacio = " <<espacio << endl;
    ll mini = min(m[1].size(), m[2].size());
    fr(0,mini){
        espacio -= a[m[1][i]] + a[m[2][i]];
        // cout << "aca si" << endl;
    }
    //los que me sobran los tengo que poner pero ocupan mas espacio y chau. (si es mod 1 y mod 1 los puedo poner apuntandose)
    fr(mini, m[2].size()){
        espacio -= a[m[2][i]] + 1; //le sumo uno por el que desperdicio
    }
    // cout << "espacio = " << espacio << endl;
    // cout << "mini " << mini << endl;
    // // cout << "i = " << i << endl;
    // cout << "m[1].size() = " <<  m[1].size() << endl;
    // cout << "m[1].size() - 1 = " << int(m[1].size() -1) << endl;
    // cout << (mini < int(m[1].size()-1) )<< endl;
    //ahora me sobran los de 1, que puedo ir juntando de a pares...
    ll gasto = 0;
    int j = 0;
    fr(mini, int(m[1].size())){
        j++;
        gasto += a[m[1][i]];
        if (j % 2 == 0){
            gasto++;
        }
    }
    if (j & 1){
        gasto+=2;
    }
    // cout << "gasto " << gasto << endl;
    espacio -= gasto;
    // for (int i = mini; i < int(m[1].size()-1); i+=2){
    //     //puedo poner dos, entonces pongo
    //     espacio -= a[m[1][i]] + a[m[1][i+1]] + 1;
    //     // cout << "espacio = " << espacio << endl;
    // }
    // cout << "espacio = " << espacio << endl;
    // if ( (int(m[1].size()) > mini) && ((int(m[1].size()) - mini) % 2 == 0)){
    //     espacio -= a[m[1][m[1].size()-1]] + 2;
    // }
    // cout << "espacio = " << espacio << endl;
    return espacio >= 0;
}

void solve() {
    ll n,s; cin >> n >> s;
    fr(0,n) cin >> a[i];
    sort(a, a+n);
    // fr(0,n){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    if (s == 1 || n == 1){
        cout << 1 << '\n'; return;
    }
    ll res = 0; // los dos mas grandes van seguro.
    ll l = 0;
    ll r = n-2;
    // int iter = 0;
    while(l <= r){
        // iter++;
        // if (iter == 30) break;
        ll mid = l + (r-l)/2;
        espacio = (s-2) * 3;
        // cout << "Pruebo con mid = " << mid << endl;
        if (puedo(mid)){ //puedo meter mid 
            // cout << "Pude " << endl;
            res = mid;
            l = mid+1;
        } else {
            // cout << "no pude " << endl;
            r = mid-1;
        }
    }
    cout << res + 2 << '\n';
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