#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#include <random>

ll norm(pair<ll,ll> p){
    return p.first * p.first + p.second * p.second;
}
pair<ll,ll> operator-(pair<ll,ll> a, pair<ll,ll> b){
    return make_pair(a.first - b.first, a.second - b.second);
}
pair<ll,ll> operator+(pair<ll,ll> a, pair<ll,ll> b){
    return make_pair(a.first + b.first, a.second + b.second);
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    vector<pair<pair<ll,ll>, ll>> a(n);
    fr(0,n){
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        a[i] = make_pair(p, i);
    }
    random_device rd;
    mt19937 g(rd());
    vector<int> r2(n);
    while (true){
        vector<int> res(n);
        shuffle(a.begin(), a.end(), g);
        pair<ll,ll> cur = {0,0};
        fr(0,n){
            if (norm(cur + a[i].first) < norm(cur - a[i].first)){
                cur = cur + a[i].first;
                res[a[i].second] = 1;
            } else {
                res[a[i].second] = -1;
                cur = cur - a[i].first;
            }
        }
        if (norm(cur) <= 1500000ll * 1500000ll){
            r2 = res;
            break;
        }
    }
    fr(0,n){
        cout << r2[i] << ' ';
    }
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