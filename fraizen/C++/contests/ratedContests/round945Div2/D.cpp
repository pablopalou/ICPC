#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

int query(int l, int x){
    cout << "? " << l << " " << x << endl;
    int res; cin >> res;
    return res;
}

void ans(int x){
    cout << "! " << x << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
}

void solve() {
    int n,k; cin >> n >> k;
    int maxi = 0; 
    for(int i = n; i>=0; i--){
        if (query(1,i*n) == n){
            maxi = i;
            break;
        }
    }
    for(int l = 1; l <=n/k; l++){
        int m = l * maxi;
        bool esEste = true;
        int q = 0;
        int index = 1;
        while(q < k){
            index = query(index, m) + 1;
            if (index == n+2){
                esEste = false; break;
            }
            if (q == k-1 && index != n+1){
                esEste = false; break;
            }
            if (index == n+1 && q < k-1){
                esEste = false; break;
            }
            q++;
        }
        if (esEste){
            ans(m);
            return;
        }
    }
    ans(-1);
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