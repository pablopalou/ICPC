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

void solve(string word) {
    if (word.length() > 10) {
        cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
    }
    else {
        cout << word << endl;
    }
}

int main(){
    int casos;
    cin >> casos;

    while (casos) {
        string word;
        cin >> word;
        solve(word);
        casos--;
    }
}