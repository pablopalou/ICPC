#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define sz(c) ((int)c.size())
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)

inline int digitSum(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fr(0, n) cin >> a[i];

    priority_queue<int> pq(a.begin(), a.end());
    int iter = 0;

    while (!pq.empty() && iter < k) {
        int top = pq.top();
        pq.pop();
        
        int sec = pq.empty() ? 0 : pq.top();

        int na = digitSum(top);
        int opsecond = top - na;

        if (iter == k - 1) {
            cout(top - opsecond);
            return;
        }
        
        top = opsecond;
        iter++;
        
        if (opsecond >= sec) {
            int diff = (opsecond - sec) / 9;
            if (iter + diff >= k) {
                cout(9);
                return;
            }
            iter += diff;
            top -= diff * 9;
        }

        if (top > 0) {
            pq.push(top);
        }
    }

    cout(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases = 1;
    while (cases--) {
        solve();
    }

    return 0;
}