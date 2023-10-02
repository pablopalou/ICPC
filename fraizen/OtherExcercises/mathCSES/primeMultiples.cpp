#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

ll sumar(int mask, int k, vector<ll>& primes, ll n){
    ll prod = 1;
    fr(0,k){
        if ((1 << i) & mask){
            if (prod > n / primes[i]) {
                // Overflow detected, break out of the loop
                return 0;
            }
            prod *= primes[i];
        }
    }
    return __builtin_popcount(mask) & 1 ? n/prod : -n/prod;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    fr(0,k){
        cin >> primes[i]; 
    }
    ll ans = 0;
    rep(mask, 1, 1<<k){
        // cout("Sumo:");
        // cout(sumar(mask, k, primes, n));
        ans += sumar(mask, k, primes, n);
    }
    cout(ans);
}