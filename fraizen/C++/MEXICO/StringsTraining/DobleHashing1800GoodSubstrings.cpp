#include <bits/stdc++.h>
using namespace std;
#define fr(a,b) for(int i = a; i<b; i++)
#define cout(x) cout << x << "\n";

typedef long long ll;
typedef vector<ll> vi;
#define pb push_back
#define mod 1000000007
#define p 3079
#define q 737

pair<vi, vi> precompute_hashes(const string& s){
    vi hashes1(s.size() + 1, 0), hashes2(s.size() + 1, 0);
    ll hash1 = 0, hash2 = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash1 = (hash1 * p + s[i]) % mod;
        hash2 = (hash2 * q + s[i]) % mod;
        hashes1[i+1] = hash1;
        hashes2[i+1] = hash2;
    }
    return {hashes1, hashes2};
}

pair<ll, ll> get_hash(const vi& hashes1, const vi& hashes2, ll l, ll r, const vi& potencias1, const vi& potencias2){
    ll hash1 = (((hashes1[r] - ((hashes1[l-1] * potencias1[r-l+1]) % mod) % mod)+ mod) % mod);
    ll hash2 = (((hashes2[r] - ((hashes2[l-1] * potencias2[r-l+1]) % mod) % mod)+ mod) % mod);
    return {hash1, hash2};
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pa) const {
        auto h1 = std::hash<T1>{}(pa.first);
        auto h2 = std::hash<T2>{}(pa.second);
        return h1 ^ h2;
    }
};

void solve(string text, string good, ll k) {
    pair<vi, vi> hashes_pair = precompute_hashes(text);
    vi hashes1 = hashes_pair.first;
    vi hashes2 = hashes_pair.second;

    int bad[text.size()+1];
    bad[0] = 0;
    fr(1,text.size()+1){
        if (good[text[i-1] - 'a'] == '0'){
            bad[i] = bad[i-1] + 1;
        } else {
            bad[i] = bad[i-1];
        }
    }

    vi potencias1(text.size()), potencias2(text.size());
    potencias1[0] = potencias2[0] = 1;
    for (ll i = 1; i < text.size(); i++) {
        potencias1[i] = (potencias1[i-1] * p) % mod;
        potencias2[i] = (potencias2[i-1] * q) % mod;
    }

    ll n = text.size();
    ll res = 0;
    fr(1,text.size()+1){// itero en el largo
        unordered_set<pair<ll,ll>, pair_hash> h;
        for(int j = 0; j <= n-i; j++){
            if ((bad[j+i] - bad[j]) <= k){
                h.insert(get_hash(hashes1, hashes2, j+1, j + i, potencias1, potencias2));
            }
        }
        res += h.size();
    }
    cout << res << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string t;
    string good;
    ll k;
    cin >> t >> good >> k;

    solve(t, good, k);
}