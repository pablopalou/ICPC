#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mp make_pair

// Copiar obligatoriamente 0
void solve() {
    int n, k; cin >> n >> k;
    map<int, string> m;
    int a[n];
    priority_queue<pair<int, int>> pq;
    fr(0,n){
        string droga; cin >> droga;
        int val; cin >> val;
        m[i] = droga;
        a[i] = val;
        pq.push(mp(-val, -i));
    }
    while(k && !pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        pq.push(mp(p.first - a[-p.second], p.second));
        cout << -p.first << " " << m[-p.second] << "\n";
        k--;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}