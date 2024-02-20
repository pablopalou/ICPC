#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

//no entiendo bien que guarda el binary lifting aca... (no anda tampoco)
// Copiar obligatoriamente 0
void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Compute cumulative sums for song durations
    vector<ll> cumSum(2*n+1, 0);
    for(int i = 1; i <= 2*n; i++) {
        cumSum[i] = cumSum[i-1] + a[(i-1)%n];
    }

    for(int i = 0; i < 2*n+1; i++){
        cout << cumSum[i] << " ";
    }
    cout << endl;

    // Initialize jump table
    int maxJump = log2(n) + 1;
    vector<vector<int>> next(n, vector<int>(maxJump, -1));

    // // Compute the base case for 'next' table
    // for(int i = 0; i < n; i++) {
    //     ll totalDuration = 0;
    //     for(int j = i; totalDuration < c; j = (j + 1) % n) {
    //         totalDuration += a[j % n];
    //         if(totalDuration >= c) {
    //             next[i][0] = (j + 1) % n;
    //             break;
    //         }
    //     }
    // }

    // // Fill the rest of the 'next' table using binary lifting
    // for(int k = 1; k < 20; k++) {
    //     for(int i = 0; i < n; i++) {
    //         if(next[i][k-1] != -1) {
    //             next[i][k] = next[next[i][k-1]][k-1];
    //         }
    //     }
    // }


    // return;
    // Fill the base case of the jump table
    for(int i = 0; i < n; i++) {
        ll duration = 0;
        for(int j = i; duration < c; j = (j + 1) % n) {
            duration = cumSum[j+1] - cumSum[i] + (j < i ? cumSum[n] : 0);
            next[i][0] = (j + 1) % n;
        }
    }

    // Fill the rest of the jump table using binary lifting
    for(int k = 1; k < maxJump; k++) {
        for(int i = 0; i < n; i++) {
            if(next[i][k-1] != -1) {
                next[i][k] = next[next[i][k-1]][k-1];
            }
        }
    }

    //     // Print the 'next' table
    cout << "Next table:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Song " << i << " -> ";
        for(int k = 0; k < maxJump+1 && next[i][k] != -1; k++) {
            cout << "2^" << k << ": " << next[i][k] << ", ";
        }
        cout << endl;
    }
    return;

    // // Compute results using the jump table
    // vector<int> res(n, 0);
    // for(int i = 0; i < n; i++) {
    //     int pos = i, count = 0;
    //     for(int k = maxJump-1; k >= 0; k--) {
    //         if(pos != -1 && next[pos][k] != -1 && next[pos][k] != i) {
    //             pos = next[pos][k];
    //             count += (1 << k);
    //         }
    //     }
    //     res[i] = count;
    // }

    // Print results
    // for(int i = 0; i < n; i++){
    //     cout << res[i] << " ";
    // }
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