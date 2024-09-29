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
// #define RB(x) (x<n?r[x]:0)

// void csort(vector<int>& sa, vector<int>& r, int k){
//     int n = sa.size();
//     vector<int> f(max(255,n),0), t(n);
//     forn(i,n) f[RB(i+k)]++;
//     int sum = 0;
//     forn(i,max(255,n)) f[i] = (sum+=f[i])-f[i];
//     forn(i,n) t[f[RB(sa[i]+k)]++] = sa[i];
//     sa = t;
// }

// vector<int> constructSA(vector<int>& s){
//     int n = s.size(), rank;
//     vector<int> sa(n), r(n), t(n);
//     forn(i,n) sa[i] = i, r[i] = s[i];
//     for (int k = 1; k < n; k*=2){
//         csort(sa, r, k);
//         csort(sa, r, 0);
//         t[sa[0]] = rank = 0;
//         forr(i,1,n){
//             if(r[sa[i]] != r[sa[i-1]] || RB(sa[i] + k) != RB(sa[i-1] + k))
//                 rank++;
//             t[sa[i]] = rank;
//         }
//         r = t;
//         if (r[sa[n-1]] == n-1) break;
//     }
//     return sa;
// }

// vector<int> computeLCP(vector<int> &s, vector<int>& sa){
//     int n = s.size(), L = 0;
//     vector<int> lcp(n), plcp(n), phi(n);
//     phi[sa[0]] = -1;
//     forr(i,1,n) phi[sa[i]] = sa[i-1];
//     forn(i,n){
//         if (phi[i] < 0){
//             plcp[i] = 0;
//             continue;
//         }
//         while(s[i+L]==s[phi[i] + L]) L++;
//         plcp[i] = L;
//         L = max(L-1, 0);
//     }
//     forn(i,n) lcp[i] = plcp[sa[i]];
//     return lcp;
// }
#define RB(x) (x < n ? r[x] : 0)
void csort(vector<ll>& sa, vector<ll>& r, ll k) {  // counting sort O(n)
  ll n = sa.size();
  vector<ll> f(max(ll(255), n), 0), t(n);
  forn(i, n) f[RB(i + k)]++;
  ll sum = 0;
  forn(i, max(ll(255), n)) f[i] = (sum += f[i]) - f[i];
  forn(i, n) t[f[RB(sa[i] + k)]++] = sa[i];
  sa = t;
}
vector<ll> constructSA(vector<ll>& s) {  // O(n logn)
  ll n = s.size(), rank;
  vector<ll> sa(n), r(n), t(n);
  forn(i, n) sa[i] = i, r[i] = s[i];  // r[i]: equivalence class of s[i..i+k)
  for (ll k = 1; k < n; k *= 2) {
    csort(sa, r, k);
    csort(sa, r, 0);      // counting sort, O(n)
    t[sa[0]] = rank = 0;  // t : equivalence classes array for next size
    forr(i, 1, n) {
      // check if sa[i] and sa[i-1] are in te same equivalence class
      if (r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))
        rank++;
      t[sa[i]] = rank;
    }
    r = t;
    if (r[sa[n - 1]] == n - 1) break;
  }
  return sa;
}

// LCP(sa[i], sa[j]) = min(lcp[i+1], lcp[i+2], ..., lcp[j])
// example: "banana", sa = {5,3,1,0,4,2}, lcp = {0,1,3,0,0,2}
// Num of dif subvvector<ll>s: (n*n+n)/2 - (sum over lcp array)
// Build suffix array (sa) before calling
vector<ll> computeLCP(vector<ll>& s, vector<ll>& sa) {
  ll n = s.size(), L = 0;
  vector<ll> lcp(n), plcp(n), phi(n);
  phi[sa[0]] = -1;
  forr(i, 1, n) phi[sa[i]] = sa[i - 1];
  forn(i, n) {
    if (phi[i] < 0) {
      plcp[i] = 0;
      continue;
    }
    while (s[i + L] == s[phi[i] + L]) L++;
    plcp[i] = L;
    L = max(L - 1, 0LL);
  }
  forn(i, n) lcp[i] = plcp[sa[i]];
  return lcp;  // lcp[i]=LCP(sa[i-1],sa[i])
}


ll gcd (ll a, ll b) {
     while (b) {
       a %= b;
       swap(a, b);
     }
     return a;
}

void solve() {
    ll n; cin >>n; vector<ll> s(n);fr(0,n) cin >> s[i];
    ll auxN = n;
    s.pb(0);
    vector<ll> sa = constructSA(s);
    vector<ll> lcp = computeLCP(s,sa);
    lcp.erase(lcp.begin());
    ll total = n*n;
    ll cur = 0;

ll augmented_n = n + 1;
    for(auto idx : sa) {
        // cout << idx << endl;
        // Print the suffix starting at index 'idx'
        // If 's' represents characters, cast them to 'char'
        // Otherwise, print them as numbers
        // Here, I'll assume they are characters for demonstration
        
        // Convert the numerical representation back to characters
        string suffix = "";
        fr(idx, n){
            cout << s[i];
        }
        cout << endl;
        // for(ll j = idx; j < augmented_n - 1; ++j) { // Exclude the sentinel
        //     suffix += static_cast<char>(s[j]);
        // }
        // cout << suffix << "\n";
    }

    cout <<"LCP " << endl;
    fr(0,lcp.size()){
        cout << lcp[i] << ' ';
    }
    cout << endl;

    //CALCULE MAYOR ANTERIOR Y MAYOR POSTERIOR PERO DEBERIA HABER CALCULADO MENOR ANTERIOR Y MENOR POSTERIOR (SUPUESTAMENTE ARREGLADO)

    ll menorAnt[n];
    memset(menorAnt, -1, sizeof(menorAnt));
    stack<pair<ll,ll> > s1;
    s1.push(mp(lcp[n-1], n-1));
    ll i = n-2;
    while(i >=0){
        while(!s1.empty() && s1.top().first >= lcp[i]){ //no se si habria que poner mayor o igual...
            ll index = s1.top().second;
            s1.pop();
            menorAnt[index] = i;
        }
        s1.push(mp(lcp[i], i));
        i--;
    }

    ll menorPos[n];
    memset(menorPos,-1, sizeof(menorPos));
    stack<pair<ll,ll>> s2;
    s2.push(mp(lcp[0], 0));
    i = 1;
    while(i <= n-1){
        while(!s2.empty() && s2.top().first > lcp[i]){ //ojo el igual aca tmb
            ll index = s2.top().second;
            s2.pop();
            menorPos[index]= i;
        }
        s2.push(mp(lcp[i],i));
        i++;
    }
    fr(0,n){
        if (menorPos[i] == -1){
            menorPos[i] = n;
        }
    }


    fr(0,n){
        cur+= lcp[i] * (i-menorAnt[i]) * (menorPos[i]-i) * 2; 
        // cout << "Cur = " << cur << endl;
    }



    ll num = auxN * (auxN+1) / 2;
    num += cur;
    // cout << "num = " << num << endl;
    ll div = gcd(num,total);
    // cout << "total = " << total << endl;
    cout << num/div <<"/" << total/div << '\n';
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

    ll cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}