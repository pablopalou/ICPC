#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<int> dp(n + 1, n);  // dp[i] initialized with a large number
    dp[n] = 0;  // No partitions needed beyond the last character

    // Prefix frequency map for character counts and their frequencies
    vector<vector<int>> count(n + 1, vector<int>(26, 0));

    // Build the prefix frequency array
    for (int i = 1; i <= n; ++i) {
        count[i] = count[i - 1];
        count[i][s[i - 1] - 'a']++;
    }

    // Check if a substring s[j:i] is balanced by comparing counts
    auto isBalanced = [&](int start, int end) {
        int minFreq = INT_MAX, maxFreq = 0;
        for (int k = 0; k < 26; ++k) {
            int freq = count[end + 1][k] - count[start][k];
            if (freq > 0) {
                minFreq = min(minFreq, freq);
                maxFreq = max(maxFreq, freq);
            }
        }
        return minFreq == maxFreq;
    };

    // Compute dp array from end to start
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (isBalanced(i, j)) {
                dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
    }

    // Final answer
    cout <<  dp[0] << endl;
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
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}