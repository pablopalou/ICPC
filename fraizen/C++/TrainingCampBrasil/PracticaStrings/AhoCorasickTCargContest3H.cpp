#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

struct Node {
    map<char, int> next, go;
    int p, link = -1;
    char pch;
    vector<int> leaf;
    int memo = -1; // Initialize memoization field
    Node(int pp, char c): p(pp), pch(c) {}
};

struct AhoCorasick {
    vector<Node> t = {Node(-1, '\0')};

    void add_string(const string &s, int id) {
        int v = 0;
        for(char c : s) {
            if(!t[v].next.count(c)) {
                t[v].next[c] = t.size();
                t.emplace_back(v, c);
            }
            v = t[v].next[c];
        }
        t[v].leaf.push_back(id);
    }

    int go(int v, char c);

    int get_link(int v) {
        if(t[v].link == -1) {
            if(v == 0 || t[v].p == 0) t[v].link = 0;
            else t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int countWords(int v) {
        if (t[v].memo != -1) return t[v].memo; // Return memoized result if available
        int count = t[v].leaf.size(); // Count words ending at this node
        if (t[v].link != -1 && t[v].link != 0) { // Accumulate counts from suffix links, avoiding infinite loop and root node
            count += countWords(get_link(v));
        }
        t[v].memo = count; // Memoize result
        return count;
    }
};

int AhoCorasick::go(int v, char c) {
    if (t[v].go.find(c) == t[v].go.end()) {
        if (t[v].next.count(c))
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return t[v].go[c];
}
const int N = 1e5 + 5;
vector<int> g[N];
int dp[N];

void calc(int x, AhoCorasick aho){
    dp[x] += aho.t[x].leaf.size();
    for (auto v: g[x]){
        dp[v] += dp[x];
        calc(v, aho);
    }
}

// Copiar obligatoriamente 0
void solve() {
    int n,m; cin >> n >> m;
    AhoCorasick aho;
    fr(0,n){
        string s; cin >> s;
        aho.add_string(s, i);
    }
    string text; cin >> text;

    fr(1,aho.t.size()){
        g[aho.get_link(i)].pb(i);
    }
    calc(0,aho);
    cout << endl;

    int ans = 0;
    int v = 0;
    vector<int> pos;
    vector<ll> tot;
    pos.pb(0);
    tot.pb(0);
    for(char c : text) {
        v = aho.go(v, c);
        pos.pb(v);
        tot.pb(dp[v]);
        ans += dp[v];
    }
    cout << ans << '\n';

    fr(0,m){
        int ps; char x; cin >> ps >> x;
        ps--;
        text[ps] = x; //cambio la letra
        int w = pos[ps];
        while(true){
            w = aho.go(w, text[ps++]);
            if (w == pos[ps]) break;
            ans -= tot[ps];
            pos[ps] = w;
            tot[ps] = dp[w]; // la dp esta bien xq ahora mi w es otro digamos, ya me movi con el otro caracter
            ans += tot[ps];
            if (ps == text.size()) break;
        }
        cout << ans <<"\n";
    }
    // fr(0,m){
    //     int pos; cin >> pos;
    //     pos--;
    //     char c; cin >> c;
    //     //sacar el texto
    //     int start = max(0, pos - 100);
    //     int end = min((int)text.length(), pos + 100);
    //     string substring = text.substr(start, end - start);
    //     // // cout << substring << endl;
    //     int cantidadSegmento = 0;
    //     // // Perform Aho-Corasick counting on the substring
    //     v = 0; // Start from the root of the trie
    //     for(char ch : substring) {
    //         v = aho.go(v, ch); // Move to the next state based on the current character
    //         cantidadSegmento += aho.countWords(v);
    //     }
    //     res -= cantidadSegmento;
    //     // cout(cantidadSegmento);
    //     //cambiar letra
    //     text[pos] = c;
    //     substring = text.substr(start, end - start);
    //     // cout(substring);
    //     int cantidadNuevoSegmento = 0;
    //     v = 0; // Start from the root of the trie
    //     for(char ch : substring) {
    //         v = aho.go(v, ch); // Move to the next state based on the current character
    //         // for(int u = v; u != 0; u = aho.get_link(u)) {
    //         //     if (!aho.t[u].leaf.empty()) {
    //         //        cantidadNuevoSegmento += aho.t[u].leaf.size();
    //         //     }
    //         // }
    //         cantidadNuevoSegmento += aho.countWords(v);
    //     }
    //     //contar de vuelta ese pedazo del texto
    //     res += cantidadNuevoSegmento;
    //     // cout(cantidadNuevoSegmento);
    //     cout << res << "\n";
    // }
    // // Output the counts
    // for(int i = 0; i < n; i++){
    //     cout << wordCount[i] << "\n";
    // }
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