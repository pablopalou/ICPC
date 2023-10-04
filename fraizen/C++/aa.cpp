#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
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
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
// #define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
// #define int ll
 
const int MAXN = 2e5 + 5;
const int MAXD = 30;  // ceil(log2(10^9))
 
// number of planets and queries
int n, q;
// parent matrix where [i][j] corresponds to i's (2^j)th parent
int parent[MAXN][MAXD];
 
int jump(int a, int d) {
	for (int i = 0; i < MAXD; i++)
		if (d & (1 << i)) a = parent[a][i];
	return a;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> q;
	for (int i = 1; i <= n; i++) { cin >> parent[i][0]; }
	// evaluate the parent matrix
	for (int d = 1; d < MAXD; d++)
		for (int i = 1; i <= n; i++) {
			parent[i][d] = parent[parent[i][d - 1]][d - 1];
		}
	// process queries
	while (q--) {
		int a, d;
		cin >> a >> d;
		cout << jump(a, d) << '\n';
	}
    return 0;
}