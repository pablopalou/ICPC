#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define print(x) cout << x << '\n'

using namespace std;

int countRepeatedAtEnd(const vector<int> &v) {
    int count = 1;
    int lastIndex = v.size() - 1;
    int lastValue = v[lastIndex];
    
    for (int i = lastIndex - 1; i >= 0; i--) {
        if (v[i] == lastValue) {
            count++;
        } else {
            break;
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    // Read the elements of array a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Read the elements of array b
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Sort the arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int howManyAreLess = 0;
    int equalAtTheEnd = 0;
    int result = 0;

    // Calculate howManyAreLess and equalAtTheEnd
    for (int i = 0; i < m; i++) {
        if (i == m - 1 || b[i] != b[i + 1]) {
            howManyAreLess = count_if(a.begin(), a.end(), [b, i](int x) { return x < b[i]; });
        }
    }
    equalAtTheEnd = countRepeatedAtEnd(b);
    print(howManyAreLess);
    print(equalAtTheEnd);

    // Modify the first array and update the result
    while (equalAtTheEnd < howManyAreLess) {
        int minValue = min(a[n - 1], b[m - equalAtTheEnd - 1]);
        for (int i = 0; i < howManyAreLess; i++) {
            result += minValue - a[i];
            a[i] = minValue;
        }

        // Update howManyAreLess and equalAtTheEnd
        howManyAreLess = 0;
        equalAtTheEnd = 0;
        for (int i = 0; i < m; i++) {
            if (i == m - 1 || b[i] != b[i + 1]) {
                equalAtTheEnd = m - i;
                howManyAreLess = count_if(a.begin(), a.end(), [b, i](int x) { return x <= b[i]; });
                if (equalAtTheEnd >= howManyAreLess) {
                    break;
                }
            }
        }
    }

    // Make the remaining elements of the first array equal to the maximum of the second array
    for (int i = 0; i < howManyAreLess; i++) {
        result += b[m - 1] - a[i];
    }

    cout << result << endl;

    return 0;
}