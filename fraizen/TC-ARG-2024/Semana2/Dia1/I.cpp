#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n; cin >> n;
    int a[3 * n];
    fr(0,n){
        cin >> a[i];
    }
    fr(0,n){
        a[i+n]=a[i];
        a[i+2*n] =a[i];
    }
    int mini = *min_element(a, a+n);
    int maxi = *max_element(a, a+n);
    // return;
    if (maxi <= mini*2.0){
        fr(0,n){
            cout << "-1 ";
        }
        cout << '\n'; return;
    }
    int l = 0;
    int r = 1;
    multiset<int> m;
    while(l < n){
        if (m.size() == 0){
            m.insert(a[l]);
            r=l+1;
            // cout << "Agrego al multiset " << a[0] << endl;  
        }
        while(r < 3*n && (*(m.rbegin()) <= (a[r]*2.0))){
            // cout << "Agrego al multiset " << a[r] << endl;  
            m.insert(a[r]);
            r++;
            // cout << "Subo R a " << r << endl;
        }
        // cout << r-l << " ";
        m.erase(m.find(a[l]));
        cout << r-l << " ";
        // cout << "respondo: " << l << " => " << r-l << endl;
        // cout << "Saco del multiset a " << a[l] << endl; 
        l++;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}