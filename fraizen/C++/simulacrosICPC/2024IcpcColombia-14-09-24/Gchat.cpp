#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const ld EPS = 1e-9;
const ld INF = 1e18;

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
    vector<ld> S(n+1, 0.0); // cumulative area
    for(int i = 1; i < n; ++i){
        ld trapezoid_area = ((y[i-1] + y[i]) / 2.0) * (x[i] - x[i-1]);
        S[i] = S[i-1] + trapezoid_area;
    }
    ld total_area = S[n-1];

    vector<ld> cuts;
    int idx = 1;
    ld S0 = 0.0;
    for(int k = 1; k < m; ++k) {
        ld A_req = k * total_area / m;

        // Advance idx until S[idx] >= A_req
        while(idx < n && S[idx] < A_req - EPS){
            idx++;
        }
        if (idx == n) idx = n - 1;

        ld x0 = x[idx - 1], y0 = y[idx - 1];
        ld x1 = x[idx], y1 = y[idx];
        S0 = S[idx - 1];

        ld L = x1 - x0;
        ld dy = y1 - y0;
        ld c = - (A_req - S0);

        ld h = 0.0;
        if (abs(dy) < EPS) {
            // Linear case
            h = - c / y0;
        } else {
            // Quadratic case
            ld a = dy / (2.0 * L);
            ld b = y0;
            ld D = b * b - 4.0 * a * c;
            if (D < 0.0) D = 0.0; // Handle potential floating-point errors
            ld sqrtD = sqrt(D);

            ld h1 = (-b + sqrtD) / (2.0 * a);
            ld h2 = (-b - sqrtD) / (2.0 * a);
            // Choose the root that lies between 0 and L
            if (h1 >= -EPS && h1 <= L + EPS) {
                h = h1;
            } else {
                h = h2;
            }
        }
        ld xi = x0 + h;
        cuts.push_back(xi);
    }
    std::ostringstream oss;
    oss.precision(7);
    oss << std::fixed;

    for(auto xi : cuts) {
        oss << xi << ' ';
    }
    cout << oss.str();
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        #ifdef JP
        freopen("G.in", "r", stdin);
	#endif

    solve();
        #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif
    return 0;
}