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
#define mp make_pair
#define inf 2e9+20

void solve() {
    int n,m; cin >> n >> m;
    vector<pair<int,int>> pref(n);
    fr(0,n){
        cin >> pref[i].first >> pref[i].second;
    }
    vector<tuple<int,int,int>> showers(m);
    fr(0,m){
        int s,d,t; cin >> s >> d >> t;
        showers[i] = {s,d,t};
    }
    //me fijo pa cada persona, cual le sirve
    vector<vector<pair<int,int>>> puedo(n, vector<pair<int,int>>());
    fr(0,n){
        rep(j,0,m){
            if (pref[i].first == get<2>(showers[j]) && pref[i].second <= get<1>(showers[j])){
                puedo[i].pb({get<0>(showers[j]), get<1>(showers[j])});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(puedo[i].begin(), puedo[i].end());
    }
    // fr(0,n){
    //     cout << "el i = " << i << "puede en " << endl;
    //     fre(puedo[i]){
    //         cout << e.first << " ";
    //     }
    //     cout << endl;
    // }
    //ahora hago la dp
    int dp[1<<n]; //dp[mask] es el tiempo minimo en el cual se pueden bañar los que estan en 1
    fr(0,(1<<n))dp[i] = inf;
    dp[0] = 0;
    for(int mask = 1; mask < (1<<n); mask++){
        //me tengo que fijar todos los que estan prendidos y fijarme cual seria mejor que vaya ultimo no? 
        int best = inf;
        fr(0,n){
            if (mask & (1<<i)){ //el i esta prendido
                int tiempo = dp[mask ^ (1<<i)];
                auto it = lower_bound(puedo[i].begin(), puedo[i].end(), mp(tiempo,0));
                int cur = inf;
                if (it != puedo[i].begin()){
                    it--;
                    //me fijo si puedo bañarme en el mismo slot que el anterior
                    if ((tiempo <= ((*it).first + (*it).second)) && ((tiempo + pref[i].second) <= ((*it).first + (*it).second))){
                        cur = tiempo + pref[i].second; 
                        best = min(best, cur);
                        continue;
                    }
                    it++;
                }
                if (it != puedo[i].end()){
                    cur = (*it).first + pref[i].second;   
                }
                best = min(best, cur);
            }
        }
        dp[mask] = best;
    }
    cout << dp[(1<<n)-1] << '\n';
}

    // for(int mask = 1; mask < (1<<n); mask++){
    //     //me tengo que fijar todos los que estan prendidos y fijarme cual seria mejor que vaya ultimo no? 
    //     int best = inf;
    //     fr(0,n){
    //         if (mask & (1<<i)){ //el i esta prendido
    //             int tiempo = dp[mask ^ (1<<i)];
    //             auto it = lower_bound(puedo[i].begin(), puedo[i].end(), mp(tiempo,0));
    //             int cur = inf;
    //             if (it != puedo[i].begin()){
    //                 //me fijo si me puedo bañar en el mismo slot que el anterior
    //                 it--;
    //                 if ((*it).first + (*it).second - tiempo >= pref[i].second && ((*it).first < tiempo && tiempo <= ((*it).first + (*it).second))){
    //                     //me puedo bañar en este timeslot
    //                     cur = tiempo + pref[i].second;
    //                     best = min(best, cur);
    //                     continue;
    //                 }
    //             }
    //             it++;
    //             if (it != puedo[i].end()){
    //                 cur = (*it).first + pref[i].second;   
    //             }
    //             best = min(best, cur);
    //         }
    //     }
    //     dp[mask] = best;
    // }

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