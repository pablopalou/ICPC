#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef set<ll> usi;
typedef map<ll, string> mis;
typedef map<ll, string> umis;
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf 1e9
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

const int MAX = 602; // maximum number of vertices
vi adj[MAX]; // adjacency list
int match[MAX], dist[MAX];
int n; // number of vertices in left and right sets respectively

// map<string, int> minimo;
int minimo[301];
map<int, bool [301]> prohibido;
bool usado[301];
string res[301];
string totalHorses[301];

bool bfs() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(match[i]==0) {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = inf;
    }
    dist[0] = inf;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u!=0) {
            for(int v: adj[u]) {
                if(dist[match[v]]==inf) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (dist[0]!=inf);
}

bool dfs(int u) {
    if(u==0) return true;
    for(int v: adj[u]) {
        if(dist[match[v]]==dist[u]+1 && dfs(match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    dist[u] = inf;
    return false;
}

int hopcroft_karp() {
    int matching = 0;
    while(bfs()) {
        for(int i=1; i<=n; i++) {
            if(match[i]==0 && dfs(i)) matching++;
        }
    }
    return matching;
}

void update(int m, int w, bool horses[], int n){
    fr(1,n+1){
        if (!horses[i]){
            int min_total_horses = minimo[i];
            if (w == min_total_horses){
                minimo[i]++;
            } else if (w > min_total_horses){
                prohibido[i][w] = true;
            }
        } else {
            minimo[i] = max(minimo[i], w);
        }
    }
}

void solve() {
    cin >> n;
    fr(0,302){
        usado[i] = false;
    }
    map<string, int> idx_name;
    fr(1,n+1){
        string name; cin >> name;
        totalHorses[i] = name;
        minimo[i] = 1;
        idx_name[name] = i;
    }
    int k; cin >> k;
    int m, w;
    fr(0,k){
        cin >> m >> w;
        bool horses[301];
        rep(l, 1, n+1) {
            horses[l] = false;
        }
        rep(j,0,m){
            string s;
            cin >> s;
            horses[idx_name[s]] = true;
        }
        update(m, w, horses, n);
    }

    fr(1, n+1) {
        // i -> minimo , ... y no estan prohibidos
        int s = minimo[i];
        while(s < n+1) {
            if (!prohibido[i][s]) {
                adj[i].pb(s+300);
                adj[s+300].pb(i);
            }
            s += 1;
        }
    }

    // fr(1, n+1) {
    //     cout << "Adj: " << i << ": ";
    //     fre(adj[i]) {
    //         cout << e << " ";
    //     }
    //     cout(" ");
    // }
    // cout(" ");

    hopcroft_karp();
    // fr(1, n+1) {
    //     cout << match[i] << " ";
    // }
    // cout(" ");
    string res[n+1];
    fr(1, n+1) {
        res[match[i]-300] = totalHorses[i];
    }
    fr(1, n+1) {
        cout << res[i] << " ";
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}