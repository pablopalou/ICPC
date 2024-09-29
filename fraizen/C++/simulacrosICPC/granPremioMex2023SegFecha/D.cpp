#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define forr(i,a,b) for(int i = (a);i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back

vector<int> kmppre(vector<int>& P){
    vector<int> b(sz(P) + 1);
    b[0] = -1;
    int j = -1;
    forn(i,sz(P)){
        while(j>=0&&P[i]!=P[j]) j = b[j];
        b[i+1] = ++j;
    }
    return b;
}

ll res = 0;
void kmp(vector<int>& T, vector<int>& P){
    int j = 0;
    vector<int> b = kmppre(P);
    forn(i,sz(T)) {
        while(j>=0 && T[i]!=P[j]) j = b[j];
        if(++j == sz(P)){
            j = b[j];
            res++;
        }
    }
}

void solve() {
    int n,m; cin >> m >> n; int a[m]; int b[n];
    fr(0,m){
        cin >> a[i];
    }
    fr(0,n){
        cin >> b[i];
    }
    if (m == 1){
        cout << n << '\n'; return;
    }
    vector<int> dif;
    fr(0,m-1){
        dif.pb(a[i+1]-a[i]);
    }
    vector<int> text;
    fr(0,n-1){
        text.pb(b[i+1]-b[i]);
    }
    kmp(text, dif);
    cout << res << '\n';
    // string dif;
    // fr(0,m-1){
    //     if (a[i+1]-a[i] >= 0){
    //         dif += "+" + to_string(a[i+1]-a[i]) + '$';  
    //     } else {
    //         dif += "-" + to_string(a[i]-a[i+1]) + '$';
    //     }
    // }
    // // cout << "DIF = " << dif << endl;
    // string text;
    // fr(0,n-1){
    //     if (b[i+1]-b[i] >= 0){
    //         text += "+" + to_string(b[i+1]-b[i]) + '$';  
    //     } else {
    //         text += "-" + to_string(b[i]-b[i+1]) + '$';
    //     }
    // }
    // cout << "TEXT = " << text << endl;

    // kmp(text, dif);
    // cout << res << '\n';

    // ll ans = 0;
    // Hash patron = Hash(dif);
    // int largo = dif.size();
    // Hash h = Hash(text);
    // fr(0,n-m){
    //     if (h.get(i, i + largo + 1) == ){

    //     }
    // }
    // cout << ans << '\n';
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
    #endif

    int cases=1;
    // cin >> cases;
    while(cases--) {
        solve();
    }
}
