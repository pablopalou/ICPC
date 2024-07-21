#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    if ((p1 + p2 + p3) % 2 == 1){
        cout << "-1\n"; return;
    }
    priority_queue<int> pq;
    if (p1 > 0){
        pq.push(p1);
    }
    if (p2 > 0){
        pq.push(p2);

    }
    if (p3>0){
        pq.push(p3);
    }
    int res = 0;
    // cout <<"SIZe" << pq.size() << endl;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        res+=1;
        if (a > 1){
            pq.push(a-1);
            // cout << "agrego a " << endl;
        }
        if (b > 1){
            pq.push(b-1);
            // cout << "agrego b " << endl;
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