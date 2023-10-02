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
int grid[502][502];
int dp[502][502];

void precompute(int n, int m) {
    //inicializo fila y columna 1. 
    int seguidos = 0;
    fr(1,n+1){
        if (grid[i][1] == 1){
            seguidos++;
            if (seguidos == 1){
                dp[i][1] = dp[i-1][1];
            } else {
                dp[i][1] = dp[i-1][1] + 1;
            }
        } else {
            seguidos = 0;
            dp[i][1] = dp[i-1][1];
        }
    }
    seguidos = 0;
    fr(1,m+1){
        if (grid[1][i] == 1){
            seguidos++;
            if (seguidos == 1){
                dp[1][i] = dp[1][i-1];
            } else {
                dp[1][i] = dp[1][i-1] + 1;
            }
        } else {
            seguidos = 0;
            dp[1][i] = dp[1][i-1];
        }
    }

    fr(2,n+1){
        rep(j,2,m+1){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if (grid[i][j] == 1 && (grid[i-1][j] == 1)){
                dp[i][j] += 1;
            }
            if (grid[i][j] == 1 && (grid[i][j-1] == 1)){
                dp[i][j] += 1;
            }
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Parsing
    int n, m;
    cin >> n >> m;
    fr(1,n+1){
        rep(j,1,m+1){
            char c;
            cin >> c;
            if (c == '#'){
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
        }
    }
    precompute(n,m);
    int q;
    cin >> q;
    fr(0,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int res = dp[c][d];
        if ((b-1) >= 1){
            res -= dp[c][b-1];
            rep(j,a,c+1){
                if (grid[j][b-1] == 1 && (grid[j][b] == 1)){
                    res--;
                }
            }
        } 
        if ((a-1) >= 1){
            res -= dp[a-1][d];
            rep(j,b,d+1){
                if (grid[a][j] == 1 && (grid[a-1][j] == 1)){
                    res--;
                }
            }
        }
        if ((a-1) >= 1 && (b-1) >= 1){
            res += dp[a-1][b-1];
        } 
        cout(res);
    }
}