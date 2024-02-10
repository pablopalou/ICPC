#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

const int MAXN = 703;
int canEdge[MAXN][MAXN];
int dp[MAXN][MAXN][2];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool fillDP(int left, int right, int isRootRight) {
    if (left > right) return true; // Base case: invalid range
    if (dp[left][right][isRootRight] != -1) { // Check if already computed
        return dp[left][right][isRootRight];
    }

    if (left == right) { // Single node is always a BST
        return dp[left][right][isRootRight] = true;
    }

    bool possible = false;
    if (!isRootRight) { // If the root is considered to be on the left
        for (int root = left + 1; root <= right; ++root) {
            if (canEdge[left][root] && fillDP(left + 1, root, 1) && fillDP(root, right, 0)) {
                possible = true;
                break;
            }
        }
    } else { // If the root is considered to be on the right
        for (int root = left; root < right; ++root) {
            if (canEdge[right][root] && fillDP(left, root, 1) && fillDP(root, right - 1, 0)) {
                possible = true;
                break;
            }
        }
    }

    return dp[left][right][isRootRight] = possible;
}

void solve() {
    int n;cin >> n; int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fr(0,MAXN){
        rep(j,0,MAXN){
            rep(k,0,2){
                dp[i][j][k] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            canEdge[i][j] = canEdge[j][i] = gcd(a[i], a[j]) > 1;
        }
    }
    // Try to construct the BST from the whole array
    bool possible = fillDP(0, n - 1, 0) || fillDP(0, n - 1, 1);

    cout << (possible ? "Yes" : "No") << "\n";
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