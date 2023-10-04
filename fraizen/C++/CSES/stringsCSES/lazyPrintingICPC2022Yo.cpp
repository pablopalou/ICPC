#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define pb push_back
#define mod 1000000007
#define p 256

vi precompute_hashes(const string& s){
    vi hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

ll lcp(const string& s, ll i, ll j, const vi& hashes, vi& potencias) {
    ll lo = 0, hi = min(s.size() - i, s.size() - j);
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (get_hash(hashes, i + 1, i + mid, potencias) == get_hash(hashes, j + 1, j + mid, potencias) ) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve(string text, ll d) {
    vi hashes = precompute_hashes(text);
    
    vi potencias(text.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < text.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }

    ll res = 0; 
    ll i = 0;
    while (i < text.size()){
        ll max_len = 0;
        for (ll k = 1; k <= d; k++) {
            ll len = k + lcp(text, i, i+k, hashes, potencias);
            max_len = max(max_len, len);
        }
        i += max_len;
        res++;
    }
    cout << res << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string t;
    ll d;
    cin >> t >> d;
    
    solve(t, d);
}