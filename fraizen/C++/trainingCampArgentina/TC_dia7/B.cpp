#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define f first
#define s second
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
const int VECTOR_SIZE = 30005;

vvi costos(VECTOR_SIZE);

void solve(ll n, ll m) {
    ll res = -1;
    rep(target, costos[1].size(), n+1){
        // cout(target);
        vi faltan;
        ll votos = costos[1].size();
        ll cur = 0;
        fr(2,m+1){
            if (costos[i].size() >= target){
                // cout << "I: " << i << " Costos[i].size: " << costos[i].size() << "\n";
                for(int j = 0; j < costos[i].size() && (j <= (costos[i].size()-target)); j++){
                    cur += costos[i][j];
                    // if (target == 2){
                    //     cout("Compro xq tiene mas");
                    // }
                    votos++;
                }
                for(int k = costos[i].size()-target+1; k < costos[i].size(); k++){
                    faltan.pb(costos[i][k]);
                }
            } else {
                for(int k = 0; k < costos[i].size(); k++){
                    faltan.pb(costos[i][k]);
                }
            }
        }
        // fr(0,faltan.size()){
        //     cout << faltan[i] << ' ';
        // }
        if (votos < target){ //tengo que comprar
            sort(faltan.begin(), faltan.end());
            int f = 0;
            while (votos < target && f < faltan.size()){
                // cout << "faltan[f]" << faltan[f] << "\n";
                cur += faltan[f];
                votos++;
                f++;
            }
            // cout << "Current: "<< "\n";
            // cout(cur);
            if (f == faltan.size()){
                continue;
            }
        }
        // cout(cur);
        if (res == -1 || cur < res){
            res = cur;
        }
    }
    
    cout(res);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    if (m==1) {
        cout << 0 << "\n";
        return 0;
    }
    fr(0,n){
        ll partido, precio;
        cin >> partido >> precio;
        costos[partido].pb(precio);
    }
    fr(0,costos.size()){
        sort(costos[i].begin(), costos[i].end());
    }
    solve(n,m);
}
