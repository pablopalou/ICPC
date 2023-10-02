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
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define cout(x) cout << x << "\n";
#define fr(a,b) for(ll i = a; i<b; i++)
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
map<char, ll> cant;
char CARTAS[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
ll cant_cartas = 13;
ll dp[102][27];

void solve(ll n, vector<char> cartas) {
    fr(0, n) {
        cant[cartas[i]] += 1;
    }
    // Cuento pares
    ll pares = 0;
    fre(CARTAS) {
        pares += (cant[e]*(cant[e]-1))/2;
    }

    ll runs = 0;
    ll largo = 0;
    ll runs_local = 1;
    fre(CARTAS) {
        if (cant[e] > 0) {
            largo += 1;
            runs_local *= cant[e];
        } else {
            if (largo >= 3){
                runs += runs_local * largo;
            }
            largo = 0;
            runs_local = 1;
        }
    }
    if (largo > 2){
        runs += runs_local * largo;
    }

    vector<ll> cartasValor;
    cartasValor.pb(0);
    fre(cartas){
        if (e == 'A'){
            cartasValor.pb(1);
        } else if (e == 'T' || e == 'J' || e == 'K' || e == 'Q'){
            cartasValor.pb(10);
        } else {
            cartasValor.pb(e-'0');
        }
    }
    
    fr(0,n+1){
        rep(j,0,16){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    fr(1,n+1){
        rep(j,0,16){
            if (j - cartasValor[i] >= 0){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-cartasValor[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // fr(0,n+1){
    //     rep(j,0,16){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout(' ');
    // }

    cout << runs + pares * 2 + dp[n][15] * 2 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<char> cartas(n);
    fr(0, n) {
        char c; cin >> c;
        cartas[i] = c;
        cant[c] = 0;
    }

    solve(n, cartas);
}