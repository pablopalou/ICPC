#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

// era mucho mas sencillo pasar el nro a base 9...
vector<int> digits;
while(k > 0) {
    digits.push_back(k % 9);
    k /= 9;
}
reverse(digits.begin(), digits.end());

//este codigo NO funciona.
ll dp[14];
ll dp9[14];
ll dp9normal[14];
void precompute(){
    dp[0] = 0;
    dp[1] = 8;
    fr(2,14){
        dp[i] = dp[i-1] * 9;
    }
    fr(2,14){
        dp[i] += dp[i-1];
    }
    // fr(1,14){
    //     cout << dp[i] << ' ';
    // }
    dp9[1] = 9;
    fr(2,14){
        dp9[i] = dp9[i-1] * 9;
    }
    dp9normal[0] = 1;
    dp9normal[1] = 9;
    fr(2,14){
        dp9normal[i] = dp9normal[i-1] * 9;
    }
    fr(2,14){
        dp9[i] += dp9[i-1];
    }
}

void solve(ll n) {
    int i = 0;
    while (n > dp[i+1]){
        i+=1;
    }
    n-=dp[i];
    i+=1;
    // tengo que llegar al numero n con i digitos
    int j = 1;
    while (n > dp9[j]){
        j += 1;
    }
    int cant1 = i-j;
    int jTrue = j;
    ll res = 0;
    int digit;
    if (i==j){
        digit = ((n-1)/ dp9normal[j-1] )+ 1;
        res = res*10 + digit;
        n = n - (digit-1) * dp9normal[j-1];
        j-=1;
    }
    while (n>0){
        if (j==0){
            break;
        }
        if (j == 1){
            digit = n<=4 ? n-1 : n;
        } else {
            digit = (n-1)/ dp9normal[j-1];
        }
        res = res*10 + digit;
        n = n - digit * dp9normal[j-1];
        j-=1;
        if (j==0){
            break;
        }
    }
    int res2=0;
    while (cant1){
        res2 = res2*10 + 1;
        cant1--;
    }
    res = res2 * pow(10,jTrue) + res; 
    
    cout(res);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute();
    int cases;
    cin >> cases;
    while(cases--){
        ll n;
        cin >> n;
        if (n < 10){
            cout << ((n < 4) ? n : n+1) << "\n";
            continue;
        }
        solve(n);
    }
    
}