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
map<ll,ll> m;
ll res;

void calcular(int i , int j){
    while(min(m[i],m[j]) != 0){
        if (m[i] >= m[j] +2){
            res++;
            m[i]-=3;
            m[j]-=1;
        } else if (m[i]>=1 && m[j]>=2){
            res++;
            m[i]-=1;
            m[j]-=2;
        } else {
            break;
        }
    }
}

void solve() {
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
    fr(0,n){
        m[a[i]%5]++;
    }
    res = 0;
    res += m[0];
    ll grupos23 = min(m[2],m[3]);
    ll grupos14 = min(m[1], m[4]);
    res += grupos23 + grupos14;
    m[0] = 0;
    m[2] -= grupos23;
    m[3] -= grupos23;
    m[1] -= grupos14;m[4] -= grupos14;
    if (m[1] > 0 && m[2] > 0){
        calcular(1,2);
    } else if (m[1] > 0 && m[3] > 0){
        calcular(3,1);
    } else if (m[4] > 0 && m[2] > 0){
        calcular(2,4);
    } else if (m[4] > 0 && m[3] > 0){
        calcular(4,3);
    }
    //acordarse de haber restado en el mapa
    res += m[1]/5 + m[2]/5 + m[3]/5 + m[4]/5;
    cout << res << '\n';
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