#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 5e6+2;

ll fac[MAXN], ifac[MAXN];

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>=1;
    }
    return res;
}

void init_fac(int n) {
    fac[0] = 1;
    for(int i =1; i <= n; ++i) fac[i] = fac[i-1] * i % MOD;
    ifac[n] = modpow(fac[n], MOD-2, MOD);
    for(int i = n; i > 0; --i) ifac[i-1] = ifac[i] * i % MOD;
}

ll comb(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

//llamar en el main a init_fac(MAXN);

void solve() {
    ll K, S, T; cin >> K >> S >> T;
    if(S < K) {
        cout << 0 << endl;
        return;
    }
    ll q = K / T;
    ll r = K % T;
    if(q == 0) {
        if(S < r) {
            cout << 0 << endl;
            return;
        }
        ll res = comb(S - 1, r - 1);
        cout << res << endl;
        return;
    }
    ll N = S - K;
    if(N < 0) {
        cout << 0 << endl;
        return;
    }
    ll res = 0;
    for(ll s1 = 0; s1 * (q + 1) <= N; ++s1) {
        if((N - (q + 1) * s1) % q != 0) continue;
        ll s2 = (N - (q + 1) * s1) / q;
        if(s2 < 0) continue;
        if(r > 0) {
            ll ways1 = comb(s1 + r - 1, r - 1);
            ll ways2 = comb(s2 + (T - r) - 1, T - r -1);
            res = (res + ways1 * ways2 % MOD) % MOD;
        } else {
            if(s1 != 0) continue;
            ll ways2 = comb(s2 + T - 1, T -1);
            res = (res + ways2) % MOD;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_fac(MAXN);
    solve();
    return 0;
}