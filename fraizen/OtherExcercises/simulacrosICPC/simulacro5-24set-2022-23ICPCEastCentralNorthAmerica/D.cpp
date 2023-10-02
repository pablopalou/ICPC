#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

bool custom(const pair<int, char>&i, const pair<int, char>&j) {
    if (i.first > j.first){
        return true;
    }
    if (i.first == j.first && i.second < j.second){
        return true;
    }
    return false;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    vector<int> a(s.size());
    vector<int> c(s.size());
    vector<int> g(s.size());
    vector<int> t(s.size());
    fr(0,s.size()){
        if (i == 0){
            a[i] = 0;
            c[i] = 0;
            g[i] = 0;
            t[i] = 0;
        } else {
            a[i] = a[i-1];
            c[i] = c[i-1];
            g[i] = g[i-1];
            t[i] = t[i-1];
        }
        if (s[i] == 'A'){
            a[i]++;
        } else if (s[i] == 'C'){
            c[i]++;
        } else if (s[i] == 'G'){
            g[i]++;
        } else if (s[i] == 'T'){
            t[i]++;
        }
    }

    int m;
    cin >> m;
    fr(0,m){
        int l, r;
        cin >> l >> r;
        // cout << l << ", " << r << endl;
        int cantA = l > 1 ? a[r-1] - a[l-2] : a[r-1];
        int cantC = l > 1 ? c[r-1] - c[l-2] : c[r-1];
        int cantG = l > 1 ? g[r-1] - g[l-2] : g[r-1];
        int cantT = l > 1 ? t[r-1] - t[l-2] : t[r-1];
        pair<int, char> p[4];
        p[0] = mp(cantA, 'A');
        p[1] = mp(cantC, 'D');//c
        p[2] = mp(cantG, 'C');//g
        p[3] = mp(cantT, 'B');//t
        sort(p, p+4, custom);
        fre(p){
            if ( e.second == 'A'){
                cout << e.second;
            } else if (e.second == 'B'){
                cout << "T";
            } else if (e.second == 'C'){
                cout << 'G';
            } else {
                cout << 'C';
            }
            // cout << e.first << ' ' << e.second << endl;
        }
        cout(' ');
    }
}