#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
typedef vector<ll> vi;
#define mod 1000000007

#define MAXN 200200
#define p 256
int n;

vi hashFraizen;
vi potencias(MAXN);

vi precompute_hashes(const string&s){
    vi hashes(s.size()+1,0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++){
        hash = (hash*p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod) + mod) %mod);
}

int contarIguales(int hash, int mid, int inicio){
    int res = 0;
    int i = inicio;
    int iter = 0;
    while( i +mid+1 <= n){
        iter++;
        // cout << "here "<< endl;
        // if (iter ==1000 ){
        //     return 2;
        //}
        if (get_hash(hashFraizen, i+1, i+mid+1, potencias) == hash){
            res++;
            i += mid;
        } else {
            i++;
        }
    }
    return res;
    // for(int i =inicio; i<=n-mid; i++){
    // }
}

bool puedo(int mid, int k){
    //tengo los hashes, tengo que ver si hay al menos k que cumplan mid letras.
    int cur = 0;
    fr(0,n){
        if (i + mid + 1 > n){
            break;
        }
        if (contarIguales(get_hash(hashFraizen, i+1, i+mid+1, potencias), mid, i+mid) > k){
            return true;
        }
    }
    return false;
}

// Copiar obligatoriamente 0
void solve() {
    int left,right; cin >> n >> left >> right;
    int k = left;
    string s; cin >> s;
    //tengo que separarlo en k substrings contiguos.
    hashFraizen = precompute_hashes(s);
    potencias[0] = 1;
    for (ll i = 1; i < n; i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }

    int l,r;
    l = 0;
    r = n/k;
    int res = 0;

    while(l <= r){
        int mid = l + (r-l)/2;
        if (mid == 0){
            cout << mid << "\n"; return;
        }
        if (puedo(mid,k)){
            res = mid;
            l = mid+1;
        } else {
            r=mid-1;
        }
    }
    cout << res << '\n';
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