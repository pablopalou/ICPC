#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b;i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define vi vector<ll>
#define p 256
#define mod 1000000007

vi precompute_hashes(const string & s){
    vi hashes(s.size()+1,0);
    ll hash = 0;
    for (ll i =0; i < s.size(); i++){
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod) + mod) % mod);
}

//escribir con el otro hash (fijarse si quedo bien)
ll lcp(const string& s, const string& s2, ll i, ll j, const vi& hashes, const vi& hashes2, vi& potencias){
    ll lo = 0;
    ll hi = min(s.size(), s2.size());
    while(lo < hi){
        ll mid = (lo + hi + 1) / 2;
        if (get_hash(hashes, i+1, i+mid, potencias) == get_hash(hashes2, j+1, j+mid, potencias)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve() {
    string s; cin >> s;
    vi hashes = precompute_hashes(s);
    vi potencias(200002);
    potencias[0] = 1;
    for (ll i =1; i < 200002; i++){
        potencias[i] = (potencias[i-1] * p) % mod;
    }
    map<char, vector<ll>> m;

    fr(0, s.size()){
        m[s[i]].push_back(i);
    }
    // cout(s);
    //     IMPRIMO MAPA Y DA BIEN
    // for(auto it = m.rbegin(); it!=m.rend(); ++it){
    //     cout << it->first;
    //     fr(0,it->second.size()){
    //         cout << it->second[i] << ' ';
    //     }
    //     cout << "\n";
    // }

    ll n; cin >> n;
    rep(h,0,n){
        // cout(h);
        bool imposible = false;
        ll res = 0;
        string s2; cin >> s2;
        ll largo2 = s2.size();
        vi hashes2 = precompute_hashes(s2);
        ll i = 0; ll j = 0;
        while (true){
            // el i lo saco del mapa de posiciones
            ll maxLargo = 0;
            ll maxFraizen = 0;
            rep(z, 0, m[s2[j]].size()){
                i = m[s2[j]][z];
                ll sumar = lcp(s,s2,i,j,hashes, hashes2, potencias);
                maxFraizen = max(maxFraizen, sumar);
            }
            if (maxFraizen == 0){
                imposible = true;
                break;
            }
            j += maxFraizen;
            res += 1;
            if (j >= largo2){
                break;
            }
        }
        if (imposible){
            cout(-1);
            continue;
        }
        cout(res);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //BORRAR
    // freopen("G.in", "r", stdin);
    // freopen("G.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}