#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vp;
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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n;
    ll maxWeight;
    cin >> n >> maxWeight;
    vector<ll> people(n);
    fr(0,n) cin >> people[i];

    int limit = 1 << n;
    vp dp(limit);
    dp[0] = {1,0}; // un elevador con capacidad hasta el momento 0
    rep(mask,1,limit){
        pair<ll,ll> bestResult = {INT_MAX, INT_MAX};
        fr(0,n){ // tenemos que iterar y apagar un bit donde sea posible para ver el resultado
            if (((1 << i) & mask) == 0) continue; // Si el bit esta apagado, no tenemos que hacer nada.
            // ahora nos fijamos que da si apagamos uno de los bits que esta en uno.
            pair<ll,ll> res = dp[ (1 << i) ^ mask];
            if (res.second + people[i] <= maxWeight){
                res.second += people[i];
            } else {
                res.first += 1;
                res.second = people[i];
            }
            bestResult = min(bestResult, res);
        }
        dp[mask] = bestResult;
    }
    cout << dp[limit-1].first;
}