#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    int mexIzq[n], mexDer[n];
    int curMex = 0;
    set<int> s1;
    fr(0,n){
        s1.insert(a[i]);
        if (curMex == a[i]){
            while(s1.find(curMex) != s1.end()){
                curMex++;
            }
        }
        mexIzq[i] = curMex;
    }

    curMex = 0;
    set<int> s2;
    for(int i = n-1; i>=0; i--){
        s2.insert(a[i]);
        if (curMex == a[i]){
            while(s2.find(curMex) != s2.end()){
                curMex++;
            }
        }
        mexDer[i] = curMex;
    }

    // fr(0,n){
    //     cout << mexIzq[i] << ' ';
    // }
    // cout << "fdasf" << endl;
    // fr(0,n){
    //     cout << mexDer[i] << ' ';
    // }
    // cout << "\n";
    int pos = -1;
    fr(0,n-1){
        if (mexIzq[i] == mexDer[i+1]){
            pos = i+1;
        }
    }
    if (pos == -1){
        cout << "-1\n"; return;
    }
    cout << 2 << "\n";
    cout << 1 <<' ' <<pos << "\n";
    cout << pos+1 <<' ' << n << "\n";
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