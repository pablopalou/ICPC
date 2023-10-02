#include <bits/stdc++.h>
using namespace std;

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
#define MAXN 1000002
ll factorials[MAXN];

int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void precompute() {
    factorials[0] = factorials[1] = 1;
    fr(2,MAXN){
        factorials[i] = (factorials[i-1] * i) % mod;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();
    string s;
    cin >> s;
    map<char, int> m;
    for (char c: s){
        m[c]++;
    }
    ll denominador = 1;
    for (const auto& e : m){
        denominador = (denominador * factorials[e.second]) % mod;
    }
    cout((factorials[s.length()] * inv(denominador)) % mod);
}