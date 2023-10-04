STRINGS CSES

SUFFIX ARRAY (DISTINCT SUBSTRINGS LCP)

const int mxN = 1e5+5;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

void print() {
    fr(0, N)
        cout << i << " " << S.substr(sa[i], S.find('$', sa[i]) - sa[i]) << endl;
}

void printLCP() {
    fr(0, N) {
        cout << lcp[i] << " ";
    }
}

void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

signed main(){
    cin>>S; N = S.size();
    suffix();
    build_lcp();
    int sm = accumulate(lcp, lcp+N, 0LL);
    cout << N*(N+1)/2 - sm;
}

FINDING BORDERS

// Al parecer para encontrar los borders de un string tengo que fijarme el ultimo border y los border de ese borders. Ya que el border de un border tambien es un border del string original. 
// Primero hacemos la table pi (que es la que muestro en el codigo de abajo).
// longest proper prefix that is also a suffix for each substring.

vi preProcessPiTable(string s1) {
    int n = s1.length();
    int len = 0;
    vi pi(n);
    int i = 1;
    while (i < n){
        if (s1[i] == s1[len]){
            len++;
            pi[i] = len;
            i++;
        } else {
            if (len!=0){
                len = pi[len-1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }
    return pi;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    vector<int>pi = preProcessPiTable(a);
    vector<int>res;
    int j = pi[pi.size()-1];
    while(j > 0){
        res.push_back(j);
        j = pi[j-1];
    }
    reverse(res.begin(), res.end());
    for(auto it: res)
        cout << it << " ";
}

FINDING PERIODS

char s[MAXN];
int z[MAXN];

void z_function(char s[]){
    int n = strlen(s);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
} 

void solve(char s[]) {
    z_function(s);
    int n = strlen(s);
    for(int i = 1;i<n;i++){
        if(z[i]+i==n)cout<<i<<" ";
    }
    cout(n);
}

int main() {
    cin.getline(s, MAXN);
    solve(s);
}

LAZY PRINTING ICPC 2022 (HASHING + LCP)

#define p 256

vi precompute_hashes(const string& s){
    vi hashes(s.size() + 1, 0);
    ll hash = 0;
    for (ll i = 0; i < s.size(); i++) {
        hash = (hash * p + s[i]) % mod;
        hashes[i+1] = hash;
    }
    return hashes;
}

ll get_hash(const vi& hashes, ll l, ll r, const vi& potencias){ // Added potencias as a parameter
    return (((hashes[r] - ((hashes[l-1] * potencias[r-l+1]) % mod) % mod)+ mod) % mod);
}

ll lcp(const string& s, ll i, ll j, const vi& hashes, vi& potencias) {
    ll lo = 0, hi = min(s.size() - i, s.size() - j);
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (get_hash(hashes, i + 1, i + mid, potencias) == get_hash(hashes, j + 1, j + mid, potencias) ) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve(string text, ll d) {
    vi hashes = precompute_hashes(text);
    
    vi potencias(text.size()); // Moved potencias array to local scope and made its size dynamic
    potencias[0] = 1;
    for (ll i = 1; i < text.size(); i++) {
        potencias[i] = (potencias[i-1] * p) % mod;
    }

    ll res = 0; 
    ll i = 0;
    while (i < text.size()){
        ll max_len = 0;
        for (ll k = 1; k <= d; k++) {
            ll len = k + lcp(text, i, i+k, hashes, potencias);
            max_len = max(max_len, len);
        }
        i += max_len;
        res++;
    }
    cout << res << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string t;
    ll d;
    cin >> t >> d;
    
    solve(t, d);
}

REPEATING SUBSTRING LCP (SUFFIX ARRAY)

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>S; N = S.size() + 1;
    S.append("$");
    suffix();
    build_lcp();
    int maximo = lcp[0];
    int maximoI = 0;
    fr(1,N){
        if (lcp[i] > maximo){
            maximo = lcp[i];
            maximoI = i;
        }
    }
    if (maximo == 0){
        cout << "-1";
    } else {
        string res = S.substr(sa[maximoI],maximo);
        cout << res;
    }
}

STRING MATCHING (no usarlo pero por las dudas)

vi search(string pattern, string text) {
    ll d = 256;
    ll M = pattern.size();
    ll N = text.size();
    ll i, j;
    ll p = 0; // hash value for pattern
    ll t = 0; // hash value for txt
    ll h = 1;
    ll q = mod;
    vi res;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // cout << "Hashes con indices de inicio: " << i << '\n';
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            // for (j = 0; j < M; j++) {
            //     if (text[i + j] != pattern[j]) {
            //         break;
            //     }
            // }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            // if (j == M)
            res.pb(i);
                // cout << "Pattern found at index " << i
                //      << endl;
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - (text[i] * h)) + text[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q) % q;
        }
    }
    return res;
}


