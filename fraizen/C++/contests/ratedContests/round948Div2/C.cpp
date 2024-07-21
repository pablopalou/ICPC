#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    ll x;
    cin >> x;
    vector<int> a;
    
    for (int i = 0; x > 0; i++) {
        if (x & 1) {
            a.push_back(1);
            x >>= 1;
            if (x & 1) {
                a.push_back(-1);
                x++;
            } else {
                a.push_back(0);
            }
        } else {
            a.push_back(0);
            x >>= 1;
        }
    }
    
    while (a.back() == 0) {
        a.pop_back();
    }
    
    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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
