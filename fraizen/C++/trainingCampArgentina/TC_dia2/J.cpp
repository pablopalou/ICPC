#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int f(int n) {
    int prod = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            prod *= digit;
        }
        n /= 10;
    }
    return prod;
}

int g(int n) {
    while (n >= 10) {
        n = f(n);
    }
    return n;
}

int count_g_values(int l, int r, int k) {
    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (g(i) == k) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;

    for (int t = 0; t < q; ++t) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << count_g_values(l, r, k) << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
 
// #define ll long long
// #define pb push_back
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define mod 1000000007
// #define inf (1LL<<60)
// #define all(x) (x).begin(),(x).end()
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll,pair<ll,ll>>
// #define goog(tno) cout << "Case #" << tno << ": " 
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define read(x) int x; cin >> x
// using namespace std;

// void solve(int n, const vector<int>& pies) {
//     vector<vector<int>> dp(n, vector<int>(n));

//     for (int len = 1; len <= n; ++len) {
//         for (int i = 0; i <= n - len; ++i) {
//             int j = i + len - 1;
            
//             if (len % 2 == 1) {
//                 if (i == 0) {
//                     dp[i][j] = dp[i + 1][j] + pies[i];
//                 } else {
//                     dp[i][j] = max(dp[i + 1][j] + pies[i], dp[i][j - 1] + pies[j]);
//                 }
//             } else {
//                 dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     int alice = dp[0][n - 1];
//     int bob = 0;
//     for (int i = 0; i < n; ++i) {
//         bob += pies[i];
//     }
//     bob -= alice;

//     cout << alice << " " << bob << endl;
// }

// // void solve(int k, vector<int>& a) {
// //     ll alice = 0;
// //     ll bob = 0;
// //     sort(a.begin(), a.end(), greater<int>());
// //     for (int i = 0; i < a.size(); i++) {
// //         cout << a[i] << " ";
// //     }
// //     for (int i = 0; i < a.size(); i++) {
// //         if (i % 2 == 0){
// //             bob = bob + a[i];
// //         } else {
// //             alice = alice + a[i];
// //         }
// //     }
// //     cout << alice << ' ' << bob << '\n';
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     solve(n, a);
// }
