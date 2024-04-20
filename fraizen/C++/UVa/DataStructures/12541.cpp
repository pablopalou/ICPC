#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

struct custom {
    bool operator()( tuple<string,ll,ll,ll> const &a, tuple<string,ll,ll,ll> const &b) const {
        if (get<3>(a) != get<3>(b)){
            return get<3>(a) < get<3>(b);
        }
        if (get<2>(a) != get<2>(b)){
            return get<2>(a) < get<2>(b);
        }
        if (get<1>(a) != get<1>(b)){
            return get<1>(a) < get<1>(b);
        }
        return false;
    }
};

// Copiar obligatoriamente 0
void solve() {
    ll n; cin >> n;
    vector<tuple<string, ll, ll, ll> > v;
    fr(0,n){
        string s; ll a, b, c; cin >> s >> a >> b >> c;
        v.push_back(make_tuple(s,a,b,c));
    }
    sort(v.begin(), v.end(), custom());
    cout << get<0>(v[n-1]) << "\n";
    cout << get<0>(v[0]) << "\n";
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