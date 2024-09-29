#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a,b,c; cin >> a >> b >> c;
    if (a >= b + c or b>= a+c or c >= a+b){
        cout << "S\n";
    } else {
        cout << "N\n";
    }
}

int main() {
    std:iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    //cin >> cases;
    while(cases--) {
        solve();
    }

    return 0;
}