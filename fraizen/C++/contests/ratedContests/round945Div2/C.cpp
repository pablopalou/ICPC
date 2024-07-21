#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
//tp
int countLocalMaximums(const vector<int>& a) {
    int n = a.size();
    int localMaxCount = 0;

    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            ++localMaxCount;
        }
    }

    return localMaxCount;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> ans(n);
    vector<int> ans2(n);

    // Fill ans with high-low pattern
    int high = n;
    int low = 1;
    for (int i = 0; i < n; i += 2) {
        ans[i] = high--;
    }
    for (int i = 1; i < n; i += 2) {
        ans[i] = low++;
    }

    // Fill ans2 with low-high pattern
    high = n;
    low = 1;
    for (int i = 1; i < n; i += 2) {
        ans2[i] = high--;
    }
    for (int i = 0; i < n; i += 2) {
        ans2[i] = low++;
    }

    vector<int> a_with_ans(n);
    vector<int> a_with_ans2(n);

    for (int i = 0; i < n; ++i) {
        a_with_ans[i] = a[i] + ans[i];
        a_with_ans2[i] = a[i] + ans2[i];
    }

    int count1 = countLocalMaximums(a_with_ans);
    int count2 = countLocalMaximums(a_with_ans2);

    if (count1 >= count2) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ans2[i] << ' ';
        }
    }
    cout << '\n';
}


// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}