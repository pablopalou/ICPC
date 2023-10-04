#include <bits/stdc++.h>

#include <iostream>
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

vector<vector<int>> precompute() {
    // Precompute g(x) for x in the range [1, 1e6+5]
    vector<vector<int>> g_values(10, vector<int>(1000005, 0));
    for (int i = 1; i <= 1000000; ++i) {
        g_values[g(i)][i] = 1;
    }

    // Calculate the prefix sum for each g(x) value
    for (int k = 1; k <= 9; ++k) {
        for (int i = 1; i <= 1000000; ++i) {
            g_values[k][i] += g_values[k][i - 1];
        }
    }
    return g_values;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g_values = precompute();

    int q;
    cin >> q;

    for (int t = 0; t < q; ++t) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << g_values[k][r] - g_values[k][l - 1] << endl;
    }

    return 0;
}