#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;
    
    vector<int> left(arr.begin(), arr.begin() + n / 2);
    vector<int> right(arr.begin() + n / 2, arr.end());
    
    long long inversions = countInversions(left) + countInversions(right);
    
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    
    for (int i = 0, j = 0, k = 0; k < n; ++k) {
        if (left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
            inversions += left.size() - i - 1;
        }
    }
    
    return inversions;
}

void solve() {
    int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        vector<int> sorted_a = a, sorted_b = b;
        sort(sorted_a.begin(), sorted_b.end());
        
        if (sorted_a != sorted_b) {
            cout << "NO" << endl;
            return;
        }
        
        long long inversions_a = countInversions(a);
        long long inversions_b = countInversions(b);
        
        if ((inversions_a % 2) == (inversions_b % 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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