void solve(string text, string pattern) {
    vi indexes = search(pattern, text);
    cout(indexes.size());
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string text, pattern;
    cin >> text;
    cin >> pattern;

    solve(text, pattern);
}

EJERCICIOS DE CODEFORCES

MUHANDCUBEWALLS (1800 KMP)

int b[MAXLEN];

void kmppre(vi s1, vi s2){
    int i = 0, j = -1;
    b[0] = -1;
    while (i < s2.size()){
        while (j >= 0 && s2[i] != s2[j]){
            j = b[j];
        }
        i++,j++;
        b[i] = j;
    }
}

void kmp(vi s1, vi s2) {
    kmppre(s1,s2);
    int res = 0;
    int i=0, j=0;
    while (i < s1.size()){
        while(j >= 0 && s1[i] != s2[j]){
            j = b[j];
        }
        i++, j++;
        if (j == s2.size()){
            res += 1;
            j = b[j];
        }
    }
    cout(res);
}

vector<ll> toDiffArray(vector<ll> v) {
    vector<ll> res(v.size()-1);
    fr(1,v.size()){
        res[i-1] = v[i] - v[i-1];
    }
    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, w;
    cin >> n >> w;
    if (w == 1){
        cout(n);
        return 0;
    }

    vector<ll> v1(n);
    vector<ll> v2(w);
    
    fr(0,n){
        int a;
        cin >> a;
        v1[i] = a;        
    }

    fr(0,w){
        int a;
        cin >> a;
        v2[i] = a;        
    }

    vector<ll> aDiff = toDiffArray(v1);
    vector<ll> bDiff = toDiffArray(v2);

    kmp(aDiff, bDiff);
}

PASSWORD (Z FUNCTION, 1700)

int z[MAXN];

void z_function(string s){
    int n = s.size();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}  

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    z_function(s);
    // fr(0,n){
    //     cout << z[i];
    // }
    set<pair<int,int>> sufijos;
    set<pair<int,int>> medios;
    fr(0,n){
        if (z[i] + i == n){
            sufijos.insert(mp(z[i],i));
        }
        if (z[i] != 0){
            medios.insert(mp(z[i],i));
        }
    }
    if (medios.size() <= 1){
        cout("Just a legend");
        return 0;
    }
    pair<int,int> maximo;
    pair<int,int> maximo2;
    for (auto it = sufijos.rbegin(); it != sufijos.rend(); it++){
        maximo = *medios.rbegin();
        if (maximo.second == it->second){
            auto it2 = medios.rbegin();
            it2++;
            maximo = *it2;
        }
        if (maximo.first >= it->first){
            fr(it->second, it->second + it->first){
                cout << s[i];
            }
            cout(' ')
            return 0;
        }
    }
    cout("Just a legend");
}

TAVAS AND MALEKAS (Z FUNCTION, 1900) 

ll z[MAXN];

