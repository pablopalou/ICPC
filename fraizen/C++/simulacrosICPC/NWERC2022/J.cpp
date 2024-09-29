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

#include <bits/stdc++.h>
using namespace std;

// Define the type and operation for the segment tree
typedef int tipo;
const tipo neutro = 0;
tipo oper(const tipo& a, const tipo& b) { return max(a, b); }

// Array-Based Segment Tree
struct ST {
    int sz;
    vector<tipo> t;
    
    // Constructor: Initialize the segment tree with size n
    ST(int n) {
        sz = 1;
        while(sz < n) sz <<= 1;  // Next power of two
        t.assign(2 * sz, neutro);
    }
    
    // Update the value at position p to val
    void set(int p, tipo val) {  // O(log n)
        p += sz;
        t[p] = max(t[p], val);  // Update with the maximum value
        while(p > 1){
            p >>= 1;
            t[p] = oper(t[2 * p], t[2 * p + 1]);
        }
    }
    
    // Query the maximum value in the range [i, j)
    tipo get(int i, int j) {  // O(log n)
        tipo res = neutro;
        i += sz;
        j += sz;
        while(i < j){
            if(i & 1){
                res = oper(res, t[i++]);
            }
            if(j & 1){
                j--;
                res = oper(res, t[j]);
            }
            i >>= 1;
            j >>= 1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    struct Suspect {
        int a; 
        int e;     
        int idx;  
    };
    
    vector<Suspect> suspects(n);
    vector<int> end_times;
    
    for(int i = 0; i < n; i++){
        int a, t;
        cin >> a >> t;
        suspects[i].a = a;
        suspects[i].e = a + t;
        suspects[i].idx = i;
        end_times.push_back(suspects[i].e);
    }
    
    sort(end_times.begin(), end_times.end());
    end_times.erase(unique(end_times.begin(), end_times.end()), end_times.end());
    auto get_compressed_idx = [&](int e) -> int {
        return lower_bound(end_times.begin(), end_times.end(), e) - end_times.begin();
    };
    
    int m = end_times.size(); 
    sort(suspects.begin(), suspects.end(), [&](const Suspect &s1, const Suspect &s2) -> bool{
        if(s1.a != s2.a)
            return s1.a < s2.a;
        return s1.e > s2.e;
    });
    
    ST st(m);
    vector<int> ans(n, 0);
    for(auto &s : suspects){
        int compressed_e = get_compressed_idx(s.e);
        tipo max_conv = st.get(compressed_e, m);
        ans[s.idx] = max_conv;
        st.set(compressed_e, ans[s.idx] + 1);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }
}

// typedef int tipo;
// const tipo neutro = -1;
// tipo oper(const tipo& a, const tipo& b) { return max(a,b); }
// // Compressed segtree, it works for any range (even negative indexes)
// struct ST {
//   ST *lc, *rc;
//   tipo val;
//   int L, R;
//   ST(int l, int r, tipo x = neutro) {
//     lc = rc = nullptr;
//     L = l, R = r, val = x;
//   }
//   ST(int l, int r, ST* lp, ST* rp) {
//     if (lp != nullptr && rp != nullptr && lp->L > rp->L) swap(lp, rp);
//     lc = lp, rc = rp;
//     L = l, R = r;
//     val = oper(lp == nullptr ? neutro : lp->val,
//                rp == nullptr ? neutro : rp->val);
//   }
//   // O(log(R-L)), parameter 'isnew' only needed when persistent
//   // This operation inserts at most 2 nodes to the tree, i.e. the
//   // total memory used by the tree is O(N), where N is the number
//   // of times this 'set' function is called. (2*log nodes when persistent)
//   void set(int p, tipo x, bool isnew = false) {  // return ST* for persistent
//     // uncomment for persistent
//     // if(!isnew) {
//     //   ST* newnode = new ST(L, R, lc, rc);
//     //   return newnode->set(p, x, true);
//     // }
//     if (L + 1 == R) {
//       val = x;
//       return;  // 'return this;' for persistent
//     }
//     int m = (L + R) / 2;
//     ST** c = p < m ? &lc : &rc;
//     if (!*c) *c = new ST(p, p + 1, x);
//     else if ((*c)->L <= p && p < (*c)->R) {
//       // replace by comment for persistent
//       (*c)->set(p, x);
//       // *c = (*c)->set(p,x);
//     } else {
//       int l = L, r = R;
//       while ((p < m) == ((*c)->L < m)) {
//         if (p < m) r = m;
//         else l = m;
//         m = (l + r) / 2;
//       }
//       *c = new ST(l, r, *c, new ST(p, p + 1, x));
//       // The code above, inside this else block, could be
//       // replaced by the following 2 lines when the complete
//       // range has the form [0, 2^k)
//       // int rm = (1<<(32-__builtin_clz(p^(*c)->L)))-1;
//       // *c = new ST(p & ~rm, (p | rm)+1, *c, new ST(p, p+1, x));
//     }
//     val = oper(lc ? lc->val : neutro, rc ? rc->val : neutro);
//     // return this; // uncomment for persistent
//   }
//   tipo get(int ql, int qr) {  // O(log(R-L))
//     if (qr <= L || R <= ql) return neutro;
//     if (ql <= L && R <= qr) return val;
//     return oper(lc ? lc->get(ql, qr) : neutro, rc ? rc->get(ql, qr) : neutro);
//   }
// };  // Usage: 1- RMQ st(MIN_INDEX, MAX_INDEX) 2- normally use set/get
// bool cmp(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
//     if (get<0>(a) == get<0>(b)){
//         return get<1>(a) > get<1>(b);
//     }
//     return get<0>(a) < get<0>(b);
// }

// void solve() {
//     int n; cin >> n; tuple<int,int,int> suspects[n];
//     fr(0,n){
//         int a,b; cin >> a >> b;
//         suspects[i] = {a,b+a,i};
//     }
//     sort(suspects, suspects+n, cmp);
//     ST st(1,2e9+10);
//     int ans[n]; memset(ans, 0, sizeof(ans));
//     fr(0,n){
//         // cout << get<0>(suspects[i]) << ','<< get<1>(suspects[i]) << ',' << get<2>(suspects[i]) << endl;
//         int left = get<1>(suspects[i]);
//         int maximo = 1 + st.get(left,2e9+2);
//         // cout << "Maximo -> " << maximo << endl;
//         ans[get<2>(suspects[i])] = maximo;
//         //pongo en el segment tree
//         // cout << "Pongo en el segment st["<<left<<"] = " << maximo << endl;
//         st.set(left,maximo);
//     }
//     fr(0,n){
//         cout << ans[i] << " ";
//     }
//     cout << '\n';
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