#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

void solve() {
    ll n, m; cin >> n >> m;
    ll in[n], out[n];
    fr(0, n) {in[i]=0; out[i]=0;}
    fr(0,m) {
        ll u,v,w; cin>>u>>v>>w; u--; v--;
        out[u] += w; in[v] += w;
    }
    vector<ll> neg, pos;
    // salida - entrada
    vector<pair<ll,ll>> adj[n];
    fr(0, n) {
        if (in[i]-out[i]<0) {
            neg.push_back(i);
        } else if (in[i]-out[i]>0) {
            pos.push_back(i);
        }
    }
    if (neg.size() == 0) {cout<<0<<"\n"; return;}
    ll total = 0;
    fre(pos) {
        adj[e].push_back({neg[0], in[e]-out[e]});
        total += in[e]-out[e];
    }
    fr(1, neg.size()) {
        adj[neg[i-1]].push_back({neg[i], total+(in[neg[i-1]]-out[neg[i-1]])});
        total += (in[neg[i-1]]-out[neg[i-1]]);
    }
    int cant = 0;
    fr(0,n){
        if (adj[i].size()>0){
            cant++;
        }
    }
    cout(cant);
    fr(0, n) {
        if (adj[i].size()>0) {
            cout << i+1 << " " << adj[i][0].first+1 << " " << adj[i][0].second << "\n";
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}