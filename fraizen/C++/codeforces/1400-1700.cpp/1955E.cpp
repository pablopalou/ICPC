#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

bool puedo(int k, int n, string s){
    int cont = 0;
    deque<int> next;
    // cout << "pruebo k = " << k << endl;
    fr(0,n-k+1){
        if (! next.empty() && next[0] == i){
            cont--;
            next.pop_front();
        }
        if ((s[i] == '1' && (cont % 2 == 0)) || (s[i] == '0' && (cont % 2 == 1))){
            // cout << "continuo " << endl;
            continue;
        }
        //tengo que arreglar este
        cont++;
        next.pb(i + k);
        // cout << "agrego " << i+k << endl;
    }
    //chequear los ultimos...
    fr(n-k, n){
        // cout << "veo i = " << i << endl;
        // cout << "cont " << cont << endl;
        // cout << s[i] << endl;
        if (! next.empty() && next[0] == i){
            cont--;
            next.pop_front();
        }
        if ((s[i] == '1' && (cont % 2 == 0)) || (s[i] == '0' && (cont % 2 == 1))){
            continue;
        }
        // cout << "retorno false" << endl;
        return false;
    }
    // cout << "retorno true" << endl;
    return true;
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n; string s; cin >> s;
    int ans = 1;
    fr(2,n+1){
        if (puedo(i, n, s)){
            ans = i;
        }
    }
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}