void z_function(string s){
    ll n = s.size();
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
    z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
    ++z[i];
    if (i + z[i] - 1 > r)
    l = i, r = i + z[i] - 1;
    }
}

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
    if (n % 2 == 1)
    res = ((res % mod) * (x % mod)) % mod;
    x = ((x % mod) * (x % mod)) % mod;
    n = n / 2;
    }
    return res % mod;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll largo = s.size();
    vi pos(m);
    fr(0,m){
        ll a;
        cin >> a;
        pos[i] = a;
    }
    ll ans = 1;
    z_function(s);
    set<ll> sufijos;
    fr(0,largo){
        if (z[i] + i == largo){
            sufijos.insert(largo-i);
        }
    }
    ll cur = 1;
    ll libres = 0;
    fr(0,m){
        if (i == 0){
            // cout("Libres al principio")
            libres = pos[i] - 1;
            // cout(libres);
            cur = pos[i];
        }
        if (pos[i] < cur){
            if (sufijos.find(cur-pos[i]) != sufijos.end()){
                cur = pos[i] + largo;
            } else {
                cout(0);
                return 0;
            }
        } else if (pos[i] == cur){
            cur += + largo;
        } else {
            libres += pos[i] - cur;
            // cout << "libres: " << libres << endl;
            cur = pos[i] + largo;
        }
    }
    cout << modular_expo(26,libres + n - cur + 1);
}

TRIE 

#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {}
    ~TrieNode() {
        for (auto &pair : children) {
            delete pair.second;
        }
    }
};

class Trie {
private:
    TrieNode *root;

    void insert(const string &s, TrieNode *node) {
        for (char c : s) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    bool find(const string &s, TrieNode *node) {
        for (char c : s) {
            auto it = node->children.find(c);
            if (it == node->children.end()) {
                return false;
            }
            node = it->second;
        }
        return true;
    }

public:
    Trie() : root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }

    void insert(const string &s) {
        insert(s, root);
    }

    bool find(const string &s) {
        return find(s, root);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Trie trie, trie_reversed;
    bool reversed = false;

    for (int i = 0; i < n; ++i) {
        int option;
        cin >> option;

        if (option == 1) {
            string str;
            cin >> str;
            if (reversed) {
                reverse(str.begin(), str.end());
            }
            trie.insert(str);
            string str_reversed = str;
            reverse(str_reversed.begin(), str_reversed.end());
            trie_reversed.insert(str_reversed);
        } else if (option == 2) {
            string str2;
            cin >> str2;

            Trie* target_trie = reversed ? &trie_reversed : &trie;

            cout << target_trie->find(str2) << '\n';

        } else if (option == 3) {
            reversed = !reversed;
        }
    }
}

OTRA VERSION DE TRIE CON ARRAY EN VEZ DE MAP (no use)
const int K = 26;
struct Vertex { 
int next[K]; 
bool output = false; 

Vertex() { 
fill(begin(next), end(next), -1); 
} 
}; 

vector<Vertex> trie(1);

void add_string(string const& s) { 
int v = 0;
for (char ch : s) { 
int c = ch - 'a'; 
if (trie[v].next[c] == -1) { 
trie[v].next[c] = trie.size();
trie.emplace_back();
} 
v = trie[v].next[c]; 
} 
trie[v].output = true; 
}


AHO CORASICK

// Aplicaciones del aho-corasick: 
// Find all strings from a given set in a text. 
// Esto si len es el largo del texto y ans es el largo de la respuesta, lo podemos hacer en O(len+ans).
// (igual tambien hay que tener guardado el exit link, que vendria a ser el vertice output mas cercano que es alcanzable usando los suffix links.)

const int K = 26; 
struct Vertex { 
int next[K]; 
bool output = false;
int p = -1; 
char pch; 
int link = -1; 
int go[K]; 

Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
fill(begin(next), end(next), -1); 
fill(begin(go), end(go), -1); 
} 
}; 

vector<Vertex> t(1); 

void add_string(string const& s) { 
int v = 0; 
for (char ch : s) { 
int c = ch - 'a'; 
if (t[v].next[c] == -1) { 
t[v].next[c] = t.size();
t.emplace_back(v, ch); 
} 
v = t[v].next[c]; 
} 
t[v].output = true; 
} 

int go(int v, char ch); 

int get_link(int v) { 
if (t[v].link == -1) { 
if (v == 0 || t[v].p == 0) 
t[v].link = 0; 
else 
t[v].link = go(get_link(t[v].p), t[v].pch); 
} 
return t[v].link; 
} 

int go(int v, char ch) { 
int c = ch - 'a'; 
if (t[v].go[c] == -1) { 
if (t[v].next[c] != -1) 
t[v].go[c] = t[v].next[c]; 
else 
t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch); 
} 
return t[v].go[c]; 
} 

