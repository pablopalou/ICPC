#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

int n; int m;
string s1;
string s2;

bool puedo(int mid){
    int p1 = 0;
    int p2 = 0;
    while(p1 < mid && p2 < m){
        if (s1[p1] == s2[p2]){
            p1++;
            p2++;
        } else {
            p2++;
        }
    }
    if (p1 == mid){
        return true;
    }
    return false;
}

// Copiar obligatoriamente 0
void solve() {
    cin >> n >> m;
    cin >> s1 >> s2;
    int l = 0;
    int r = n;
    int res = 0;
    while(l<=r){
        int mid = l + (r-l) /2;
        if (puedo(mid)){
            res = mid;
            l= mid+1;
        } else {
            r = mid-1;
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