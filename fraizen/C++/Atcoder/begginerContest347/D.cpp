#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mp make_pair
#define pb push_back

void swapBits(ll &res1, ll &res2) {
    for (int i = 0; i < 60; ++i) { // Assuming we're working within 60 bits as per your code
        ll bit1 = 1LL << i; // Bit to check in position i
        // Check if bit i is set in res1 but not in res2 (to move from res1 to res2)
        if ((res1 & bit1) && !(res2 & bit1)) {
            // Clear bit i in res1
            res1 &= ~bit1;
            // Set bit i in res2
            res2 |= bit1;
            break; // Exit after swapping one pair of bits
        }
    }
}

// Copiar obligatoriamente 0
void solve() {
    ll a, b , n; cin >> a >> b >>n;
    //puedo si los dejo empatados
    priority_queue<pair<ll, char> > pq;
    ll res1 = 0LL;
    ll res2 = 0LL;
    pq.push(mp(a,'a'));
    pq.push(mp(b,'b'));
    ll cant = __builtin_popcountll(n);
    ll iter = 0;
    // cout << cant << endl;
    vector<char> asignar;
    while(cant){
        pair<ll,char> cur= pq.top();
        pq.pop();
        // cout << cur.first << ' ' << cur.second << endl;
        asignar.pb(cur.second);
        pq.push(mp(cur.first-1, cur.second));
        cant--;
        iter++;
    }
    // cout << "asignar" << asignar.size() << endl;
    pair<ll,char> newA = pq.top();
    pq.pop();
    pair<ll,char> newB = pq.top();
    if (newA.first != newB.first || newA.first < 0){
        cout << "-1\n"; return;
    }
    ll cant2 = 0;
    fr(0,60){
        // cout << "I = " << i << endl;
        if (cant2 >= asignar.size()){
            break;
        }
        if ((1LL << i) & n){
            if (asignar[cant2] == 'a'){
                res1 += (1LL<<i);
                // cout << "Sumo " << (1<<i) << endl;
            } else {
                res2 += (1LL<<i);
                // cout << "Sumo " << (1<<i) << endl;
            }
            cant2++;
        }
    }

    // cout << __builtin_popcountll(res1) << endl;
    // cout << __builtin_popcountll(res2) << endl;

    // cout << newA.first << endl;
    // cout << "here " << res1 << ' ' << res2 << endl;
    ll falta = newA.first;
    // cout << falta << endl;
    fr(0,60){
        if ((! ((1LL<<i) & n)) && falta){
            res1 += (1LL<<i);
            res2 += (1LL<<i);
            falta--;
            if (falta == 0){
                break;
            }
        }
    }
    if (res1 >= (1LL << 60)) {
        swapBits(res1, res2);
    }
    // cout << falta << endl;
    // cout << __builtin_popcountll(res1) << endl;
    // cout << __builtin_popcountll(res2) << endl;
    //hay un res que queda mayor o igual a 1<<60 y eso no puede pasar
    if (n != (res1^res2) || (__builtin_popcountll(res1) != a || __builtin_popcountll(res2) != b )){
        cout << "-1\n"; return;
    }
    cout << res1 << ' ' << res2 << "\n";
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