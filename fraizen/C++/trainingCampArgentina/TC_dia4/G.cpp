#include <bits/stdc++.h>
 
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
 
using namespace std;

// Custom comparator for descending order
struct custom_compare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

void solve(int n, set<int, custom_compare> numbers) {
    int res = 0;
    while (!numbers.empty()) {
        int num = *numbers.begin();
        numbers.erase(numbers.begin());

        if (num == 1) {
            break;
        }

        if (num % 2 == 0) {
            numbers.insert(num / 2);
            res +=1;
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases){
        set<int, custom_compare> numbers;
        int n, num;
        cin >> n;
        fr(0,n){
            cin >> num;
            if (num % 2 == 0){
                numbers.insert(num);
            }
        }
        solve(n,numbers);
        cases--;
    }
}
