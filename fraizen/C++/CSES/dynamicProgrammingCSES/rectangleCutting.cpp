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
#define MAXN 1000008
int dp[505][505];
// NO FUNCIONA
// lo que hay que hacer en realidad es por cada posicion
// de la matriz, hacer todos los cortes horizontales y todos
// los cortes verticales y quedarse con el minimo
// el algoritmo es O(n^3).


void solve(int n, int m) {
    fr(1,min(n+1,m+1)){
        dp[i][i] = 0;
    }
    fr(2,n+1){
        dp[i][1] = i - 1;
    }
    fr(2,m+1){
        dp[1][i] = i - 1;
    }
    // fr(0,n+1){
    //     rep(j,0,m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout(' ');
    // }
    // cout(' ');
    fr(2,n+1){
        rep(j,2,m+1){
            if (dp[i][j] == 1e5){
                if (i-j > j){
                    dp[i][j] = 1 + dp[i-j][j];
                } else {
                    dp[i][j] = 1 + dp[j][i-j];
                }
            }
        }
    }
    // fr(0,n+1){
    //     rep(j,0,m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout(' ');
    // }
    cout(dp[n][m]);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n,m;
    cin >> n >> m;
    if (m>n){
        swap(m,n);
    }
    fr(0,n+1){
        rep(j,0,m+1){
            dp[i][j] = 1e5;
        }
    }
    
    solve(n,m);
}