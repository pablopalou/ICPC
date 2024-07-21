#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())

ll ans = 0;
struct Trie {
    map<char, Trie> m;
    ll count = 0;
  void add(const string& s, int p = 0) {
    count++;
    if (s[p]) m[s[p]].add(s, p + 1);
  }
  void dfs(bool root = true) {
    if (!root){
        ans += (count * (count-1))/2;
    }
    forall(it, m) it->second.dfs(false);
  }
};

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    Trie t;
    fr(0,n){
        string s;
        cin >>s;
        t.add(s);
    }
    t.dfs();
    cout << ans << "\n";
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

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define cout(x) cout << x << "\n";
// #define pb push_back

// ll n;
// // string a[300100];
// ll res = 0;

// //esto esta contando solo el primer grupo digamos
// void contar(vector<ll> s, set<ll> indices,  ll curLetter){
//     if (s.size() == 1) return;
//     if (curLetter >= a[s[0]].size()){//tengo que sacar el primero y mandar a la misma curLetter
//         vector<ll> newV;
//         fr(1,s.size()){
//             newV.pb(s[i]);
//         }
//         indices.erase(s[0]);
//         contar(newV, indices, curLetter);
//         return;
//     }
//     char c = a[s[0]][curLetter];
//     int j = 1;
//     int count = 0;
//     vector<ll> v;
//     set<ll> sss;
//     v.pb(s[0]);
//     sss.insert(s[0]);
//     while (j<s.size() && curLetter < a[s[j]].size() && a[s[j]][curLetter] == c){
//         count++;
//         v.pb(s[j]);
//         sss.insert(s[j]);
//         j++;
//     }
//     set<ll> newSet;
//     vector<ll> v2;
//     fre(indices){
//         if (find(sss.begin(), sss.end(), e) == sss.end()){
//             newSet.insert(e);
//             v2.pb(e);
//         }
//     }
//     res += count * (count-1) / 2;
//     contar(v, sss, curLetter+1);
//     contar(v2, newSet, curLetter);
// }

// // Copiar obligatoriamente 0
// void solve() {
//     cin >> n;
//     fr(0,n){
//         cin >> a[i];
//     }
//     sort(a,a+n);
//     vector<ll> v;
//     set<ll> ind;
//     fr(0,n){
//         v.pb(i);
//         ind.insert(i);
//     }
//     contar(v, ind ,0);
//     cout << res << '\n';
//     // int i = 0; int j = 0;
//     // while(i < n){
//     //     char curLetter = a[i][j];
//     //     while(i+1 < n && j<a[i+1].size() && a[i+1][j] == curLetter){

//     //     }
//     // }
//     // fr(0,n){
//     //     cout << a[i] << ' ';
//     // }
// }

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     // cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }