#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
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
 
const int INF = 1e9;
 
vector<int> dp(4001, -1);
 
 
int solve(int n, int a, int b, int c) {
    if (n==0) {
        return 0;
    } else if (n < 0) {
        return -INF;
    } else {
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = 1 + max(max(solve(n-a, a, b, c), solve(n-b, a, b, c)), solve(n-c, a, b, c));
        return dp[n];
        // return 1 + max(max(solve(n-a, a, b, c), solve(n-b, a, b, c)), solve(n-c, a, b, c));
    }
}
 
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    int res;
    
    res = solve(n, a, b, c);
 
    cout(res);
}