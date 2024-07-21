#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll msbit(ll k){
    if (k == 0) return 0;
    ll res = 0;
    k/=2;
    while(k){
        k/=2; res++;
    }
    return (1 << res);
}

ll sig(ll num){
    if ((num & (num-1)) == 0){
        return num << 1;
    } else {
        int i =1;
        while(i < num){
            i*=2;
        }
        return i;
    }
}

void solve() {
    int n,k; cin >> n >> k;
    vector<ll> v;
    ll msb = msbit(k);
    // cout << "Msb es " << msb << endl;
    fr(0,20){
        v.pb((1<<i));
    }
    fr(0,v.size()){
        if (v[i] == msb){
            v[i] = k - (msb-1) -1;
            // cout << "cambio msb por " << v[i] << endl;
            break;
        }
    }
    v.pb(k+msb);
    if (msb+1 > k){
        v.pb(msb+1);
        // cout << "here" << endl;
    }
    //  else {
        // cout << "heeeeeere "  << endl;
    v.pb(sig(msb)+1);
    // }
    v.pb(k+1);
    cout << v.size() << "\n";
    fre(v){
        cout << e << " ";
    }
    cout << '\n';
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