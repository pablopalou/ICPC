#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const ld EPS = 1e-9;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> y[i];
    }
    vector<ld> S(n+1, 0.0);
    for(int i = 1; i < n; ++i){
        ld trapezoid_area = ((y[i-1] + y[i]) / 2.0) * (x[i] - x[i-1]);
        S[i] = S[i-1] + trapezoid_area;
    }
    ld total_area = S[n-1];

    int idx = 1;
    ld S0 = 0.0;
    for(int k = 1; k < m; ++k) {
        ld A_req = k * total_area / m;
        while(idx < n && S[idx] < A_req - EPS){
            idx++;
        }
        if (idx == n) idx = n - 1;

        ld x0 = x[idx - 1], y0 = y[idx - 1];
        ld x1 = x[idx], y1 = y[idx];
        S0 = S[idx - 1];

        ld L = x1 - x0;
        ld dy = y1 - y0;
        ld target_area = A_req - S0;

        ld left = 0.0, right = L;
        while(right-left > 1e-6) {
            ld h = (left + right) / 2.0;
            ld area = y0 * h + (dy / (2.0 * L)) * h * h;
            if (area < target_area) {
                left = h;
            } else {
                right = h;
            }
        }
        ld h = (left + right) / 2.0;
        ld xi = x0 + h;
        if (k > 1) cout << ' ';
        cout << fixed << setprecision(12) << xi;
    }
    cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}