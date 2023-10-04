#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
 
using namespace std;

void solve(int n, int m) {
    int res = 0;
    if (n == m) {
        cout << res << '\n';
        return;
    }
    if (m % n != 0){
        cout << "-1" << '\n';
        return;
    }
    int div = m / n;
    while (div % 3 == 0){
        div = div/3;
        res +=1;
    }
    while (div % 2 == 0){
        div = div/2;
        res +=1;
    }
    if (div!=1){
        cout << "-1" << '\n';
        return;
    }
    cout << res << '\n';
}

#include <utility>

// Custom comparator function for multiset
struct custom_compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    multiset<pair<int, int>, custom_compare> points;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        points.insert(make_pair(a, b));
    }

    // Print the ordered pairs
    for (const auto& point : points) {
        cout << "a: " << point.first << ", b: " << point.second << endl;
    }
    solve(n,points);
}
