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

void solve() {
    int n1,n2,n3; cin >> n1>>n2>>n3;
    int n; cin >> n; int a[n]; fr(0,n) cin >> a[i];
    sort(a, a+n);
    int grundy[105];
    grundy[0] = 0;
    fr(1,105){
        bool values[105];
        rep(j,0,105) values[j] = false;
        rep(j,0,n){
            if (i - a[j] >= 0){
                values[grundy[i-a[j]]] = true;
            } else {
                break;
            }
        }
        int mex = 1050;
        rep(j,0,105){
            if (!values[j]){
                mex = j;
                break;
            }
        }
        grundy[i] = mex;
    }
    int res = 0;
    res = res ^ grundy[n1]^ grundy[n2]^ grundy[n3];
    if (res == 0){
        cout << "Vasya\n";
    } else {
        cout << "Peter\n";
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