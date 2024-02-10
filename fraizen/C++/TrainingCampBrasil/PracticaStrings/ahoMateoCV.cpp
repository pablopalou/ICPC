#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a,overflowed=b;i<overflowed;i++)
#define mset(a,b) memset(a,b,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define SZ(a) int(a.size())
#define fst first
#define snd second
#define pb push_back
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
 
struct vertex {
    map<char,int>next,go;int p,link;char pch; vector<int> leaf;
    vertex(int p=-1,int pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init() {
    t.clear();t.pb(vertex());
}
void add_string(string s, int id) {
    int v=0;
    for(char c:s){
        if(!t[v].next.count(c))t[v].next[c]=t.size(),t.pb(vertex(v,c));
        v=t[v].next[c];
    }
    t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v) {
    if(t[v].link<0){
        if(!v||!t[v].p)t[v].link=0;
        else t[v].link=go(get_link(t[v].p),t[v].pch);
    }
    return t[v].link;
}
int go(int v, char c) {
    if(!t[v].go.count(c)) {
        if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
        else t[v].go[c]=v==0?0:go(get_link(v), c);
    }
    return t[v].go[c];
}
const int N = 1e5;
 
vector<int> g[N];
int dp[N];
 
void calc(int x) {
    dp[x] += SZ(t[x].leaf);
    for(auto v : g[x]) {
        dp[v] += dp[x];
        calc(v);
    }
}
 
int main(){
    FIO;
    int n, m; cin >> n >> m;
    aho_init();
    fore(i, 0, n) {
        string s; cin >> s;
        add_string(s, i);
    }
 
    fore(i, 1, SZ(t)) g[get_link(i)].pb(i);
 
    calc(0);
    string s; cin >> s;
    for(int i = 0; i<s.size(); i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
    // 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0
    // 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 
    ll ans = 0;
 
    vector<int> pos;
    vector<ll> tot;
 
    int w = 0;
    pos.pb(w);
    tot.pb(0);
    fore(i, 0, SZ(s)) {
        w = go(w, s[i]);
        pos.pb(w);
        tot.pb(dp[w]);
        ans += dp[w];
        // cout << ans << ' ' << s[i] << endl;
    }
    cout << ans << '\n';
 
    fore(i, 0, m) {
        int ps; char x; cin >> ps >> x;
        ps--;
        s[ps] = x;
 
        int w = pos[ps];
 
        while(1) {
            w = go(w, s[ps++]);
            if(w == pos[ps]) break;
            pos[ps] = w;
            ans -= tot[ps];
            tot[ps] = dp[w];
            ans += tot[ps];
            if(ps == SZ(s)) break;
        }
        cout << ans << '\n';
    }
 
    return 0;
}