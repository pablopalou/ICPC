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
#define MAXN 1002
int cur;

int dp[MAXN][(1 << 10)];

void solve(int n, const vector<tuple<int, int, int,int>>& shows) {
    int cantShows = shows.size();
    int inicio, fin, canciones, stage;
    int comienzo = 0;
    fr(0,MAXN){
        tie(fin, inicio, canciones, stage) = shows[i];
        if (fin > 0) {
            comienzo = i;
            break;
        }
    }
    dp[comienzo][1 << stage] = canciones;
    
    fr(comienzo + 1,MAXN){
        tie(fin, inicio, canciones, stage) = shows[i];
        rep(mask,1,1 << n){
            tuple<int,int,int,int> a = {inicio, 0,0,0};
            auto it = upper_bound(shows.begin(), shows.end(), a);
            it--;
            int pos = it - shows.begin();
            // calculate new dp value, how can i do it? 
            dp[i][mask | (1 << stage)] = max(dp[pos][mask | (1 << stage)] + canciones,dp[i-1][mask]);
        }
    }

    fr(0,MAXN){
        rep(j,0,1 << n){
            cout << dp[i][j] << ' ';
        }
        cout(' ');
    }

    cout << dp[cantShows-1][(1 << n) - 1];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> shows(MAXN);
    // guardo fin, inicio, canciones, stage.
    int stage;
    cur = 0;
    fr(0,n){
        int cant;
        cin >> cant;
        rep(j,0,cant){
            int inicio, fin, canciones;
            cin >> inicio >> fin >> canciones;
            shows[cur] = {fin, inicio, canciones, i};
            cur += 1;
        }
    }
    sort(shows.begin(), shows.end());

    fr(0,cur+1){
        rep(j,0,1 << n){
            dp[i][j] = 0;
        }
    }

    solve(n,shows);
}