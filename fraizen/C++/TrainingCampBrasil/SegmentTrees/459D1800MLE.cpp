#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5; // Adjusted according to the problem constraint
int L[MAXN], R[MAXN]; // Arrays to store frequencies

//da memory limit exceeded en el test de 1 millon.
// lo hago bien en el 459D1800.cpp

struct SegmentTree {
    int n;
    vector<map<int, int>> tree;

    SegmentTree(int size) : n(size), tree(4 * n) {}

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node][arr[start]] = 1;
        } else {
            int mid = (start + end) / 2;
            build(node * 2, start, mid, arr);
            build(node * 2 + 1, mid + 1, end, arr);

            for (auto& p : tree[node * 2]) {
                tree[node][p.first] += p.second;
            }
            for (auto& p : tree[node * 2 + 1]) {
                tree[node][p.first] += p.second;
            }
        }
    }

    int query(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return 0;
        if (start >= l && end <= r) {
            int count = 0;
            for (const auto& p : tree[node]) {
                if (p.first < val) count += p.second;
            }
            return count;
        }

        int mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r, val) + query(node * 2 + 1, mid + 1, end, l, r, val);
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    // Precompute L and R
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        L[i] = ++freq[a[i]];
    }
    freq.clear();
    for (int i = n - 1; i >= 0; --i) {
        R[i] = ++freq[a[i]];
    }
 
    // Build Segment Tree with R
    SegmentTree st(n);
    st.build(1, 0, n - 1, vector<int>(R, R + n));
 
    // Query and Count
    ll answer = 0;
    for (int i = 0; i < n - 1; ++i) {
        answer += st.query(1, 0, n - 1, i + 1, n - 1, L[i]);
    }
 
    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
