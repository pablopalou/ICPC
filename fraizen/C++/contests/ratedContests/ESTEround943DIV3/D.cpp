#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
// #define pb push_back

// Copiar obligatoriamente 0
void solve() {
    ll n,k,pb,ps; cin >> n>>k>>pb>>ps;
    pb--; ps--;
    ll p[n]; ll a[n];
    ll ptsB = 0;
    ll ptsS = 0;
    fr(0,n){
        cin >> p[i];
    }
    fr(0,n){
        cin >> a[i];
    }
    unordered_set<int> posB, posS;
    ll maxB = 0;
    ll k2 = k;
    ll curMax = 0;
    ll resto = 0;
    while(posB.find(pb) == posB.end() && k2 > 0){
        posB.insert(pb);
        curMax = max(curMax, a[pb]);
        resto += a[pb];
        ptsB = max(ptsB, curMax * k2 + resto - curMax);
        pb = p[pb]-1;
        k2--;
    }
    ll restoS = 0;
    ll curMaxS = 0;
    ll maxS = 0;
    ll k3 = k;
    while(posS.find(ps) == posS.end() && k3 > 0){
        posS.insert(ps);
        curMaxS = max(curMaxS, a[ps]);
        restoS += a[ps];
        ptsS = max(ptsS, curMaxS * k3 + restoS - curMaxS);
        ps = p[ps]-1;
        k3--;
    }
    // cout << "Puntos B " << ptsB << endl;
    // cout << "Puntos S " << ptsS << endl;
    // while(k){
    //     ptsB += a[pb];
    //     ptsS += a[ps];
    //     if (a[pb] < a[p[pb]-1]){
    //         pb = p[pb]-1;
    //     }
    //     if (a[ps] < a[p[ps]-1] ){
    //         ps =  p[ps]-1;
    //     }
    //     k--;
    // }
    if (ptsB == ptsS){
        cout << "Draw\n"; return;
    }
    if (ptsB > ptsS){
        cout << "Bodya\n"; return;
    } else {
        cout << "Sasha\n"; return;
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}