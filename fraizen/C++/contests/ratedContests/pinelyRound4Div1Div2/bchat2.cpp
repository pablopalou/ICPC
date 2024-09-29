#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }

        vector<int> a(n);
        a[0] = b[0];
        bool possible = true;

        for (int i = 1; i < n - 1; ++i) {
            if ((b[i] & b[i-1]) != b[i-1]) {
                possible = false;
                break;
            }
            a[i] = b[i];
        }

        a[n - 1] = b[n - 2];

        if (possible) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}