#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define MAXN 30005
#define mp make_pair

int degree[MAXN];
int ans[17][MAXN];
int n;

void query(string s, int num){ //num es numero de query
    cout << "QUERY " << s << endl;
    if (num == 0){
        fr(0,n){
            cin >> degree[i];
        }
    } else {
        fr(0,n){
            cin >> ans[num-1][i];
        }
    }
}

void solve() {
    cin >> n;
    string s;
    fr(0,n){
        s+='1';
    }
    query(s, 0);
    for(int i = 0; (1 << i) <= n; i++){
        s = "";
        rep(j,0,n){
            if ((j & (1 << i)) != 0){
                s+='1'; 
            } else {
                s+='0';
            }
        }
        query(s, i+1);
    }
    // cout << "DEGREE " << endl;
    // fr(0,n){
    //     cout << degree[i] << " ";
    // }
    // cout << endl;

    // fr(0,5){
    //     rep(j,0,5){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    vector<pair<int, int> > res;
    queue<int> q;
    fr(0,n){
        if (degree[i] == 1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(degree[cur] == 0)break;
        int parent = 0;
        for(int i = 0; (1 << i) <= n; i++){ //reconstruyo el padre
            if (ans[i][cur]){
                parent += (1 << i);
            }
        }
        res.pb(mp(cur, parent));
        //ahora actualizo las respuestas, para que no interfiera el nodo que ya use
        for(int i = 0; (1 << i) <= n; i++){ //reconstruyo el padre
            if (cur & (1 << i)){
                ans[i][parent]--;
            }
        }
        degree[parent]--;
        if (degree[parent] == 1){
            q.push(parent);
        }
    }
    cout << "ANSWER" << endl;
    fre(res){
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}