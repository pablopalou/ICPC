#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long h, v;

    cin >> h >> v >> h >> v;

    vector<pair<int, int>> horizontais(h), verticais(v);

    for(auto &it : horizontais)
        cin >> it.first >> it.second;

    sort(horizontais.begin(), horizontais.end());

    for(auto &it : verticais)
        cin >> it.first >> it.second;

    sort(verticais.begin(), verticais.end());

    long long r = (h + 1) * (v + 1);

    statisticsTree th, tv;

    for(auto &it : horizontais)
    {
        r += th.order_of_key(it.second);

        th.insert(it.second);
    }

    for(auto &it : verticais)
    {
        r += tv.order_of_key(it.second);

        tv.insert(it.second);
    }

    cout << r << endl;
}

// #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;

// typedef long long ll;
// typedef vector<ll> vi;
// typedef pair<ll,ll> pii;
// typedef set<ll> si;
// typedef multiset<ll> msi;
// typedef unordered_set<ll> usi;
// typedef map<ll, string> mis;
// typedef unordered_map<ll, string> umis;
// typedef tree<
//     int,
//     null_type,
//     greater<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
// statisticsTree;

// #define pb push_back
// #define mp make_pair
// #define cout(x) cout << x << "\n";
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define mod 1000000007
// #define inf (1LL<<60)
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll,pair<ll,ll>>
// #define fre(s) for(auto e:s)
// #define MAXN 1000008

// void solve() {

// }

// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     ll x, y;
//     cin >> x >> y;
//     ll h, v;
//     cin >> h >> v;
//     ll res = 1;
//     res += h + v;
//     res += h*v;
//     vector<pii> horizontales;
//     vector<pii> verticales;
//     vector<ll> endsV;
//     vector<ll> endsH;

//     fr(0,h){
//         int start, end;
//         cin >> start >> end;
//         pii a = mp(start, end);
//         horizontales.pb(a);
//     }

//     sort(horizontales.begin(), horizontales.end());

//     statisticsTree th, tv;

//     for(auto &it : horizontais)
//     {
//         res += th.order_of_key(it.second);

//         th.insert(it.second);
//     }

//     for(auto &it : verticais)
//     {
//         res += tv.order_of_key(it.second);

//         tv.insert(it.second);
//     }
//     // endsV.pb(-horizontales[0].second);
//     // fr(1,h){
//     //     auto it = lower_bound(endsV.begin(), endsV.end(), -horizontales[i].second);
//     //     int pos = it - endsV.begin();
//     //     res += pos;
//     //     endsV.insert(it, -horizontales[i].second);
//     // }

//     // fr(0,v){
//     //     int start, end;
//     //     cin >> start >> end;
//     //     pii a = mp(start, end);
//     //     verticales.pb(a);
//     // }

//     // sort(verticales.begin(), verticales.end());
//     // endsH.pb(-verticales[0].second);
//     // fr(1,v){
//     //     auto it = lower_bound(endsH.begin(), endsH.end(), -verticales[i].second);
//     //     int pos = it - endsH.begin();
//     //     res += pos;
//     //     endsH.insert(it, -verticales[i].second);
//     // }

//     cout(res);
// }