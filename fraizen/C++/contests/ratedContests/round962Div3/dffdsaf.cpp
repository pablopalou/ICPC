#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll count_valid_triplets(ll n, ll x) {
    ll count = 0;

    for (ll a = 1; a <= min((ll)sqrt(n), x - 2); ++a) {
        ll max_bc = (n - a * a) / (2 * a) + 1;

        for (ll b = 1; b < max_bc && a + b < x; ++b) {
            ll max_c = min(x - a - b, (n - a * b) / (a + b));

            if (max_c > 0) {
                count += max_c;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;

        cout << count_valid_triplets(n, x) << endl;
    }

    return 0;
}