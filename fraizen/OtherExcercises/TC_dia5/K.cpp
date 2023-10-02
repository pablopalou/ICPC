#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long ll;

void solve(ll n, ll t, ll* a) {
    vector<ll> partial_sum(n + 1, 0);
    
    for (ll i = 1; i <= n; ++i) {
        partial_sum[i] = partial_sum[i - 1] + a[i - 1];
    }
    
    ll max_books = 0;
    for (ll left = 1, right = 1; left <= n && right <= n;) {
        ll reading_time = partial_sum[right] - partial_sum[left - 1];
        if (reading_time <= t) {
            max_books = max(max_books, right - left + 1);
            right++;
        } else {
            left++;
        }
    }

    cout << max_books << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    ll a[n]; 
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(n, t, a);
}

// #include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>
// #include <math.h>
// using namespace std;

// typedef long long ll;
// typedef vector<ll> vll;
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// typedef set<int> si;
// typedef multiset<int> msi;
// typedef unordered_set<int> usi;
// typedef map<int, string> mis;
// typedef unordered_map<int, string> umis;
// #define cout(x) cout << x << "\n";

// void solve(ll n, ll t, ll* a) {
//     for (ll i = n - 2; i >= 0; i--) {
//         a[i] += a[i + 1];
//     }
//     reverse(a, a + n);
//     // for (ll z = 0; z <= n-1; z++){
//     //     cout(a[z]);
//     // }
//     ll res = 0;
//     ll index = lower_bound(a, a + n, t) - a;
//     if (a[index] == t){
//         res = max(res, index + 1);
//         index = index+1;
//     } else {
//         res = max(res, index);
//     }

//     for (ll i = index; i < n; i++) {
//         ll index = lower_bound(a, a + n, a[i] - t) - a;
//         if (a[i] - t == a[index]){
//             res = max(res, i - index + 1);
//         } else {
//             res = max(res, i - index);
//         }
//     }

//     cout << res << "\n";
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll n, t;
//     cin >> n >> t;
//     ll a[n]; 
//     for (ll i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     solve(n, t, a);
// }