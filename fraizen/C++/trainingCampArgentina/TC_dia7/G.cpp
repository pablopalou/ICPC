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
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>


void solve(vector<vi> prefs) {
    bool res = false;
    rep(j, 0, 5) {
        rep(i, 0, 5) {
            if (i != j) {
                int d1 = 0, d2 = 0, neg = 0;
                rep(k, 0, prefs.size()) {
                    if (prefs[k][j]) d1 += 1;
                    if (prefs[k][i]) d2 += 1;
                    if (!prefs[k][j] && !prefs[k][i]) neg += 1;
                }
                if (d1 >= prefs.size()/2 && d2 >= prefs.size()/2 && neg == 0) {
                    res = true;
                }
            }
        }
    }
    if (res) {
        cout("YES");
    } else {
        cout("NO");
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll cases;
    cin >> cases;
    int d;
    fr(0, cases) {
        ll students;
        cin >> students;
        vector<vi> prefs(students);
        rep(i, 0, students) {
            rep(j, 0, 5) {
                cin >> d;
                prefs[i].push_back(d);
            }
        }
        solve(prefs);
    }
}