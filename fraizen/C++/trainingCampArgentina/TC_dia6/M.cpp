#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

using namespace std;

void solve(vi input) {
    vi left(input.size()), right(input.size()), ans(input.size()+1, 0);
    stack<int> s;
    
    fr(0, input.size()) {
        while(!s.empty() && input[s.top()] >= input[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top()+1;
        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }
    for(int i=input.size()-1; i>=0; i--) {
        while(!s.empty() && input[s.top()] >= input[i]) {
            s.pop();
        }
        right[i] = s.empty() ? input.size()-1 : s.top()-1;
        s.push(i);
    }

    fr(0, input.size()) {
        int len = right[i] - left[i] + 1;
        ans[len] = max(ans[len], input[i]);
    }

    for(int i=input.size()-1; i>=1; i--) {
        ans[i] = max(ans[i], ans[i+1]);
    }

    fr(1, input.size()+1) {
        cout << ans[i] << " ";
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vi input(n);
    for(int i=0; i<n; i++) {
        cin >> input[i];
    }

    solve(input);

    return 0;
}