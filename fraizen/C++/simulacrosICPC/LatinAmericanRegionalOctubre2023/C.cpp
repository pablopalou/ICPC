// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define cout(x) cout << x << "\n";
// #define p 400001
// ll n;
// #define mod 1000000007

// // Copiar obligatoriamente 0
// void solve() {
//     cin >> n; ll k; cin >> k;
//     map<ll,ll> freq;     //frequencias
//     ll cant0 = k;     //contador de ceros
//     ll norm = 0; //variable de normalizacion
//     ll a[n];
//     fr(0,n){
//         cin >> a[i];
//     }
//     vector<ll> potencias(k+1); // Moved potencias array to local scope and made its size dynamic
//     potencias[0] = 1;
//     for (ll i = 1; i < k; i++) {
//         potencias[i] = ((potencias[i-1] % mod * p %mod) + mod)  % mod;
//         // cout << potencias[i] <<endl;
//     }
//     // cout << "potencias" << endl;
//     // for (ll i = 0; i < k; i++) {
//     //     cout << potencias[i] <<endl;
//     // } 
// // 1, 256, 256*2;
//     ll sumaPotencias = 0;
//     fr(0,k+1){ //fijarse el indice.
//         sumaPotencias = (sumaPotencias % mod +  potencias[i] % mod) % mod;
//     }
//     map<ll,ll> cantidades;
//     cantidades[0] = k;

//     map<ll, vector<ll>> m;
//     vector<ll> hashes(n + 1, 0);
//     ll hash = 1;
//     m[1].push_back(0);
//     bool algunaVez = false;
//     fr(0,n){
//         // cout << "I = " << i << endl;
//         bool deboNorm = false;
//         cantidades[freq[a[i]]]--;
//         cantidades[freq[a[i]]+1]++;
//         freq[a[i]]++;
//         if (freq[a[i]] == norm + 1){
//             cant0--;
//             if (cant0 == 0){
//                 algunaVez = true;
//                 // cout << "normalizo en i = " << i << endl;
//                 norm++;
//                 cant0 = cantidades[norm];
//                 deboNorm = true;
//             }
//         }
//         // cout << "potencias de a["<<i<<"]= " << potencias[a[i]-1] << endl;
//         hash = ((hash + potencias[a[i]-1]) + mod) % mod;
//         if (deboNorm){
//             // cout << "resto " << sumaPotencias<< endl;
//             hash = ((hash - sumaPotencias) % mod + mod) % mod;
//         }
//         hashes[i+1] = hash;
//         m[hash].push_back(i+1);
//     }
//     // fre(m){
//     //     cout << "m[" << e.first <<"] = ";
//     //     fr(0,e.second.size()){
//     //         cout << e.second[i] << ", ";
//     //     }
//     //     cout << endl;
//     // }
//     ll res = 0;
//     if (!algunaVez){
//         cout << "0\n";return;
//     }
//     fre(m){
//         ll size = e.second.size();
//         if (size > 1){
//             res = max(res, e.second[size-1] - e.second[0]);
//         }
//     }
//     cout << res << "\n";
// }

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     // cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define p 256
#define p2 7
ll n;
#define mod1 999727999
#define mod 1070777777
// #define modGrande 87178291199

struct HashPair {
    ll first, second;
    bool operator==(const HashPair& other) const {
        return first == other.first && second == other.second;
    }
    bool operator!=(const HashPair& other) const {
        return !(*this == other);
    }
    bool operator<(const HashPair& other) const {
        if (first != other.first) return first < other.first;
        return second < other.second;
    }
};

map<HashPair, vector<ll>> m;


// Copiar obligatoriamente 0
void solve() {
    cin >> n; ll k; cin >> k;
    map<ll,ll> freq;     //frequencias
    ll cant0 = k;     //contador de ceros
    ll norm = 0; //variable de normalizacion
    ll a[n];
    fr(0,n){
        cin >> a[i];
    }
    vector<ll> potencias(k+1,0); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < k; i++) {
        potencias[i] = ((potencias[i-1] % mod * (p %mod)) + mod)  % mod;
    }
    vector<ll> potencias2(k+1,0); // Moved potencias array to local scope and made its size dynamic
    potencias2[0] = 1;
    for (ll i = 1; i < k; i++) {
        potencias2[i] = ((potencias2[i-1] % mod1 * (p2 %mod1)) + mod1)  % mod1;
    }

    ll sumaPotencias = 0;
    fr(0,k+1){ //fijarse el indice.
        sumaPotencias = (sumaPotencias % mod +  potencias[i] % mod) % mod;
    }
    ll sumaPotencias2 = 0;
    fr(0,k+1){ //fijarse el indice.
        sumaPotencias2 = (sumaPotencias2 % mod1 +  potencias2[i] % mod1) % mod1;
    }
    map<ll,ll> cantidades;
    cantidades[0] = k;

    // map<ll, vector<ll>> m;
    // map<ll, vector<ll>> m2;
    vector<ll> hashes(n + 1, 0);
    ll hash = 1;
    vector<ll> hashes2(n + 1, 0);
    ll hash2 = 1;
    // m[hash * (1ll<<32) % mod + hash2].push_back(0);
    m[{1,1}].push_back(0);
    // cout << "vale " << endl;
    // cout << hash * (1ll<<32) % mod + hash2 << endl;
    bool algunaVez = false;
    fr(0,n){
        // cout << "I = " << i << endl;
        bool deboNorm = false;
        cantidades[freq[a[i]]]--;
        cantidades[freq[a[i]]+1]++;
        freq[a[i]]++;
        if (freq[a[i]] == norm + 1){
            cant0--;
            if (cant0 == 0){
                algunaVez = true;
                norm++;
                // cout << "Normalize en "<< i << endl;
                cant0 = cantidades[norm];
                deboNorm = true;
            }
        }
        hash = ((hash + potencias[a[i]-1]) + mod) % mod;
        if (deboNorm){
            hash = ((hash - sumaPotencias) % mod + mod) % mod;
        }
        hashes[i+1] = hash;
        hash2 = ((hash2 + potencias2[a[i]-1]) + mod1) % mod1;
        if (deboNorm){
            hash2 = ((hash2 - sumaPotencias2) % mod1 + mod1) % mod1;
        }
        HashPair currentHash = {hash, hash2};
        m[currentHash].push_back(i+1);
        hashes2[i+1] = hash2;
        // m[((hash * (1ll<<32))%modGrande + hash2) % modGrande].push_back(i+1);
    }
    // fre(m){
    //     cout << "m[" << e.first <<"] = ";
    //     fr(0,e.second.size()){
    //         cout << e.second[i] << ", ";
    //     }
    //     cout << endl;
    // }
    ll res = 0;
    if (!algunaVez){
        cout << "0\n";return;
    }
    fre(m){
        ll size = e.second.size();
        if (size > 1){
            res = max(res, e.second[size-1] - e.second[0]);
        }
    }
    cout << res << "\n";
    // ll otroRes = 0;
    // fre(m2){
    //     ll size = e.second.size();
    //     if (size > 1){
    //         otroRes = max(otroRes, e.second[size-1] - e.second[0]);
    //     }
    // }
    // cout << min(res, otroRes) << "\n";
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