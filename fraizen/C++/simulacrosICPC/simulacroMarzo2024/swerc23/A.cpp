#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define mp make_pair
#define pb push_back

int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

// Copiar obligatoriamente 0
void solve() {
    int n; cin >> n;
    pair<char, int> cards[n];
    fr(0,n){
        string s; cin >> s;
        cards[i] = mp(s[0], stoi(s.substr(1, s.size()-1)));
    }

    vector<char> order(5);
    // order[0] = 'S';
    // order[1] = 'W';
    // order[2] = 'E';
    // order[3] = 'R';
    // order[4] = 'C';
    order[0] = 'E';
    order[1] = 'R';
    order[2] = 'S';
    order[3] = 'W';
    order[4] = 'C';

    ll best = 1000000;
    // int j = 1;
    do {
        // cout << "Orden #" << j << endl;
        // j++;
        // fr(0,n){
        //     cout << order[i] << ' ';
        // }
        // cout << endl;
        ll cur = 0;
        vector<int> v(n);
        fr(0,n){
            ll val = (find(order.begin(), order.end(), cards[i].first) - order.begin()) * n + (cards[i].second);
            v[i] = val;
            // cout << v[i] << ' ';
        }
        // cout << endl;
        //tengo que poner numeros a las cartas y ahi llamar a lis
        cur = lengthOfLIS(v);
        best = min(best, n - cur);
    } while (next_permutation(order.begin(), order.end()-1));

    cout << best << "\n";
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


