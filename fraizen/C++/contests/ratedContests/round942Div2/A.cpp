#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
int n;

bool check(const vector<int>& a, const vector<int>& b){
    fr(0,a.size()){
        if (a[i] > b[i]){
            return false;
        }
    }
    return true;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    fr(0,n){
        cin >>a[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    fr(0,n){
        cin >> b[i];
        // cout << b[i] << ' ';
    }
    // cout << endl;
    // return;
    int res = 0;
    while(!check(a,b) && res <=n){
        res++;
        for(int i = n-1; i>0;i--){
            a[i] = a[i-1];
        }
        a[0] = 0; 
        // fr(0,n){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
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