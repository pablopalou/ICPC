//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)

//Copiar obligatoriamente 2
#define debug(x) cout << #x << ": "; _print(x); cout << "\n";
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = a; i<b; i++)

//copiar luego 4
#define fre(s) for(auto e:s)
#define MAXN 1000008

// Copiar luego 4
#define ppb pop_back
#define mod 1000000007

#define p 256
int n;
int hashesPro[5001][5001];

//HASH DE PREFIJOS Y SUFIJOS (REVERSE HASH)

vector<ll> precompute_hashes(const string& s){
    vector<ll> hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

vector<ll> precompute_reverse_hashes(const string& s){
    vector<ll> reverse_hashes(s.size() + 1, 0);
    ll reverse_hash = 0;
    for (ll i = s.size() - 1; i >= 0; i--) {
        reverse_hash = (reverse_hash * p + s[i]) % mod;
        reverse_hashes[s.size() - i] = reverse_hash;
    }
    return reverse_hashes;
}

ll get_hash(const vector<ll>& hashes, ll l, ll r, const vector<ll>& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

bool isPalindrome(const vector<ll>& hashes,const vector<ll>& reverse_hashes,ll i,ll j, const vector<ll>& potencias){
    ll pre = get_hash(hashes, i+1, j+1, potencias);
    ll suf = get_hash(reverse_hashes, n - j, n -i, potencias);
    return pre == suf;
}

// void populate_hashes(const vector<ll>& hashes, const vector<ll>& potencias){
//     fr(0,n){
//         rep(j,0,n){
//             hashesPro[i][j] = get_hash(hashes, i+1, j+1, potencias);
//         }
//     }
// }
// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    n = s.size();
    vector<ll> hashes = precompute_hashes(s);
    vector<ll> reverse_hashes = precompute_reverse_hashes(s);

    vector<ll> potencias(s.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < s.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }

    // populate_hashes();

    vector<int> kPal;
    fr(0,s.size()){
        rep(j,i,s.size()){
            if (isPalindrome(hashes, reverse_hashes, i,j, potencias)){
                kPal.pb(i*5000+j);
            }
        }
    }
    sort(kPal.begin(), kPal.end());
    cout << kPal.size() << ' ';
    vector<int> newkPal;
    int endIter = min(15, (int)s.size());
    fr(1,endIter){
        fre(kPal){
            int fraizenJ = e % 5000;
            int fraizenI = e / 5000;
            ll largo = fraizenJ - fraizenI + 1;
            if (fraizenI - largo >= 0){
                if (fraizenI - largo - 1 >= 0){
                    int target = (fraizenI - largo - 1)*5000+fraizenI -2;
                    auto it = lower_bound(kPal.begin(), kPal.end(), target);
                    if (it != kPal.end() && *it == target && get_hash(hashes, fraizenI - largo - 1 +1, fraizenI -2 +1, potencias) == get_hash(hashes, fraizenI+1, fraizenJ+1, potencias)){
                        int newElement = (fraizenI - largo - 1)*5000+fraizenJ;
                        auto newIt = lower_bound(newkPal.begin(), newkPal.end(), newElement);
                        if (newIt == newkPal.end() || *newIt != newElement) {
                            newkPal.insert(newIt, newElement);
                        }
                    }
                }
                int target = (fraizenI - largo)*5000+fraizenI -1;
                auto it = lower_bound(kPal.begin(), kPal.end(), target);
                if (it != kPal.end() && *it == target && get_hash(hashes, fraizenI - largo +1, fraizenI, potencias) == get_hash(hashes, fraizenI+1, fraizenJ+1, potencias)){
                    int newElement = (fraizenI - largo)*5000+fraizenJ;
                    auto newIt = lower_bound(newkPal.begin(), newkPal.end(), newElement);
                    if (newIt == newkPal.end() || *newIt != newElement) {
                        newkPal.insert(newIt, newElement);
                    }
                }
            }
            // if (fraizenJ + largo <= n-1){
            //     if (fraizenJ + largo + 1 <= n-1){
            //         int target = (fraizenJ +2)*5000+fraizenJ + largo + 1;
            //         auto it = lower_bound(kPal.begin(), kPal.end(), target);
            //         if (it != kPal.end() && *it == target && get_hash(hashes, fraizenJ +3, fraizenJ + largo + 2, potencias) == get_hash(hashes, fraizenI+1, fraizenJ+1, potencias)){
            //             int newElement = fraizenI * 5000 + fraizenJ + largo + 1;
            //             auto newIt = lower_bound(newkPal.begin(), newkPal.end(), newElement);
            //             if (newIt == newkPal.end() || *newIt != newElement) {
            //                 newkPal.insert(newIt, newElement);
            //             }
            //         }
            //     }
            //     int target = (fraizenJ +1)*5000+fraizenJ + largo;
            //     auto it = lower_bound(kPal.begin(), kPal.end(), target);
            //     if (it != kPal.end() && *it == target && get_hash(hashes, fraizenJ +2, fraizenJ + largo + 1, potencias) == get_hash(hashes, fraizenI+1, fraizenJ+1, potencias)){
            //         int newElement = fraizenI *5000 +fraizenJ + largo;
            //         auto newIt = lower_bound(newkPal.begin(), newkPal.end(), newElement);
            //         if (newIt == newkPal.end() || *newIt != newElement) {
            //             newkPal.insert(newIt, newElement);
            //         }
            //     }
            // }
        }
        cout << newkPal.size() << ' ';
        kPal = newkPal;
        newkPal.clear();
        sort(kPal.begin(), kPal.end());
    }

    fr(15, s.size()){
        cout << 0 << ' ';
    }
}

// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // BORRAR
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}