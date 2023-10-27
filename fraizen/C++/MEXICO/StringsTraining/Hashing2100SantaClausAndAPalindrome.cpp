//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)

//copiar luego 3
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;

//Copiar luego 4
typedef long double ld;
typedef double d;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;

//Copiar obligatoriamente 2
#define debug(x) cout << #x << ": "; _print(x); cout << "\n";
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = a; i<b; i++)

//copiar luego 4
#define ff first
#define ss second
#define fre(s) for(auto e:s)
#define MAXN 1000008

// Copiar luego 4
#define ppb pop_back
#define mod 1000000007
#define mod1 998244353
#define PI 3.141592653589793238462
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& pa) const {
        auto h1 = std::hash<T1>{}(pa.first);
        auto h2 = std::hash<T2>{}(pa.second);
        return h1 ^ h2;
    }
};

// Copiar obligatoriamente 0
void solve(ll k, ll n) {
    vi potencias(n);
    potencias[0] = 1;
    for (ll i = 1; i < n; i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }
    map<pair<ll,ll>, vi> m;
    string words[k];
    fr(0,k){
        string s; ll val;
        cin >> s >> val;
        words[i] = s;
        pair<vi, vi> hashes_pair = precompute_hashes(s);
        vi hashes1 = hashes_pair.first;
        vi hashes2 = hashes_pair.second;
        m[mp(hashes1[n],hashes2[n])].pb(val);
    }
    for (auto& i: m){
        sort(i.second.begin(), i.second.end());
    }

    map<pair<ll,ll>,bool> visited;
    set<pair<ll,ll>> pairs;
    ll res = 0;
    ll valuePairs = 0;
    ll maxAlone = 0;
    ll possibleScore = 0;

    fr(0,k){
        // cout << i << endl;
        string sRev = words[i];
        reverse(sRev.begin(), sRev.end());
        pair<vi, vi> hashes_pair = precompute_hashes(sRev);
        vi hashes1 = hashes_pair.first;
        vi hashes2 = hashes_pair.second;
        hashes_pair = precompute_hashes(words[i]);
        vi hashes1Original = hashes_pair.first;
        vi hashes2Original = hashes_pair.second;
        if (visited[mp(hashes1[n],hashes2[n])]){
            continue;
        }
        visited[mp(hashes1[n],hashes2[n])]=true;
        visited[mp(hashes1Original[n],hashes2Original[n])] = true;
        if (mp(hashes1[n],hashes2[n]) == mp(hashes1Original[n],hashes2Original[n])){
            // tenemos el caso de uno que ya es palindrome
            // cout << "Palindrome " << endl;
            ll size = m[mp(hashes1[n],hashes2[n])].size();
            vi values = m[mp(hashes1[n],hashes2[n])];
            while (size >= 2){
                if (values[size-1] >= 0 && values[size-2] >= 0){
                    // cout << "Sumo a res" << endl;
                    res += values[size-1] + values[size-2];
                    // cout << res << endl;
                    size -=2;
                } else {
                    break;
                }
            }
            if (size >= 2 && (values[size-1] + values[size-2] > 0)){
                valuePairs += values[size-1] + values[size-2];
                pairs.insert(mp(values[size-1],values[size-2]));
                res += values[size-1] + values[size-2];
                size -= 2;
                // fr(0, values.size()){
                //     cout << values[i] << ' ';
                // }
                // cout << endl;
                possibleScore = max(possibleScore, -values[size]);
            }

            if (size > 0){
                maxAlone = max(maxAlone, values[size-1]);
                possibleScore = max(possibleScore, maxAlone);
            }
        } else { //tenemos el caso de uno que no es palindrome, hay que buscar pareja
            ll size1 = m[mp(hashes1[n],hashes2[n])].size();
            vi values1 = m[mp(hashes1[n],hashes2[n])];
            ll size2 = m[mp(hashes1Original[n],hashes2Original[n])].size();
            vi values2 = m[mp(hashes1Original[n],hashes2Original[n])];

            while (size1 > 0 && size2 > 0 && ((values1[size1-1] + values2[size2-1]) > 0)){
                res += values1[size1-1] + values2[size2-1];
                size1-=1;
                size2-=1;
            }
        }
    }
    // cout << possibleScore << endl;
    cout << possibleScore + res << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        ll k,n;
        cin >> k >> n;
        solve(k,n);
    }

    return 0;
}