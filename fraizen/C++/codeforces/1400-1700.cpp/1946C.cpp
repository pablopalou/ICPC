#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

const int MAXN = 100100;
vector<vector<int>> adj(MAXN);
vector<int> subtree_size(MAXN);
int n,k;
int comp;

int dfs(int v, int parent, int mid) {
    subtree_size[v] = 1;
    for (int child : adj[v]) {
        if (child != parent) { 
            subtree_size[v] += dfs(child, v, mid);
        }
    }
    if (subtree_size[v] >= mid){
        comp++;
        if (parent!=-1){
            subtree_size[parent] -= subtree_size[v];
        }
    }
    return subtree_size[v];
}

// Function to check if it's possible to get k+1 components each of at least 'mid' size
bool puedo(int mid) {
    fill(subtree_size.begin(), subtree_size.end(), 0);
    comp = 0;
    dfs(0, -1, mid);
    return comp >= k + 1;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >>k;
    fr(0,n){
        adj[i].clear();
    }
    fr(0,n-1){
        int a,b; cin >> a >> b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int res = 1;
    int l = 1;
    int r = n / (k+1) + 1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if (puedo(mid)){
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << res << "\n";
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}