#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n"
#define sz size

// Be careful with nodes with degree 0 when solving your problem, the
// comments below assume that there are no nodes with degree 0.
//
// Euler [path/cycle] exists in a bidirectional graph iff the graph is
// connected and at most [2/0] nodes have odd degree. The path must
// start from an odd degree vertex when there are 2.
//
// Euler [path/cycle] exists in a directed graph iff the graph is
// [connected when making edges bidirectional / a single SCC], and
// at most [1/0] node have indg - outdg = 1, at most [1/0] node have
// outdg - indg = 1, all the other nodes have indg = outdg. The path
// must start from the node with outdg - indg = 1, when there is one.
//
// Directed version (uncomment commented code for undirected)
struct edge {
  int y;
  list<edge>::iterator rev;
  edge(int yy) : y(yy) {}
};
struct EulerPath {
  vector<list<edge>> g;
  EulerPath(int n) : g(n) {}
  void addEdge(int a, int b) {
    g[a].push_front(edge(b));
    auto ia = g[a].begin();
    g[b].push_front(edge(a));
    auto ib = g[b].begin();
    ia->rev=ib, ib->rev=ia;
  }
  vector<int> p;
  void go(int x) {
    while (sz(g[x])) {
      int y = g[x].front().y;
      g[y].erase(g[x].front().rev);
      g[x].pop_front();
      go(y);
    }
    p.push_back(x);
  }
  vector<int> getPath(int x) {  // get a path that starts from x
    // you must check that a path exists from x before calling get_path!
    p.clear(), go(x);
    reverse(p.begin(), p.end());
    return p;
  }
};

void solve() {
    int n,m; cin>>n>>m;
	int degree[n+m];
	fr(0, n+m) degree[i] = 0;
	int s=-1;
	int grid[n][m];
	vector<pair<int,int>> arista;
	set<int> filas, cols;
    fr(0, n) {
        rep(j, 0, m) {
            char v; cin>>v;
            if (v=='.') {
				grid[i][j]=-1;
				filas.insert(i);
				cols.insert(j+n);
				arista.push_back({i,j+n});
            } else {
				grid[i][j]=0;
			}
        }
    }
	int comp = 0;
	map<int,int> c;
	map<int,int> d;
	fre(filas) {
		s = comp;
		c[e] = comp;
		d[comp] = e;
		comp++;
	}
	fre(cols) {
		c[e] = comp;
		d[comp] = e;
		comp++;
	}
	EulerPath euler(comp);
	// cout << "comp\n";
	// fre(c) {
	// 	cout << e.first << ": " << e.second << endl;
	// }
	// cout << "desc\n";
	// fre(d) {
	// 	cout << e.first << ": " << e.second << endl;
	// }
	fre(arista) {
		// cout << e.first << "-" << e.second << endl;
		euler.addEdge(c[e.first], c[e.second]);
		// euler.addEdge(j, i);
		degree[c[e.first]]++;
		degree[c[e.second]]++;
	}
	// fr(0, comp) {
	// 	cout << degree[i] << " ";
	// }
	// cout << endl;

	int odd = 0;
	fr(0, comp) {
		if (degree[i]%2) odd++;
	}
	// cout << "odd " << odd << endl;
	if ((odd!=0&&odd!=2) || (s==-1)) {
		cout << "*\n";
		return;
	}
	fr(0, comp) {if(degree[i]%2) s=i;}
	// cout << "s " << s << endl;
	vector<int> path = euler.getPath(s);
    if (path.size() - 1 != arista.size()) {
        cout << "*\n";
        return;
    }
	// fre(path) cout << e << " ";
	// cout << endl;
	
	int res[n][m];
	fr(0, n) {
		rep(j, 0, m) {
			res[i][j]=0;
		}
	}
	bool fila = path[0] < filas.size();
	int id = 1;
	fr(1, path.size()) {
		if (fila) {
			res[d[path[i-1]]][d[path[i]]-n] = id;
		} else {
			res[d[path[i]]][d[path[i-1]]-n] = id;
		}
		fila = !fila;
		id++;
	}
	fr(0, n) {
		rep(j, 0, m) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

int main() {
    std:iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    //cin >> cases;
    while(cases--) {
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}