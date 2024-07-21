#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    ll n,m,k; cin >> n >> m >> k;
    ll a[n][m];
    fr(0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }
    ll unos = 0;
    ll ceros = 0;
    ll mat[n][m];
    fr(0,n){
        string s; cin >> s;
        rep(j, 0, m){
            mat[i][j] = s[j]-'0';
            if (s[j] == '1'){
                unos+=a[i][j];
            } else {
                ceros+= a[i][j];
            }
        }
    }
    ll dif = abs(unos-ceros);
    if (dif == 0){
        cout << "YES\n"; return;
    }
    fr(0,n){
        rep(j,0,m){
            if (i > 0){
                mat[i][j] += mat[i-1][j];
            } 
            if (j > 0){
                mat[i][j] += mat[i][j-1];
            }
            if (i > 0 && j > 0){
                mat[i][j] -= mat[i-1][j-1];
            }
        }
    }
    ll gcdd = 0;
    fr(k-1,n){
        rep(j,k-1,m){
            ll cur = mat[i][j];
            if (i > k-1){
                cur -= mat[i-k][j];
            }
            if (j > k-1){
                cur -= mat[i][j-k];
            }
            if (i > k-1 && j > k-1){
                cur += mat[i-k][j-k];
            }
            gcdd = gcd(gcdd, abs(k*k - cur - cur)); 
        }
    }
    if (gcdd == 0){
        cout << "NO\n"; return;
    }
    if (dif % gcdd == 0){
        cout << "YES\n"; return;
    }
    cout << "NO\n"; return;
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