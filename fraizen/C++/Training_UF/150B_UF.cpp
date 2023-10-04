#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x

class UnionFind { // OOP style
    private: vi p, rank; // remember: vi is vector<int>
    public:
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); 
            for (int i = 0; i < N; i++) p[i] = i; 
        }
        
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
            } 
        } 
};

void solve(int n, int m, int k) {
    UnionFind u(n);
    rep(i, k-1, n){
        int l = i - k + 1;
        int r = i;
        while (l<r){
            u.unionSet(l,r);
            l+=1;
            r-=1;
        }
    }
    ll res = 1;
    set<int> componentes;
    rep(i,0,n){
        componentes.insert(u.findSet(i));
    }

    rep(i,0,componentes.size()){
        res = (res * m) % mod;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    solve(n,m,k);
}
